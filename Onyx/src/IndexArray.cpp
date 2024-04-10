#include "IndexArray.h"

Onyx::IndexArray::IndexArray()
{
	indices = nullptr;
	size = 0;
}

Onyx::IndexArray::IndexArray(uint *indices, uint size)
{
	this->indices = indices;
	this->size = size;
}

uint* Onyx::IndexArray::getIndices() const
{
	return indices;
}

uint Onyx::IndexArray::getSize() const
{
	return size;
}

void Onyx::IndexArray::setIndices(uint *indices)
{
	this->indices = indices;
}

void Onyx::IndexArray::setSize(uint size)
{
	this->size = size;
}
