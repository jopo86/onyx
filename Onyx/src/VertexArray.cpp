#include "VertexArray.h"

Onyx::VertexArray::VertexArray()
{
	vertices = nullptr;
	size = 0;
	format = Onyx::VertexFormat::Null;
}

Onyx::VertexArray::VertexArray(float *vertices, uint size, VertexFormat format)
{
	this->vertices = vertices;
	this->size = size;
	this->format = format;
}

float* Onyx::VertexArray::getVertices() const
{
	return vertices;
}

uint Onyx::VertexArray::getSize() const
{
	return size;
}

Onyx::VertexFormat Onyx::VertexArray::getFormat() const
{
	return format;
}

void Onyx::VertexArray::setVertices(float *vertices)
{
	this->vertices = vertices;
}

void Onyx::VertexArray::setSize(uint size)
{
	this->size = size;
}

void Onyx::VertexArray::setFormat(VertexFormat format)
{
	this->format = format;
}
