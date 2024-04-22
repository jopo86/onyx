#include "UiRenderable.h"

#include <glad/glad.h>

#include "Shader.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::UiRenderable::UiRenderable() 
{
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Vec3 rgb)
{
	this->mesh = mesh;
	shader = Shader::UI_Color(Vec4(rgb, 1.0f));
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Math::Vec4 rgba)
{
	this->mesh = mesh;
	shader = Shader::UI_Color(rgba);
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture) 
{
	this->mesh = mesh;
	this->texture = texture;
	shader = Shader::UI_Texture();
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
	hidden = false;
}

void Onyx::UiRenderable::render()
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::UiRenderable::render(Mat4 ortho)
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	shader.setMat4("u_projection", ortho);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::UiRenderable::hide()
{
	hidden = true;
}

void Onyx::UiRenderable::show()
{
	hidden = false;
}

void Onyx::UiRenderable::toggleVisibility()
{
	hidden = !hidden;
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
	return mesh;
}

Onyx::Shader Onyx::UiRenderable::getShader() const
{
	return shader;
}

Onyx::Texture Onyx::UiRenderable::getTexture() const
{
	return texture;
}

bool Onyx::UiRenderable::isHidden() const
{
	return hidden;
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
	if (translation.isZero()) return;

	Vec2 rotated = translation;

	if (m_rotation != 0.0f)
	{
		float sin = sinf(Math::Radians(m_rotation));
		float cos = cosf(Math::Radians(m_rotation));
		float x = rotated.getX();
		float y = rotated.getY();
		rotated.setX(x * cos - y * sin);
		rotated.setY(x * sin + y * cos);
	}

	translate(rotated);
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
	model = Mat4::Identity();
}

void Onyx::UiRenderable::dispose()
{
	mesh.dispose();
	shader.dispose();
	texture.dispose();
}

void Onyx::UiRenderable::updateModel()
{
    model = Mat4::Identity();
    model.translate(Vec3(m_position, 0.0f));
    model.rotate(m_rotation, Vec3(0.0f, 0.0f, 1.0f));
    model.scale(Vec3(m_scale, 1.0f));
}
