#include "Mesh.h"

#include <glad/glad.h>

void onyx_err(const Onyx::Error&);

using Onyx::Math::Vec2, Onyx::Math::Vec3;

Onyx::Mesh::Mesh()
{
	m_vao = m_vbo = m_ibo = 0;
	m_verticesSize = m_indicesSize = 0;
	m_vertexFormat = VertexFormat::Null;
}

Onyx::Mesh::Mesh(VertexBuffer vertexBuffer, IndexBuffer indexBuffer, bool* result)
{
	m_vao = m_vbo = m_ibo = 0;
	m_verticesSize = vertexBuffer.m_size;
	m_indicesSize = indexBuffer.m_size;
	m_vertexFormat = vertexBuffer.m_format;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexBuffer.m_size, vertexBuffer.m_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.m_size, indexBuffer.m_indices, GL_STATIC_DRAW);

	/*
		Layout locations:
		0: Position
		1: Color
		2: Texture coords
		3: Normal
	 */

	switch (vertexBuffer.m_format)
	{
		case VertexFormat::Null:
			onyx_err(Error{
					.sourceFunction = "Onyx::Mesh::Mesh(VertexBuffer vertexBuffer, IndexBuffer indexBuffer)",
					.message = "Vertex format cannot be null",
					.howToFix = "Pass a valid vertex format to the VertexBuffer constructor"
				}
			);
			if (result != nullptr) *result = false;
			return;

		case VertexFormat::P:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			break;

		case VertexFormat::PN:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			break;

		case VertexFormat::PT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			break;

		case VertexFormat::PCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			break;

		case VertexFormat::PNT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PNC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PNCT:
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

	if (vertexBuffer.m_heap) delete[] vertexBuffer.m_vertices;
	if (indexBuffer.m_heap) delete[] indexBuffer.m_indices;

	if (result != nullptr) *result = true;

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Mesh::Mesh(const Mesh& other)
{
	m_vao = other.m_vao;
	m_vbo = other.m_vbo;
	m_ibo = other.m_ibo;
	m_verticesSize = other.m_verticesSize;
	m_indicesSize = other.m_indicesSize;
	m_vertexFormat = other.m_vertexFormat;
}

void Onyx::Mesh::render() const
{
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, m_indicesSize / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

uint Onyx::Mesh::getVerticesSize() const
{
	return m_verticesSize;
}

uint Onyx::Mesh::getIndicesSize() const
{
	return m_indicesSize;
}

Onyx::VertexFormat Onyx::Mesh::getVertexFormat() const
{
	return m_vertexFormat;
}

uint Onyx::Mesh::getVAO() const
{
	return m_vao;
}

uint Onyx::Mesh::getVBO() const
{
	return m_vbo;
}

uint Onyx::Mesh::getIBO() const
{
	return m_ibo;
}

void Onyx::Mesh::dispose()
{
	if (m_vao) glDeleteVertexArrays(1, &m_vao);
	if (m_vbo) glDeleteBuffers(1, &m_vbo);
	if (m_ibo) glDeleteBuffers(1, &m_ibo);
	m_vao = m_vbo = m_ibo = 0;

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
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
		VertexBuffer(vertices, 9 * sizeof(float), VertexFormat::P),
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
		VertexBuffer(vertices, 12 * sizeof(float), VertexFormat::P),
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
		VertexBuffer(vertices, 24 * sizeof(float), VertexFormat::P),
		IndexBuffer(indices, 36 * sizeof(uint))
	);

	delete[] vertices;
	delete[] indices;
}
