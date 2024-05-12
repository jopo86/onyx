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

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float side, bool genNormals, bool genTexCoords)
{
	return Triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)), genNormals, genTexCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Triangle(float base, float height, bool genNormals, bool genTexCoords)
{
	if (genNormals && genTexCoords)
	{
		float* vertices = new float[48]{
			-base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		1.0f, 0.0f,
			 0.0f,         height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,		0.5f, 1.0f,

			-base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
			 0.0f,         height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,		0.5f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 48 * sizeof(float), VertexFormat::PNT);
		vb.m_heap = true;
		return vb;
	}
	else if (genNormals)
	{
		float* vertices = new float[36]{
			-base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 base / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 0.0f,         height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,

			-base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 base / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 0.0f,         height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 36 * sizeof(float), VertexFormat::PN);
		vb.m_heap = true;
		return vb;
	}
	else if (genTexCoords)
	{
		float* vertices = new float[15]{
			-base / 2.0f, -height / 2.0f,  0.0f,	0.0f, 0.0f,
			 base / 2.0f, -height / 2.0f,  0.0f,	1.0f, 0.0f,
			 0.0f,         height / 2.0f,  0.0f,	0.5f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 15 * sizeof(float), VertexFormat::PT);
		vb.m_heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[9]{
			-base / 2.0f, -height / 2.0f,  0.0f,
			 base / 2.0f, -height / 2.0f,  0.0f,
			 0.0f,         height / 2.0f,  0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 9 * sizeof(float), VertexFormat::P);
		vb.m_heap = true;
		return vb;
	}
}

Onyx::VertexBuffer Onyx::VertexBuffer::Square(float side, bool genNormals, bool genTexCoords)
{
	return Quad(side, side, genNormals, genTexCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Quad(float width, float height, bool genNormals, bool genTexCoords)
{
	if (genNormals && genTexCoords)
	{ 
		float* vertices = new float[64]{
			-width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,	0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,	0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 64 * sizeof(float), VertexFormat::PNT);
		vb.m_heap = true;
		return vb;
	}
	else if (genNormals)
	{
		float* vertices = new float[48]{
			-width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f, -height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,
			-width / 2.0f,  height / 2.0f,  0.001f,		0.0f, 0.0f,  1.0f,

			-width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f, -height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f,
			-width / 2.0f,  height / 2.0f, -0.001f,		0.0f, 0.0f, -1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 48 * sizeof(float), VertexFormat::PN);
		vb.m_heap = true;
		return vb;
	}
	else if (genTexCoords)
	{
		float* vertices = new float[20]{
			-width / 2.0f, -height / 2.0f,  0.0f,	0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  0.0f,	1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  0.0f,	1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  0.0f,	0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 20 * sizeof(float), VertexFormat::PT);
		vb.m_heap = true;
		return vb;
	}
	else
	{
		float* vertices = new float[12]{
			-width / 2.0f, -height / 2.0f,  0.0f,
			 width / 2.0f, -height / 2.0f,  0.0f,
			 width / 2.0f,  height / 2.0f,  0.0f,
			-width / 2.0f,  height / 2.0f,  0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 12 * sizeof(float), VertexFormat::P);
		vb.m_heap = true;
		return vb;
	}
}

Onyx::VertexBuffer Onyx::VertexBuffer::Circle(float r, int nSegments, bool genNormals, bool genTexCoords)
{
	return Circle(r, 360.0f / nSegments, genNormals, genTexCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::Circle(float r, float _angleStep, bool genNormals, bool genTexCoords)
{
	float angleStep = Math::Radians(_angleStep);

	if (genNormals)
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < Math::TAU; ang += angleStep)
		{
			float c = cosf(ang);
			float s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(0.001f)	;
			vertices->push_back(0.0f);
			vertices->push_back(0.0f);
			vertices->push_back(1.0f);
			if (genTexCoords)
			{
				vertices->push_back(Math::Remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(Math::Remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		for (float ang = 0.0f; ang < Math::TAU; ang += angleStep)
		{
			float c = cosf(ang);
			float s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(-0.001f)	;
			vertices->push_back(0.0f);
			vertices->push_back(0.0f);
			vertices->push_back(-1.0f);
			if (genTexCoords)
			{
				vertices->push_back(Math::Remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(Math::Remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), genTexCoords ? VertexFormat::PNT : VertexFormat::PN);
	}
	else
	{
		std::vector<float>* vertices = new std::vector<float>;
		onyx_add_malloc(vertices, false);

		for (float ang = 0.0f; ang < Math::TAU; ang += angleStep)
		{
			float c = cosf(ang);
			float s = sinf(ang);
			vertices->push_back(c * r);
			vertices->push_back(s * r);
			vertices->push_back(0.0f);
			if (genTexCoords)
			{
				vertices->push_back(Math::Remap(c, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
				vertices->push_back(Math::Remap(s, Vec2(-1.0f, 1.0f), Vec2(0.0f, 1.0f)));
			}
		}

		return VertexBuffer(vertices->data(), vertices->size() * sizeof(float), genTexCoords ? VertexFormat::PT : VertexFormat::P);
	}
}

Onyx::VertexBuffer Onyx::VertexBuffer::Cube(float side, bool genNormals, bool genTexCoords)
{
	return RectPrism(side, side, side, genNormals, genTexCoords);
}

Onyx::VertexBuffer Onyx::VertexBuffer::RectPrism(float width, float height, float depth, bool genNormals, bool genTexCoords)
{
	if (genNormals && genTexCoords)
	{ 
		float* vertices = new float[192]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,		0.0f, 1.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,		0.0f, 1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,		0.0f, 1.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,		0.0f, 1.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 192 * sizeof(float), VertexFormat::PNT);
		vb.m_heap = true;
		return vb;
	}
	else if (genNormals)
	{
		float* vertices = new float[144]{
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f, 0.0f,  1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f, 0.0f, -1.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		0.0f, -1.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		0.0f, -1.0f, 0.0f,

			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		0.0f,  1.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		0.0f,  1.0f, 0.0f,

			-width / 2.0f, -height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f, -height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f,  height / 2.0f,  depth / 2.0f,		-1.0f, 0.0f, 0.0f,
			-width / 2.0f,  height / 2.0f, -depth / 2.0f,		-1.0f, 0.0f, 0.0f,

			 width / 2.0f, -height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f, -height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f,  depth / 2.0f,		 1.0f, 0.0f, 0.0f,
			 width / 2.0f,  height / 2.0f, -depth / 2.0f,		 1.0f, 0.0f, 0.0f
		};

		VertexBuffer vb = VertexBuffer(vertices, 144 * sizeof(float), VertexFormat::PN);
		vb.m_heap = true;
		return vb;
	}
	else if (genTexCoords)
	{
		float* vertices = new float[120]{
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
	else
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
}
