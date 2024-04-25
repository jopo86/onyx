#include "VertexBuffer.h"

Onyx::VertexBuffer::VertexBuffer()
{
	vertices = nullptr;
	size = 0;
	format = Onyx::VertexFormat::Null;
	heap = false;
}

Onyx::VertexBuffer::VertexBuffer(float *vertices, uint size, VertexFormat format)
{
	this->vertices = vertices;
	this->size = size;
	this->format = format;
	heap = false;
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

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float side)
{
	return Triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)));
}

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float base, float height)
{
	float* vertices = new float[6]{
		-base / 2.0f, -height / 2.0f,
		 base / 2.0f, -height / 2.0f,
		 0.0f,         height / 2.0f
	};

	VertexBuffer vb = VertexBuffer(vertices, 6 * sizeof(float), VertexFormat::P);
	vb.heap = true;
	return vb;
}

Onyx::VertexBuffer Onyx::VertexBuffer::Square(float side)
{
	float* vertices = new float[8]{
		-side / 2.0f, -side / 2.0f,
		 side / 2.0f, -side / 2.0f,
		 side / 2.0f,  side / 2.0f,
		-side / 2.0f,  side / 2.0f
	};

	VertexBuffer vb = VertexBuffer(vertices, 8 * sizeof(float), VertexFormat::P);
	vb.heap = true;
	return vb;
}

Onyx::VertexBuffer Onyx::VertexBuffer::Quad(float width, float height)
{
	float* vertices = new float[8]{
		-width / 2.0f, -height / 2.0f,
		 width / 2.0f, -height / 2.0f,
		 width / 2.0f,  height / 2.0f,
		-width / 2.0f,  height / 2.0f
	};

	VertexBuffer vb = VertexBuffer(vertices, 8 * sizeof(float), VertexFormat::P);
	vb.heap = true;
	return vb;
}

Onyx::VertexBuffer Onyx::VertexBuffer::Cube(float side)
{
	float* vertices = new float[24]{
		-side / 2.0f, -side / 2.0f,  side / 2.0f,
		 side / 2.0f, -side / 2.0f,  side / 2.0f,
		 side / 2.0f,  side / 2.0f,  side / 2.0f,
		-side / 2.0f,  side / 2.0f,  side / 2.0f,
		-side / 2.0f, -side / 2.0f, -side / 2.0f,
		 side / 2.0f, -side / 2.0f, -side / 2.0f,
		 side / 2.0f,  side / 2.0f, -side / 2.0f,
		-side / 2.0f,  side / 2.0f, -side / 2.0f
	};

	VertexBuffer vb = VertexBuffer(vertices, 24 * sizeof(float), VertexFormat::P);
	vb.heap = true;
	return vb;
}

Onyx::VertexBuffer Onyx::VertexBuffer::RectPrism(float width, float height, float depth)
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
	vb.heap = true;
	return vb;
}
