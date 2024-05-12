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

Onyx::IndexBuffer Onyx::IndexBuffer::Triangle()
{
	uint* indices = new uint[3]{
		0, 1, 2
	};

	IndexBuffer ib(indices, 3 * sizeof(uint));
	ib.m_heap = true;
	return ib;
}

Onyx::IndexBuffer Onyx::IndexBuffer::Square()
{
	return Quad();
}

Onyx::IndexBuffer Onyx::IndexBuffer::Quad()
{
	uint* indices = new uint[6]{
		0, 1, 2,
		2, 3, 0
	};

	IndexBuffer ib(indices, 6 * sizeof(uint));
	ib.m_heap = true;
	return ib;
}

Onyx::IndexBuffer Onyx::IndexBuffer::Circle(int nSegments)
{
	return Circle(360.0f / nSegments);
}

Onyx::IndexBuffer Onyx::IndexBuffer::Circle(float _angleStep)
{
	float angleStep = Math::Radians(_angleStep);

	std::vector<uint>* indices = new std::vector<uint>;
	onyx_add_malloc(indices, false);

	int i = 0;
	for (float ang = 0.0f; ang < Math::TAU; ang += angleStep)
	{
		if (i == 0 || ang + angleStep >= Math::TAU)
		{
			i++;
			continue;
		}
		indices->push_back(i);
		indices->push_back(i + 1);
		indices->push_back(0);
		i++;
	}

	return IndexBuffer(indices->data(), indices->size() * sizeof(uint));
}

Onyx::IndexBuffer Onyx::IndexBuffer::Cube()
{
	return RectPrism();
}

Onyx::IndexBuffer Onyx::IndexBuffer::RectPrism()
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
