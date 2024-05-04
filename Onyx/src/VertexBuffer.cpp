#include "VertexBuffer.h"

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
