#include "Renderable.h"

#include <glad/glad.h>

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, 
Onyx::Math::Mat4;

Onyx::Renderable::Renderable() 
{
	model = Mat4(1.0f);
	inverseModel = Math::Inverse(model);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh)
{
	this->mesh = mesh;
	model = Mat4(1.0f);
	inverseModel = Math::Inverse(model);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader)
{
	this->mesh = mesh;
	this->shader = shader;
	model = Mat4(1.0f);
	inverseModel = Math::Inverse(model);
	hidden = false;
}

Onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)
{
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	model = Mat4(1.0f);
	inverseModel = Math::Inverse(model);
	hidden = false;
}

void Onyx::Renderable::render()
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	shader.setMat4("u_inverseModel", inverseModel);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Renderable::render(const Mat4& view, const Mat4& proj)
{
	if (hidden) return;
	shader.use();
	texture.bind();
	shader.setMat4("u_model", model);
	shader.setMat4("u_inverseModel", inverseModel);
	shader.setMat4("u_view", view);
	shader.setMat4("u_projection", proj);
	glBindVertexArray(mesh.getVAO());
	glDrawElements(GL_TRIANGLES, mesh.getIndicesSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
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

void Onyx::Renderable::translate(const Vec3& xyz)
{
	if (xyz.isZero()) return;
	model.translate(xyz);
	inverseModel = Math::Inverse(model);
}

void Onyx::Renderable::rotate(float degrees, const Vec3& mask)
{
	if (degrees == 0.0f || mask.isZero()) return;
	model.rotate(degrees, mask);
	inverseModel = Math::Inverse(model);
}

void Onyx::Renderable::scale(float scalar)
{
	if (scalar == 1.0f) return;
	model.scale(Vec3(scalar, scalar, scalar));
	inverseModel = Math::Inverse(model);
}

void Onyx::Renderable::scale(const Vec3& xyzScalar)
{
	if (xyzScalar.getX() == 1.0f && xyzScalar.getY() == 1.0f && xyzScalar.getZ() == 1.0f) return;
	model.scale(xyzScalar);
	inverseModel = Math::Inverse(model);
}

void Onyx::Renderable::resetTransform()
{
	model = Mat4(1.0f);
}

Onyx::Mesh* Onyx::Renderable::getMesh()
{
	return &mesh;
}

Onyx::Shader* Onyx::Renderable::getShader()
{
	return &shader;
}

Onyx::Texture* Onyx::Renderable::getTexture()
{
	return &texture;
}

const Mat4& Onyx::Renderable::getModel() const
{
	return model;
}

bool Onyx::Renderable::isHidden() const
{
	return hidden;
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float side, Vec3 rgb)
{
	return ColoredTriangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), Vec4(rgb, 1.0f));
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float side, Vec4 rgba)
{
	return ColoredTriangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), rgba);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float base, float height, Vec3 rgb)
{
	return ColoredTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f),
		rgb
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(float base, float height, Vec4 rgba)
{
	return ColoredTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f),
		rgba
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(Vec2 a, Vec2 b, Vec2 c, Vec3 rgb)
{
	return Renderable(
		Mesh::Triangle(a, b, c),
		Shader::V_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredTriangle(Vec2 a, Vec2 b, Vec2 c, Vec4 rgba)
{
	return Renderable(
		Mesh::Triangle(a, b, c),
		Shader::V_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(float side)
{
	return VertexColoredTriangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)));
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(float base, float height)
{
	return VertexColoredTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f)
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredTriangle(Vec2 a, Vec2 b, Vec2 c)
{
	return Renderable(
		Mesh::Triangle(a, b, c),
		Shader::V_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(float side, Texture texture)
{
	return TexturedTriangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), texture);
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(float base, float height, Texture texture)
{
	return TexturedTriangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedTriangle(Vec2 a, Vec2 b, Vec2 c, Texture texture)
{
	float* vertices = new float[15] {
		a.getX(), a.getY(), 0.0f, 0.0f, 0.0f,
			b.getX(), b.getY(), 0.0f, 1.0f, 0.0f,
			c.getX(), c.getY(), 0.0f, 0.5f, 1.0f
		};

	uint* indices = new uint[3]{
		0, 1, 2
	};

	Mesh mesh(
		VertexBuffer(vertices, 15 * sizeof(float), Onyx::VertexFormat::VT),
		IndexBuffer(indices, 3 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;

	return Renderable(
		mesh,
		Shader::VT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::ColoredSquare(float side, Vec3 rgb)
{
	return ColoredQuad(side, side, rgb);
}

Onyx::Renderable Onyx::Renderable::ColoredSquare(float side, Vec4 rgba)
{
	return ColoredQuad(side, side, rgba);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(float width, float height, Vec3 rgb)
{
	return ColoredQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f),
		rgb
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(float width, float height, Vec4 rgba)
{
	return ColoredQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f),
		rgba
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec3 rgb)
{
	return Renderable(
		Mesh::Quad(a, b, c, d),
		Shader::V_Color(Vec4(rgb, 1.0f))
	);
}

Onyx::Renderable Onyx::Renderable::ColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec4 rgba)
{
	return Renderable(
		Mesh::Quad(a, b, c, d),
		Shader::V_Color(rgba)
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredSquare(float side)
{
	return VertexColoredQuad(side, side);
}

Onyx::Renderable Onyx::Renderable::VertexColoredQuad(float width, float height)
{
	return VertexColoredQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f)
	);
}

Onyx::Renderable Onyx::Renderable::VertexColoredQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	return Renderable(
		Mesh::Quad(a, b, c, d),
		Shader::V_XYZtoRGB()
	);
}

Onyx::Renderable Onyx::Renderable::TexturedSquare(float side, Texture texture)
{
	return TexturedQuad(side, side, texture);
}

Onyx::Renderable Onyx::Renderable::TexturedQuad(float width, float height, Texture texture)
{
	return TexturedQuad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::TexturedQuad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Texture texture)
{
	float* vertices = new float[20] {
		a.getX(), a.getY(), 0.0f, 0.0f, 0.0f,
			b.getX(), b.getY(), 0.0f, 1.0f, 0.0f,
			c.getX(), c.getY(), 0.0f, 1.0f, 1.0f,
			d.getX(), d.getY(), 0.0f, 0.0f, 1.0f
		};

	uint* indices = new uint[6]{
		0, 1, 2,
		2, 3, 0
	};

	Mesh mesh(
		VertexBuffer(vertices, 20 * sizeof(float), Onyx::VertexFormat::VT),
		IndexBuffer(indices, 6 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;

	return Renderable(
		mesh,
		Shader::VT(),
		texture
	);
}

Onyx::Renderable Onyx::Renderable::ColoredCube(float side, Vec3 rgb)
{
	return ColoredCube(side, Vec4(rgb, 1.0f));
}

Onyx::Renderable Onyx::Renderable::ColoredCube(float side, Vec4 rgba)
{
	float* vertices = new float[240] {
		-side / 2.0f, -side / 2.0f, side / 2.0f, 0.0f, 0.0f, 1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, -side / 2.0f, side / 2.0f, 0.0f, 0.0f, 1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, side / 2.0f, 0.0f, 0.0f, 1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, side / 2.0f, side / 2.0f, 0.0f, 0.0f, 1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),

			-side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),

			-side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, -1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, -1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, -side / 2.0f, side / 2.0f, 0.0f, -1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, -side / 2.0f, side / 2.0f, 0.0f, -1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),

			-side / 2.0f, side / 2.0f, -side / 2.0f, 0.0f, 1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, -side / 2.0f, 0.0f, 1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, side / 2.0f, 0.0f, 1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, side / 2.0f, side / 2.0f, 0.0f, 1.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),

			-side / 2.0f, -side / 2.0f, -side / 2.0f, -1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, -side / 2.0f, side / 2.0f, -1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, side / 2.0f, side / 2.0f, -1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			-side / 2.0f, side / 2.0f, -side / 2.0f, -1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),

			side / 2.0f, -side / 2.0f, -side / 2.0f, 1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, -side / 2.0f, side / 2.0f, 1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, side / 2.0f, 1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
			side / 2.0f, side / 2.0f, -side / 2.0f, 1.0f, 0.0f, 0.0f, rgba.getX(), rgba.getY(), rgba.getZ(), rgba.getW(),
		};

	uint* indices = new uint[36]{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	Mesh mesh(
		VertexBuffer(vertices, 240 * sizeof(float), Onyx::VertexFormat::VNC),
		IndexBuffer(indices, 36 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;

	return Renderable(
		mesh,
		Shader::VNC()
	);
}

Onyx::Renderable Onyx::Renderable::TexturedCube(float side, Texture texture)
{
	float* vertices = new float[192] {
		-side / 2.0f, -side / 2.0f,  side / 2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		 side / 2.0f, -side / 2.0f,  side / 2.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		 side / 2.0f,  side / 2.0f,  side / 2.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
		-side / 2.0f,  side / 2.0f,  side / 2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,

		-side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
		 side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
		 side / 2.0f,  side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
		-side / 2.0f,  side / 2.0f, -side / 2.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,

		-side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		 side / 2.0f, -side / 2.0f, -side / 2.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		 side / 2.0f, -side / 2.0f,  side / 2.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
		-side / 2.0f, -side / 2.0f,  side / 2.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,

		-side / 2.0f,  side / 2.0f, -side / 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
		 side / 2.0f,  side / 2.0f, -side / 2.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		 side / 2.0f,  side / 2.0f,  side / 2.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		-side / 2.0f,  side / 2.0f,  side / 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,

		-side / 2.0f, -side / 2.0f, -side / 2.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-side / 2.0f, -side / 2.0f,  side / 2.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-side / 2.0f,  side / 2.0f,  side / 2.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-side / 2.0f,  side / 2.0f, -side / 2.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

		 side / 2.0f, -side / 2.0f, -side / 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		 side / 2.0f, -side / 2.0f,  side / 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		 side / 2.0f,  side / 2.0f,  side / 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		 side / 2.0f,  side / 2.0f, -side / 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		};

	uint* indices = new uint[36]{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	Mesh mesh(
		VertexBuffer(vertices, 192 * sizeof(float), Onyx::VertexFormat::VNT),
		IndexBuffer(indices, 36 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;

	return Renderable(
		mesh,
		Shader::VNT(),
		texture
	);
}

void Onyx::Renderable::dispose()
{
	texture.dispose();
	shader.dispose();
	mesh.dispose();
}
