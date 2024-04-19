#include "Mesh.h"

#include <glad/glad.h>

using Onyx::Math::Vec2, Onyx::Math::Vec3;

Onyx::Mesh::Mesh()
{
	vao = vbo = ibo = 0;
	verticesSize = indicesSize = 0;
}

Onyx::Mesh::Mesh(VertexBuffer vertexBuffer, IndexBuffer indexBuffer)
{
	vao = vbo = ibo = 0;
	verticesSize = vertexBuffer.size;
	indicesSize = indexBuffer.size;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexBuffer.size, vertexBuffer.vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.size, indexBuffer.indices, GL_STATIC_DRAW);

	/*
		Layout locations:
		0: Position
		1: Color
		2: Texture coordinates
		3: Normal
	 */

	switch (vertexBuffer.format)
	{
		case Onyx::VertexFormat::Null:
			Onyx::Err("Mesh creation failed: vertex format is null. (aborted)");
			return;

		case Onyx::VertexFormat::V:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			break;

		case Onyx::VertexFormat::VN:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			break;

		case Onyx::VertexFormat::VT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			break;

		case Onyx::VertexFormat::VCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			break;

		case Onyx::VertexFormat::VNT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VNC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VNCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(10 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	if (vertexBuffer.heap) delete[] vertexBuffer.vertices;
	if (indexBuffer.heap) delete[] indexBuffer.indices;
}

Onyx::Mesh::Mesh(const Mesh& other)
{
	vao = other.vao;
	vbo = other.vbo;
	ibo = other.ibo;
	verticesSize = other.verticesSize;
	indicesSize = other.indicesSize;
}

void Onyx::Mesh::render() const
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indicesSize / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

uint Onyx::Mesh::getVerticesSize() const
{
	return verticesSize;
}

uint Onyx::Mesh::getIndicesSize() const
{
	return indicesSize;
}

uint Onyx::Mesh::getVAO() const
{
	return vao;
}

uint Onyx::Mesh::getVBO() const
{
	return vbo;
}

uint Onyx::Mesh::getIBO() const
{
	return ibo;
}

void Onyx::Mesh::dispose()
{
	if (vao) glDeleteVertexArrays(1, &vao);
	if (vbo) glDeleteBuffers(1, &vbo);
	if (ibo) glDeleteBuffers(1, &ibo);
	vao = vbo = ibo = 0;
}

Onyx::Mesh Onyx::Mesh::Triangle(float side)
{
	return Triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)));
}

Onyx::Mesh Onyx::Mesh::Triangle(float base, float height)
{
	return Triangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2(base / 2.0f, -height / 2.0f),
		Vec2(0.0f, height / 2.0f)
	);
}

Onyx::Mesh Onyx::Mesh::Triangle(Vec2 a, Vec2 b, Vec2 c)
{
	float* vertices = new float[9] {
		a.getX(), a.getY(), 0.0f,
			b.getX(), b.getY(), 0.0f,
			c.getX(), c.getY(), 0.0f
		};

	uint* indices = new uint[3]{
		0, 1, 2
	};

	return Mesh(
		VertexBuffer(vertices, 9 * sizeof(float), Onyx::VertexFormat::V),
		IndexBuffer(indices, 3 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;
}

Onyx::Mesh Onyx::Mesh::Square(float side)
{
	return Quad(side, side);
}

Onyx::Mesh Onyx::Mesh::Quad(float width, float height)
{
	return Quad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, -height / 2.0f),
		Vec2(width / 2.0f, height / 2.0f),
		Vec2(-width / 2.0f, height / 2.0f)
	);
}

Onyx::Mesh Onyx::Mesh::Quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	float* vertices = new float[12] {
		a.getX(), a.getY(), 0.0f,
			b.getX(), b.getY(), 0.0f,
			c.getX(), c.getY(), 0.0f,
			d.getX(), d.getY(), 0.0f
		};

	uint* indices = new uint[6]{
		0, 1, 2,
		2, 3, 0
	};

	return Mesh(
		VertexBuffer(vertices, 12 * sizeof(float), Onyx::VertexFormat::V),
		IndexBuffer(indices, 6 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;
}

Onyx::Mesh Onyx::Mesh::Cube(float side)
{
	return RectPrism(side, side, side);
}

Onyx::Mesh Onyx::Mesh::RectPrism(float width, float height, float depth)
{
	return RectPrism(
		Vec3(-width / 2.0f, -height / 2.0f,  depth / 2.0f),
		Vec3( width / 2.0f, -height / 2.0f,  depth / 2.0f),
		Vec3( width / 2.0f,  height / 2.0f,  depth / 2.0f),
		Vec3(-width / 2.0f,  height / 2.0f,  depth / 2.0f),
		Vec3(-width / 2.0f, -height / 2.0f, -depth / 2.0f),
		Vec3( width / 2.0f, -height / 2.0f, -depth / 2.0f),
		Vec3( width / 2.0f,  height / 2.0f, -depth / 2.0f),
		Vec3(-width / 2.0f,  height / 2.0f, -depth / 2.0f)
	);
}

Onyx::Mesh Onyx::Mesh::RectPrism(Vec3 a, Vec3 b, Vec3 c, Vec3 d, Vec3 e, Vec3 f, Vec3 g, Vec3 h)
{
	float* vertices = new float[24] {
		a.getX(), a.getY(), a.getZ(),
		b.getX(), b.getY(), b.getZ(),
		c.getX(), c.getY(), c.getZ(),
		d.getX(), d.getY(), d.getZ(),
		e.getX(), e.getY(), e.getZ(),
		f.getX(), f.getY(), f.getZ(),
		g.getX(), g.getY(), g.getZ(),
		h.getX(), h.getY(), h.getZ()
	};

	uint* indices = new uint[36]{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		0, 1, 5,
		5, 4, 0,

		3, 2, 6,
		6, 7, 3,

		0, 4, 7,
		7, 3, 0,

		1, 5, 6,
		6, 2, 1
	};

	return Mesh(
		VertexBuffer(vertices, 24 * sizeof(float), Onyx::VertexFormat::V),
		IndexBuffer(indices, 36 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;
}
