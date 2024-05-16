#pragma warning(disable: 4267)

#include "IndexBuffer.h"
#include "Math.h"

void onyx_add_malloc(void*, bool);

Onyx::IndexBuffer::IndexBuffer()
{
	m_indices = nullptr;
	m_size = 0;
	m_heap = false;
}

Onyx::IndexBuffer::IndexBuffer(uint* indices, uint size)
{
	m_indices = indices;
	m_size = size;
	m_heap = false;
}

Onyx::IndexBuffer Onyx::IndexBuffer::Triangle(bool normals)
{
	if (normals)
	{
		uint* indices = new uint[6]{
			0, 1, 2,
			3, 4, 5
		};

		IndexBuffer ib(indices, 6 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
	else
	{
		uint* indices = new uint[3]{
			0, 1, 2
		};

		IndexBuffer ib(indices, 3 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
}

Onyx::IndexBuffer Onyx::IndexBuffer::Square(bool normals)
{
	return Quad(normals);
}

Onyx::IndexBuffer Onyx::IndexBuffer::Quad(bool normals)
{
	if (normals)
	{
		uint* indices = new uint[12]{
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			6, 7, 4
		};

		IndexBuffer ib(indices, 12 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
	else
	{
		uint* indices = new uint[6]{
			0, 1, 2,
			2, 3, 0
		};

		IndexBuffer ib(indices, 6 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
}

Onyx::IndexBuffer Onyx::IndexBuffer::Circle(int nSegments, bool normals)
{
	return Circle(360.0f / nSegments, normals);
}

Onyx::IndexBuffer Onyx::IndexBuffer::Circle(float angleStepDeg, bool normals)
{
	if (normals)
	{
		int nVertices = (int)(360.0f / angleStepDeg);
		float angleStep = Math::Radians(angleStepDeg);

		std::vector<uint>* indices = new std::vector<uint>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < nVertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = nVertices + 1; i < 2 * nVertices - 1; i++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(nVertices);
		}

		return IndexBuffer(indices->data(), indices->size() * sizeof(uint));
	}
	else
	{
		int nVertices = (int)(360.0f / angleStepDeg);
		float angleStep = Math::Radians(angleStepDeg);

		std::vector<uint>* indices = new std::vector<uint>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < nVertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		return IndexBuffer(indices->data(), indices->size() * sizeof(uint));
	}
}

Onyx::IndexBuffer Onyx::IndexBuffer::Cube(bool normalsOrTexCoords)
{
	return RectPrism(normalsOrTexCoords);
}

Onyx::IndexBuffer Onyx::IndexBuffer::RectPrism(bool normalsOrTexCoords)
{
	if (normalsOrTexCoords)
	{
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

		IndexBuffer ib(indices, 36 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
	else
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

		IndexBuffer ib(indices, 36 * sizeof(uint));
		ib.m_heap = true;
		return ib;
	}
}

Onyx::IndexBuffer Onyx::IndexBuffer::Cylinder(int nSegments, bool normalsOrTexCoords)
{
	return Cylinder(360.0f / nSegments, normalsOrTexCoords);
}

Onyx::IndexBuffer Onyx::IndexBuffer::Cylinder(float angleStepDeg, bool normalsOrTexCoords)
{
	if (normalsOrTexCoords)
	{
		int nVertices = (int)(360.0f / angleStepDeg);

		std::vector<uint>* indices = new std::vector<uint>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < nVertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = nVertices + 1; i < 2 * nVertices - 1; i++)
		{
			indices->push_back(nVertices);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = 2 * nVertices, j = 3 * nVertices; i < 3 * nVertices - 1 || j < 4 * nVertices - 1; i++, j++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(j);

			indices->push_back(i + 1);
			indices->push_back(j + 1);
			indices->push_back(j);
		}

		indices->push_back(3 * nVertices - 1);
		indices->push_back(2 * nVertices);
		indices->push_back(4 * nVertices - 1);

		indices->push_back(2 * nVertices);
		indices->push_back(3 * nVertices);
		indices->push_back(4 * nVertices - 1);

		return IndexBuffer(indices->data(), indices->size() * sizeof(uint));
	}
	else
	{
		int nVertices = (int)(360.0f / angleStepDeg);

		std::vector<uint>* indices = new std::vector<uint>;
		onyx_add_malloc(indices, false);
		
		for (int i = 1; i < nVertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = nVertices + 1; i < 2 * nVertices - 1; i++)
		{
			indices->push_back(nVertices);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = 0, j = nVertices; i < nVertices - 1 || j < 2 * nVertices - 1; i++, j++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(j);

			indices->push_back(i + 1);
			indices->push_back(j + 1);
			indices->push_back(j);
		}

		indices->push_back(nVertices - 1);
		indices->push_back(1);
		indices->push_back(2 * nVertices - 1);

		indices->push_back(1);
		indices->push_back(nVertices);
		indices->push_back(2 * nVertices - 1);

		return IndexBuffer(indices->data(), indices->size() * sizeof(uint));
	}
}
