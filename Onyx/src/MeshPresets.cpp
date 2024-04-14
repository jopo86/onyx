#pragma warning(disable : 4244)

#include "MeshPresets.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3;

Onyx::Mesh Onyx::MeshPresets::Triangle(float side)
{
	return Triangle(side, sqrtf(powf(side, 2.0f) - powf(side / 2.0f, 2.0f)));
}

Onyx::Mesh Onyx::MeshPresets::Triangle(float base, float height)
{
	return Triangle(
		Vec2(-base / 2.0f, -height / 2.0f),
		Vec2( base / 2.0f, -height / 2.0f),
		Vec2( 0.0f,         height / 2.0f)
	);
}

Onyx::Mesh Onyx::MeshPresets::Triangle(Vec2 a, Vec2 b, Vec2 c)
{
	float* vertices = new float[9]{
		a.getX(), a.getY(), 0.0f,
		b.getX(), b.getY(), 0.0f,
		c.getX(), c.getY(), 0.0f
	};

	uint* indices = new uint[3]{
		0, 1, 2
	};

	return Mesh(
		VertexArray(vertices, 9 * sizeof(float), Onyx::VertexFormat::V),
		IndexArray(indices, 3 * sizeof(uint))
	);
}

Onyx::Mesh Onyx::MeshPresets::Square(float side)
{
	return Quad(side, side);
}

Onyx::Mesh Onyx::MeshPresets::Quad(float width, float height)
{
	return Quad(
		Vec2(-width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f, -height / 2.0f),
		Vec2( width / 2.0f,  height / 2.0f),
		Vec2(-width / 2.0f,  height / 2.0f)
	);
}

Onyx::Mesh Onyx::MeshPresets::Quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	float* vertices = new float[12]{
		a.getX(), a.getY(), 0.0f,
		b.getX(), b.getY(), 0.0f,
		c.getX(), c.getY(), 0.0f,
		d.getX(), d.getY(), 0.0f
	};

	uint* indices = new uint[6]{
		0, 1, 2,
		2, 3, 0
	};

	Onyx::AddMalloc(vertices, true);
	Onyx::AddMalloc(indices, true);

	return Mesh(
		VertexArray(vertices, 12 * sizeof(float), Onyx::VertexFormat::V),
		IndexArray(indices, 6 * sizeof(uint))
	);
}

Onyx::Mesh Onyx::MeshPresets::Cube(float side)
{
	return RectPrism(side, side, side);
}

Onyx::Mesh Onyx::MeshPresets::RectPrism(float width, float height, float depth)
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

Onyx::Mesh Onyx::MeshPresets::RectPrism(Vec3 a, Vec3 b, Vec3 c, Vec3 d, Vec3 e, Vec3 f, Vec3 g, Vec3 h)
{
	float* vertices = new float[24]{
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

	Onyx::AddMalloc(vertices, true);
	Onyx::AddMalloc(indices, true);

	return Mesh(
		VertexArray(vertices, 24 * sizeof(float), Onyx::VertexFormat::V),
		IndexArray(indices, 36 * sizeof(uint))
	);
}

Onyx::VertexArray Onyx::MeshPresets::GetTriangleVertices(float side)
{
	int base = side;
	int height = sqrtf(powf(side / 2.0f, 2.0f) + powf(side, 2.0f));

	float* vertices = new float[6]{
		-base / 2.0f, -height / 2.0f,
		 base / 2.0f, -height / 2.0f,
		 0.0f,         height / 2.0f
	};

	Onyx::AddMalloc(vertices, true);

	return VertexArray(vertices, 6 * sizeof(float), Onyx::VertexFormat::V);
}

Onyx::VertexArray Onyx::MeshPresets::GetTriangleVertices(float base, float height)
{
	float* vertices = new float[6]{
		-base / 2.0f, -height / 2.0f,
		 base / 2.0f, -height / 2.0f,
		 0.0f,         height / 2.0f
	};

	Onyx::AddMalloc(vertices, true);

	return VertexArray(vertices, 6 * sizeof(float), Onyx::VertexFormat::V);
}

Onyx::VertexArray Onyx::MeshPresets::GetSquareVertices(float side)
{
	float* vertices = new float[8]{
		-side / 2.0f, -side / 2.0f,
		 side / 2.0f, -side / 2.0f,
		 side / 2.0f,  side / 2.0f,
		-side / 2.0f,  side / 2.0f
	};

	Onyx::AddMalloc(vertices, true);

	return VertexArray(vertices, 8 * sizeof(float), Onyx::VertexFormat::V);
}

Onyx::VertexArray Onyx::MeshPresets::GetQuadVertices(float width, float height)
{
	float* vertices = new float[8]{
		-width / 2.0f, -height / 2.0f,
		 width / 2.0f, -height / 2.0f,
		 width / 2.0f,  height / 2.0f,
		-width / 2.0f,  height / 2.0f
	};

	Onyx::AddMalloc(vertices, true);

	return VertexArray(vertices, 8 * sizeof(float), Onyx::VertexFormat::V);
}

Onyx::VertexArray Onyx::MeshPresets::GetRectPrismVertices(float width, float height, float depth)
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

	Onyx::AddMalloc(vertices, true);

	return VertexArray(vertices, 24 * sizeof(float), Onyx::VertexFormat::V);
}

Onyx::IndexArray Onyx::MeshPresets::GetIndices(Onyx::MeshType meshType)
{
	IndexArray retval;

	switch (meshType)
	{
		case Onyx::MeshType::Triangle:
		{
			uint* indices = new uint[3]{ 0, 1, 2 };
			Onyx::AddMalloc(indices, true);
			retval = IndexArray(indices, 3 * sizeof(uint));
			break;
		}

		case Onyx::MeshType::Square: case Onyx::MeshType::Quad:
		{
			uint* indices = new uint[6]{
				0, 1, 2,
				2, 3, 0
			};
			Onyx::AddMalloc(indices, true);
			retval = IndexArray(indices, 6 * sizeof(uint));
			break;
		}

		case Onyx::MeshType::Cube: case Onyx::MeshType::RectPrism:
		{
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
			Onyx::AddMalloc(indices, true);
			retval = IndexArray(indices, 36 * sizeof(uint));
			break;
		}
	}

	return retval;
}
