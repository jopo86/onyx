#include "VertexArray.h"

Onyx::VertexArray::VertexArray()
{
	vertices = nullptr;
	size = 0;
	format = Onyx::VertexFormat::Null;
	heap = false;
}

Onyx::VertexArray::VertexArray(float *vertices, ushort size, VertexFormat format, bool heap)
{
	this->vertices = vertices;
	this->size = size;
	this->format = format;
	this->heap = heap;
}

float* Onyx::VertexArray::getVertices() const
{
	return vertices;
}

ushort Onyx::VertexArray::getSize() const
{
	return size;
}

Onyx::VertexFormat Onyx::VertexArray::getFormat() const
{
	return format;
}

bool Onyx::VertexArray::isOnHeap() const
{
	return heap;
}

void Onyx::VertexArray::setVertices(float *vertices)
{
	this->vertices = vertices;
}

void Onyx::VertexArray::setSize(ushort size)
{
	this->size = size;
}

void Onyx::VertexArray::setFormat(VertexFormat format)
{
	this->format = format;
}
