#include "Renderable.h"

using Onyx::Math::Mat4;
using Onyx::Math::Vec3;

Onyx::Renderable::Renderable() 
{
	model = Mat4(1.0f);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh)
{
	this->mesh = mesh;
	model = Mat4(1.0f);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader)
{
	this->mesh = mesh;
	this->shader = shader;
	model = Mat4(1.0f);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)
{
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	model = Mat4(1.0f);
	hidden = false;
}

void Onyx::Renderable::render()
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndexArray().getSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

void Onyx::Renderable::render(Mat4 view, Mat4 proj)
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	shader.setMat4("u_view", view);
	shader.setMat4("u_projection", proj);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndexArray().getSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);
}

void Onyx::Renderable::hide()
{
	hidden = true;
}

void Onyx::Renderable::show()
{
	hidden = false;
}

void Onyx::Renderable::toggleVisibility()
{
	hidden = !hidden;
}

void Onyx::Renderable::translate(Vec3 xyz)
{
	if (xyz.isZero()) return;
	model.translate(xyz);
}

void Onyx::Renderable::rotate(float degrees, Vec3 axes)
{
	if (degrees == 0 || axes.isZero()) return;
	model.rotate(degrees, axes);
}

void Onyx::Renderable::scale(float scalar)
{
	if (scalar == 1.0f) return;
	model.scale(Vec3(scalar, scalar, scalar));
}

void Onyx::Renderable::scale(Vec3 xyzScalar)
{
	if (xyzScalar.getX() == 1 && xyzScalar.getY() == 1 && xyzScalar.getZ() == 1) return;
	model.scale(xyzScalar);
}

void Onyx::Renderable::resetTransform()
{
	model = Mat4(1.0f);
}

Onyx::Mesh Onyx::Renderable::getMesh()
{
	return mesh;
}

Onyx::Shader Onyx::Renderable::getShader()
{
	return shader;
}

Onyx::Texture Onyx::Renderable::getTexture()
{
	return texture;
}

bool Onyx::Renderable::isHidden()
{
	return hidden;
}

void Onyx::Renderable::dispose()
{
	texture.dispose();
	shader.dispose();
	mesh.dispose();
}
