#include "UiRenderable.h"

#include <glad/glad.h>

#include "Shader.h"

void onyx_err(const Onyx::Error&);

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::UiRenderable::UiRenderable() 
{
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	m_hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Vec3 rgb)
{
	m_mesh = mesh;
	m_shader = Shader::P_UI_Color(Vec4(rgb, 1.0f));
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	m_hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Math::Vec4 rgba)
{
	m_mesh = mesh;
	m_shader = Shader::P_UI_Color(rgba);
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	m_hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture, bool* result) 
{
	m_mesh = mesh;
	m_texture = texture;
	m_shader = Shader::PT_UI();
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	m_hidden = false;

	if (!VertexBuffer::HasTextureCoords(mesh.getVertexFormat()))
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture)",
				.message = "The mesh contains a vertex buffer that is not of a format with texture coordinates. It will most likely have problems rendering.",
				.howToFix = "Use a vertex format with texture coords: PT, PCT, PNT, or PNCT"
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	if (result != nullptr) *result = true;
}

void Onyx::UiRenderable::render()
{
	if (m_hidden) return;
	m_shader.use();
	m_texture.bind();
	m_shader.setMat4("u_model", m_model);
	glBindVertexArray(m_mesh.getVAO());
	glDrawElements(GL_TRIANGLES, m_mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::UiRenderable::render(Mat4 ortho)
{
	if (m_hidden) return;
	m_shader.use();
	m_texture.bind();
	m_shader.setMat4("u_model", m_model);
	m_shader.setMat4("u_projection", ortho);
	glBindVertexArray(m_mesh.getVAO());
	glDrawElements(GL_TRIANGLES, m_mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::UiRenderable::hide()
{
	m_hidden = true;
}

void Onyx::UiRenderable::show()
{
	m_hidden = false;
}

void Onyx::UiRenderable::toggleVisibility()
{
	m_hidden = !m_hidden;
}

const Onyx::Math::Vec2& Onyx::UiRenderable::getPosition() const
{
	return m_position;
}

float Onyx::UiRenderable::getRotation() const
{
	return m_rotation;
}

const Onyx::Math::Vec2& Onyx::UiRenderable::getScale() const
{
	return m_scale;
}

Onyx::Mesh Onyx::UiRenderable::getMesh() const
{
	return m_mesh;
}

Onyx::Shader Onyx::UiRenderable::getShader() const
{
	return m_shader;
}

Onyx::Texture Onyx::UiRenderable::getTexture() const
{
	return m_texture;
}

bool Onyx::UiRenderable::isHidden() const
{
	return m_hidden;
}

void Onyx::UiRenderable::setPosition(const Vec2& position)
{
	m_position = position;
	updateModel();
}

void Onyx::UiRenderable::setRotation(float rotation)
{
	m_rotation = rotation;
	updateModel();
}

void Onyx::UiRenderable::setScale(const Vec2& scale)
{
	m_scale = scale;
	updateModel();
}

void Onyx::UiRenderable::translate(const Vec2& translation)
{
	m_position += translation;
	updateModel();
}

void Onyx::UiRenderable::translateLocal(const Vec2& translation)
{
	translate(Math::Rotate(translation, m_rotation));
}

void Onyx::UiRenderable::rotate(float rotation)
{
	m_rotation += rotation;
	updateModel();
}

void Onyx::UiRenderable::scale(const Vec2& scalars)
{
	m_scale.setX(m_scale.getX() * scalars.getX());
	m_scale.setY(m_scale.getY() * scalars.getY());
	updateModel();
}

void Onyx::UiRenderable::scale(float scalar)
{
	m_scale.setX(m_scale.getX() * scalar);
	m_scale.setY(m_scale.getY() * scalar);
	updateModel();
}

void Onyx::UiRenderable::resetTransform()
{
	m_model = Mat4::Identity();
}

void Onyx::UiRenderable::dispose()
{
	m_mesh.dispose();
	m_shader.dispose();
	m_texture.dispose();
}

void Onyx::UiRenderable::updateModel()
{
	m_model = Mat4::Identity();
	m_model.translate(Vec3(m_position, 0.0f));
	m_model.rotate(m_rotation, Vec3(0.0f, 0.0f, 1.0f));
	m_model.scale(Vec3(m_scale, 1.0f));
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredTriangle(float side, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Triangle(side), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredTriangle(float side, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Triangle(side), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredTriangle(float base, float height, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Triangle(base, height), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredTriangle(float base, float height, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Triangle(base, height), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedTriangle(float side, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Triangle(side, true), IndexBuffer::Triangle()), texture);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedTriangle(float base, float height, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Triangle(base, height, true), IndexBuffer::Triangle()), texture);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredSquare(float side, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Square(side), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredSquare(float side, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Square(side), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedSquare(float side, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Square(side, true), IndexBuffer::Square()), texture);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredQuad(float width, float height, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Quad(width, height), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredQuad(float width, float height, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Quad(width, height), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedQuad(float width, float height, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Quad(width, height, true), IndexBuffer::Quad()), texture);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredCircle(float radius, int nSegments, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Circle(radius, nSegments), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredCircle(float radius, int nSegments, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Circle(radius, nSegments), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredCircle(float radius, float angleStep, Math::Vec3 rgb)
{
	return UiRenderable(Mesh::Circle(radius, angleStep), rgb);
}

Onyx::UiRenderable Onyx::UiRenderable::ColoredCircle(float radius, float angleStep, Math::Vec4 rgba)
{
	return UiRenderable(Mesh::Circle(radius, angleStep), rgba);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedCircle(float radius, int nSegments, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Circle(radius, nSegments, true), IndexBuffer::Circle(nSegments)), texture);
}

Onyx::UiRenderable Onyx::UiRenderable::TexturedCircle(float radius, float angleStep, Texture texture)
{
	return UiRenderable(Mesh(VertexBuffer::Circle(radius, angleStep, true), IndexBuffer::Circle(angleStep)), texture);
}
