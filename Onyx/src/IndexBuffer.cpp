#include "IndexBuffer.h"

Onyx::IndexBuffer::IndexBuffer()
{
	indices = nullptr;
	size = 0;
	heap = false;
}

Onyx::IndexBuffer::IndexBuffer(uint* indices, uint size)
{
	this->indices = indices;
	this->size = size;
	heap = false;
}

Onyx::IndexBuffer Onyx::IndexBuffer::Triangle()
{
	uint* indices = new uint[3]{
		0, 1, 2
	};

	IndexBuffer ib(indices, sizeof(indices));
	ib.heap = true;
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

	IndexBuffer ib(indices, sizeof(indices));
	ib.heap = true;
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

	IndexBuffer ib(indices, sizeof(indices));
	ib.heap = true;
	return ib;
}
