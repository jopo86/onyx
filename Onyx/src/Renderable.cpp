#include "Renderable.h"

#include <glad/glad.h>

void onyx_warn(const Onyx::Warning&);

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, 
Onyx::Math::Mat4;

Onyx::Renderable::Renderable() 
{
	m_model = Mat4(1.0f);
	m_inverseModel = Math::Inverse(m_model);
	m_scale = Vec3(1.0f);
	m_hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh)
{
	m_mesh = mesh;
	m_shader = Shader::P_Color(Vec4::White());
	m_model = Mat4(1.0f);
	m_inverseModel = Math::Inverse(m_model);
	m_scale = Vec3(1.0f);
	m_hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader)
{
	m_mesh = mesh;
	m_shader = shader;
	m_model = Mat4(1.0f);
	m_inverseModel = Math::Inverse(m_model);
	m_scale = Vec3(1.0f);
	m_hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)
{
	if (!VertexBuffer::HasTextureCoords(mesh.getVertexFormat()))
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)",
				.message = "The mesh contains a vertex buffer that is not of a format with texture coordinates. It will most likely have problems rendering.",
				.howToFix = "Use a vertex format with texture coords: PT, PCT, PNT, or PNCT",
				.severity = Warning::Severity::High
			}
		);
	}
	m_mesh = mesh;
	m_shader = shader;
	m_texture = texture;
	m_model = Mat4(1.0f);
	m_inverseModel = Math::Inverse(m_model);
	m_scale = Vec3(1.0f);
	m_hidden = false;
}

