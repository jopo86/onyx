#pragma warning(disable: 4267)

#include "VertexBuffer.h"
#include "Math.h"

using Onyx::Math::Vec2;

void onyx_add_malloc(void*, bool);

Onyx::VertexBuffer::VertexBuffer()
{
	m_vertices = nullptr;
	m_size = 0;
	m_format = Onyx::VertexFormat::Null;
	m_heap = false;
}

Onyx::VertexBuffer::VertexBuffer(float *vertices, uint size, VertexFormat format)
{
	m_vertices = vertices;
	m_size = size;
	m_format = format;
	m_heap = false;
}

bool Onyx::VertexBuffer::HasNormals(Onyx::VertexFormat format)
{
	return format == VertexFormat::PN || format == VertexFormat::PNT || format == VertexFormat::PNC || format == VertexFormat::PNCT;
}

bool Onyx::VertexBuffer::HasTextureCoords(Onyx::VertexFormat format)
{
	return format == VertexFormat::PT || format == VertexFormat::PCT || format == VertexFormat::PNT || format == VertexFormat::PNCT;
}

bool Onyx::VertexBuffer::HasColors(Onyx::VertexFormat format)
{
	return format == VertexFormat::PC || format == VertexFormat::PCT || format == VertexFormat::PNC || format == VertexFormat::PNCT;
}

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float side, bool texCoords)
{
	return Triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), texCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float base, float height, bool texCoords)
{
	if (!texCoords)
	{
		float* vertices = new float[9]{
			-base / 2.0f, -height / 2.0f, 0.0f,
			 base / 2.0f, -height / 2.0f, 0.0f,
			 0.0f,         height / 2.0f, 0.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 9 * sizeof(float), VertexFormat::P);
		vb.m_heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[15] {
			-base / 2.0f, -height / 2.0f, 0.0f,		0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f, 0.0f,		1.0f, 0.0f,
			 0.0f,         height / 2.0f, 0.0f,		0.5f, 1.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 15 * sizeof(float), VertexFormat::PT);
		vb.m_heap = true;
		return vb;
	}
}

Onyx::VertexBuffer Onyx::VertexBuffer::Square(float side, bool texCoords)
{
	return Quad(side, side, texCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Quad(float width, float height, bool texCoords)
{
	if (!texCoords)
	{ 
		float* vertices = new float[12]{
			-width / 2.0f, -height / 2.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, 0.0f,
			-width / 2.0f,  height / 2.0f, 0.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 12 * sizeof(float), VertexFormat::P);
		vb.m_heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[20] {
			-width / 2.0f, -height / 2.0f, 0.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, 0.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, 0.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, 0.0f,	0.0f, 1.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 20 * sizeof(float), VertexFormat::PT);
		vb.m_heap = true;
		return vb;
	}
}

Onyx::VertexBuffer Onyx::VertexBuffer::Circle(float r, int nSegments, bool texCoords)
{
	return Circle(r, 360.0f / nSegments, texCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Circle(float r, float _angleStep, bool texCoords)
{
	float angleStep = Math::Radians(_angleStep);

	std::vector<float>* vertices = new std::vector<float>;
	onyx_add_malloc(vertices, false);

	for (float ang = 0.0f; ang < Math::TAU; ang += angleStep)
	{
		float c = cosf(ang);
		float s = sinf(ang);
		vertices->push_back(c * r);
		vertices->push_back(s * r);
		vertices->push_back(0.0f);
		if (texCoords)
		{
			vertices->push_back(Math::Remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			vertices->push_back(Math::Remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
		}
	}

	return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), texCoords ? VertexFormat::PT : VertexFormat::P);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Cube(float side, bool texCoords)
{
	return RectPrism(side, side, side, texCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::RectPrism(float width, float height, float depth, bool texCoords)
{
	if (!texCoords)
	{ 
		float* vertices = new float[24]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,
			-width / 2.0f, -height / 2.0f, -depth / 2.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 24 * sizeof(float), VertexFormat::P);
		vb.m_heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[120] {
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		1.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 1.0f,
		};

		VertexBuffer vb = VertexBuffer(vertices, 120 * sizeof(float), VertexFormat::PT);
		vb.m_heap = true;
		return vb;
	}
}
