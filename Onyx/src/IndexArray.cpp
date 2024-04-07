#include "IndexArray.h"

Onyx::IndexArray::IndexArray()
{
	indices = nullptr;
	size = 0;
	heap = false;
}

Onyx::IndexArray::IndexArray(uint *indices, ushort size, bool heap)
{
	this->indices = indices;
	this->size = size;
	this->heap = heap;
}

uint* Onyx::IndexArray::getIndices() const
{
	return indices;
}

ushort Onyx::IndexArray::getSize() const
{
	return size;
}

bool Onyx::IndexArray::isOnHeap() const
{
	return heap;
}

void Onyx::IndexArray::setIndices(uint *indices)
{
	this->indices = indices;
}

void Onyx::IndexArray::setSize(ushort size)
{
	this->size = size;
}