void Onyx::Renderable::render()
{
	if (m_hidden) return;
	m_shader.use();
	m_texture.bind();
	m_shader.setMat4("u_model", m_model);
	m_shader.setMat4("u_inverseModel", m_inverseModel);
	glBindVertexArray(m_mesh.getVAO());
	glDrawElements(GL_TRIANGLES, m_mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderable::render(const Mat4& view, const Mat4& proj, const Vec3& camPos)
{
	if (m_hidden) return;
	m_shader.use();
	m_texture.bind();
	m_shader.setMat4("u_model", m_model);
	m_shader.setMat4("u_inverseModel", m_inverseModel);
	m_shader.setMat4("u_view", view);
	m_shader.setMat4("u_projection", proj);
	m_shader.setVec3("u_camPos", camPos);
	glBindVertexArray(m_mesh.getVAO());
	glDrawElements(GL_TRIANGLES, m_mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderable::hide()
{
	m_hidden = true;
}

void Onyx::Renderable::show()
{
	m_hidden = false;
}

void Onyx::Renderable::toggleVisibility()
{
	m_hidden = !m_hidden;
}

const Vec3& Onyx::Renderable::getPosition() const
{
	return m_position;
}

const Vec3& Onyx::Renderable::getRotation() const
{
	return m_rotation;
}

const Vec3& Onyx::Renderable::getScale() const
{
	return m_scale;
}

Onyx::Mesh* Onyx::Renderable::getMesh()
{
	return &m_mesh;
}

Onyx::Shader* Onyx::Renderable::getShader()
{
	return &m_shader;
}

Onyx::Texture* Onyx::Renderable::getTexture()
{
	return &m_texture;
}

const Mat4& Onyx::Renderable::getModel() const
{
	return m_model;
}

bool Onyx::Renderable::isHidden() const
{
	return m_hidden;
}

void Onyx::Renderable::setPosition(const Vec3& position)
{
	m_position = position;
	updateModel();
}

void Onyx::Renderable::setRotation(const Vec3& rotations)
{
	m_rotation = rotations;
	updateModel();
}

void Onyx::Renderable::setScale(const Vec3& scales)
{
	m_scale = scales;
	updateModel();
}

void Onyx::Renderable::translate(const Vec3& translation)
{
	m_position += translation;
	updateModel();
}

void Onyx::Renderable::translateLocal(const Vec3& translation)
{
	translate(Math::Rotate(translation, m_rotation));
}

void Onyx::Renderable::rotate(const Vec3& rotations)
{
	m_rotation += rotations;
	updateModel();
}

void Onyx::Renderable::rotate(const Vec3& rotations, const Vec3& origin)
{
	Vec3 diff = m_position - origin;
	translate(-diff);
	rotate(rotations);
	diff = Math::Rotate(diff, rotations);
	translate(diff);
}

void Onyx::Renderable::scale(const Vec3& scalars)
{
	m_scale.setX(m_scale.getX() * scalars.getX());
	m_scale.setY(m_scale.getY() * scalars.getY());
	m_scale.setZ(m_scale.getZ() * scalars.getZ());
	updateModel();
}

void Onyx::Renderable::scale(float scalar)
{
	m_scale.setX(m_scale.getX() * scalar);
	m_scale.setY(m_scale.getY() * scalar);
	m_scale.setZ(m_scale.getZ() * scalar);
	updateModel();
}

void Onyx::Renderable::resetTransform()
{
	m_position = Vec3(0.0f);
	m_rotation = Vec3(0.0f);
	m_scale = Vec3(1.0f);
	updateModel();
}

void Onyx::Renderable::dispose()
{
	if (m_disposed) return;
	m_texture.dispose();
	m_shader.dispose();
	m_mesh.dispose();
	m_disposed = true;
}

void Onyx::Renderable::updateModel()
{
	m_model = Mat4::Identity();
	m_model.translate(m_position);
	m_model.rotate(m_rotation.getX(), Vec3(1.0f, 0.0f, 0.0f));
	m_model.rotate(m_rotation.getY(), Vec3(0.0f, 1.0f, 0.0f));
	m_model.rotate(m_rotation.getZ(), Vec3(0.0f, 0.0f, 1.0f));
	m_model.scale(m_scale);
	m_inverseModel = Math::Inverse(m_model);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::Triangle(side, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::Triangle(side, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float base, float height, Vec3 rgb)
{
	return Renderable(
		Mesh::Triangle(base, height, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float base, float height, Vec4 rgba)
{
	return Renderable(
		Mesh::Triangle(base, height, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(Vec2 a, Vec2 b, Vec2 c, Vec3 rgb)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(Vec2 a, Vec2 b, Vec2 c, Vec4 rgba)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(float side)
{
	return Renderable(
		Mesh::Triangle(side, true),
		Shader::PN_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(float base, float height)
{
	return Renderable(
		Mesh::Triangle(base, height, true),
		Shader::PN_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(Vec2 a, Vec2 b, Vec2 c)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(float side, Texture texture)
{
	return Renderable(
		Mesh::Triangle(side, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(float base, float height, Texture texture)
{
	return Renderable(
		Mesh::Triangle(base, height, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(Vec2 a, Vec2 b, Vec2 c, Texture texture)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::ColoredSquare(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::Square(side, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredSquare(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::Square(side, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(float width, float height, Vec3 rgb)
{
	return Renderable(
		Mesh::Quad(width, height, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(float width, float height, Vec4 rgba)
{
	return Renderable(
		Mesh::Quad(width, height, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec3 rgb)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec4 rgba)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::VertexColoredSquare(float side)
{
	return VertexColoredQuad(side, side);
}

Onyx::Renderable Onyx::Renderable::VertexColoredQuad(float width, float height)
{
	return Renderable(
		Mesh::Quad(width, height, true),
		Shader::PN_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::TexturedSquare(float side, Texture texture)
{
	return Renderable(
		Mesh::Square(side, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedQuad(float width, float height, Texture texture)
{
	return Renderable(
		Mesh::Quad(width, height, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Texture texture)
{
	return Renderable();
}

Onyx::Renderable Onyx::Renderable::ColoredCircle(float radius, int nSegments, Math::Vec3 rgb)
{
	return Renderable(
		Mesh::Circle(radius, nSegments, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCircle(float radius, int nSegments, Math::Vec4 rgba)
{
	return Renderable(
		Mesh::Circle(radius, nSegments, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCircle(float radius, float angleStep, Math::Vec3 rgb)
{
	return Renderable(
		Mesh::Circle(radius, angleStep, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCircle(float radius, float angleStep, Math::Vec4 rgba)
{
	return Renderable(
		Mesh::Circle(radius, angleStep, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredCircle(float radius, int nSegments)
{
	return Renderable(
		Mesh::Circle(radius, nSegments, true),
		Shader::PN_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredCircle(float radius, float angleStep)
{
	return Renderable(
		Mesh::Circle(radius, angleStep, true),
		Shader::PN_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::TexturedCircle(float radius, int nSegments, Texture texture)
{
	return Renderable(
		Mesh::Circle(radius, nSegments, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedCircle(float radius, float angleStep, Texture texture)
{
	return Renderable(
		Mesh::Circle(radius, angleStep, true, true),
		Shader::PNT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCube(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::Cube(side, true),
		Shader::PN_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCube(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::Cube(side, true),
		Shader::PN_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::TexturedCube(float side, Texture texture)
{
	return Renderable(
		Mesh::Cube(side, true, true),
		Shader::PNT(),
		texture
	);
}
