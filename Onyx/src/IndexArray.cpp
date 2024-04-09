#include "IndexArray.h"

Onyx::IndexArray::IndexArray()
{
	indices = nullptr;
	size = 0;
}

Onyx::IndexArray::IndexArray(uint *indices, ushort size)
{
	this->indices = indices;
	this->size = size;
}

uint* Onyx::IndexArray::getIndices() const
{
	return indices;
}

ushort Onyx::IndexArray::getSize() const
{
	return size;
}

void Onyx::IndexArray::setIndices(uint *indices)
{
	this->indices = indices;
}

void Onyx::IndexArray::setSize(ushort size)
{
	this->size = size;
}
