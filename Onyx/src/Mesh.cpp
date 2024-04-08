#include "Mesh.h"

Onyx::Mesh::Mesh()
{
	vao = vbo = ibo = 0;
}

Onyx::Mesh::Mesh(VertexArray vertexArray, IndexArray indexArray)
{
	vao = vbo = ibo = 0;
	this->vertexArray = vertexArray;
	this->indexArray = indexArray;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexArray.getSize(), vertexArray.getVertices(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexArray.getSize(), indexArray.getIndices(), GL_STATIC_DRAW);

	/*
		Layout locations:
		0: Position
		1: Color
		2: Texture coordinates
		3: Normal
	 */

	switch (vertexArray.getFormat())
	{
		case Onyx::VertexFormat::Null:
			Onyx::Err("Mesh creation failed: vertex format is null. (aborted)");
			return;

		case Onyx::VertexFormat::V:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			break;

		case Onyx::VertexFormat::VN:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			break;

		case Onyx::VertexFormat::VT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			break;

		case Onyx::VertexFormat::VCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			break;

		case Onyx::VertexFormat::VNT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VNC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(3);
			break;

		case Onyx::VertexFormat::VNCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
			glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(10 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Onyx::Mesh::Mesh(const Mesh& other)
{
	vao = other.vao;
	vbo = other.vbo;
	ibo = other.ibo;
	vertexArray = other.vertexArray;
	indexArray = other.indexArray;
}

void Onyx::Mesh::render() const
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indexArray.getSize() / sizeof(uint), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
}

Onyx::VertexArray Onyx::Mesh::getVertexArray() const
{
	return vertexArray;
}

Onyx::IndexArray Onyx::Mesh::getIndexArray() const
{
	return indexArray;
}

uint Onyx::Mesh::getVAO() const
{
	return vao;
}

uint Onyx::Mesh::getVBO() const
{
	return vbo;
}

uint Onyx::Mesh::getIBO() const
{
	return ibo;
}

void Onyx::Mesh::dispose()
{
	if (vao) glDeleteVertexArrays(1, &vao);
	if (vbo) glDeleteBuffers(1, &vbo);
	if (ibo) glDeleteBuffers(1, &ibo);
	vao = vbo = ibo = 0;
	if (vertexArray.getVertices() != nullptr && vertexArray.isOnHeap()) delete[] vertexArray.getVertices();
	if (indexArray.getIndices() != nullptr && indexArray.isOnHeap()) delete[] indexArray.getIndices();
}
