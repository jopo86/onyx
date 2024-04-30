#include "IndexBuffer.h"

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
