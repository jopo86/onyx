#include "UiRenderable.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::UiRenderable::UiRenderable() 
{
	model = Mat4::Identity();
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Vec3 rgb)
{
	this->mesh = mesh;
	shader = ShaderPresets::UI_Color(Vec4(rgb, 1.0f));
	model = Mat4::Identity();
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Math::Vec4 rgba)
{
	this->mesh = mesh;
	shader = ShaderPresets::UI_Color(rgba);
	model = Mat4::Identity();
	hidden = false;
}

Onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture) 
{
	this->mesh = mesh;
	this->texture = texture;
	shader = ShaderPresets::UI_Texture();
	model = Mat4::Identity();
	hidden = false;
}

void Onyx::UiRenderable::render()
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.uniform("u_model", model);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndexArray().getSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

void Onyx::UiRenderable::render(Mat4 ortho)
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.uniform("u_model", model);
	shader.uniform("u_projection", ortho);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndexArray().getSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
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

void Onyx::UiRenderable::translate(Vec2 xy)
{
	if (xy.isZero()) return;
	model.translate(Vec3(xy, 0.0f));
}

void Onyx::UiRenderable::rotate(float degrees)
{
	if (degrees == 0.0f) return;
	model.rotate(degrees, Vec3(0.0f, 0.0f, 1.0f));
}

void Onyx::UiRenderable::scale(float scalar)
{
	if (scalar == 1.0f) return;
	model.scale(Vec3(scalar, scalar, 1.0f));
}

void Onyx::UiRenderable::scale(Vec2 xyScalar)
{
	if (xyScalar.getX() == 1.0f && xyScalar.getY() == 1.0f) return;
	model.scale(Vec3(xyScalar, 1.0f));
}

void Onyx::UiRenderable::resetTransform()
{
	model = Mat4::Identity();
}

Onyx::Mesh Onyx::UiRenderable::getMesh()
{
	return mesh;
}

Onyx::Shader Onyx::UiRenderable::getShader()
{
	return shader;
}

Onyx::Texture Onyx::UiRenderable::getTexture()
{
	return texture;
}

bool Onyx::UiRenderable::isHidden()
{
	return hidden;
}

void Onyx::UiRenderable::dispose()
{
	mesh.dispose();
	shader.dispose();
	texture.dispose();
}
