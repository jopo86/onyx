#include "VertexArray.h"

Onyx::VertexArray::VertexArray()
{
	vertices = nullptr;
	size = format = 0;
	heap = false;
}

Onyx::VertexArray::VertexArray(float *vertices, ushort size, int format, bool heap)
{
	this->vertices = vertices;
	this->size = size;
	this->format = format;
	this->heap = heap;
}

float* Onyx::VertexArray::getVertices()
{
	return vertices;
}

ushort Onyx::VertexArray::getSize()
{
	return size;
}

int Onyx::VertexArray::getFormat()
{
	return format;
}

bool Onyx::VertexArray::isOnHeap()
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

void Onyx::VertexArray::setFormat(int format)
{
	this->format = format;
}
