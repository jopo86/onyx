#include <onyx/mesh.hpp>

#include <glad/glad.h>
#include "internal.hpp"

onyx::Mesh::Mesh()
{
	this->vao = this->vbo = this->ibo = 0;
	this->vertices_size = this->indices_size = 0;
	this->vertex_format = VertexFormat::Null;
}

onyx::Mesh::Mesh(VertexBuffer vertex_buffer, IndexBuffer index_buffer, bool* result)
{
	this->vao = this->vbo = this->ibo = 0;
	this->vertices_size = vertex_buffer.size;
	this->indices_size = index_buffer.size;
	this->vertex_format = vertex_buffer.format;

	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);
	glGenBuffers(1, &this->ibo);

	glBindVertexArray(this->vao);

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer.size, vertex_buffer.vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_buffer.size, index_buffer.indices, GL_STATIC_DRAW);

	/*
		Layout locations:
		0: Position
		1: Colors
		2: Texture Coords
		3: Normals
	 */

	switch (vertex_buffer.format)
	{
		case VertexFormat::Null:
			onyx_err(Error{
					.source_function = "onyx::Mesh::Mesh(VertexBuffer vertex_buffer, IndexBuffer index_buffer, bool* result)",
					.message = "Vertex format cannot be null",
					.how_to_fix = "Pass a valid vertex format to the VertexBuffer constructor"
				}
			);
			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			if (vertex_buffer.heap) delete[] vertex_buffer.vertices;
			if (index_buffer.heap) delete[] index_buffer.indices;
			if (result != nullptr) *result = false;
			return;

		case VertexFormat::P:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			break;

		case VertexFormat::PN:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			break;

		case VertexFormat::PT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			break;

		case VertexFormat::PCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			break;

		case VertexFormat::PNT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PNC:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(3);
			break;

		case VertexFormat::PNCT:
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(6 * sizeof(float)));
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(10 * sizeof(float)));
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);
			glEnableVertexAttribArray(3);
			break;
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	if (vertex_buffer.heap) delete[] vertex_buffer.vertices;
	if (index_buffer.heap) delete[] index_buffer.indices;

	if (result != nullptr) *result = true;

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

onyx::Mesh::Mesh(const Mesh& other)
{
	this->vao = other.vao;
	this->vbo = other.vbo;
	this->ibo = other.ibo;
	this->vertices_size = other.vertices_size;
	this->indices_size = other.indices_size;
	this->vertex_format = other.vertex_format;
}

void onyx::Mesh::render() const
{
	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->indices_size / sizeof(u32), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

u32 onyx::Mesh::get_vertices_size() const
{
	return this->vertices_size;
}

u32 onyx::Mesh::get_indices_size() const
{
	return this->indices_size;
}

onyx::VertexFormat onyx::Mesh::get_vertex_format() const
{
	return this->vertex_format;
}

u32 onyx::Mesh::get_vao() const
{
	return this->vao;
}

u32 onyx::Mesh::get_vbo() const
{
	return this->vbo;
}

u32 onyx::Mesh::get_ibo() const
{
	return this->ibo;
}

void onyx::Mesh::dispose()
{
	if (this->disposed) return;
	if (this->vao) glDeleteVertexArrays(1, &this->vao);
	if (this->vbo) glDeleteBuffers(1, &this->vbo);
	if (this->ibo) glDeleteBuffers(1, &this->ibo);
	this->vao = this->vbo = this->ibo = 0;
	this->disposed = true;

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

onyx::Mesh onyx::Mesh::triangle(float side, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::triangle(side, gen_normals, gen_tex_coords),
		IndexBuffer::triangle(gen_normals)
	);
}

onyx::Mesh onyx::Mesh::triangle(float base, float height, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::triangle(base, height, gen_normals, gen_tex_coords),
		IndexBuffer::triangle(gen_normals)
	);
}

onyx::Mesh onyx::Mesh::square(float side, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::square(side, gen_normals, gen_tex_coords),
		IndexBuffer::square(gen_normals)
	);
}

onyx::Mesh onyx::Mesh::quad(float width, float height, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::quad(width, height, gen_normals, gen_tex_coords),
		IndexBuffer::quad(gen_normals)
	);
}

onyx::Mesh onyx::Mesh::circle(float r, int n_segments, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::circle(r, n_segments, gen_normals, gen_tex_coords),
		IndexBuffer::circle(n_segments, gen_normals)
	);
}

onyx::Mesh onyx::Mesh::circle(float r, float _angleStep, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::circle(r, _angleStep, gen_normals, gen_tex_coords),
		IndexBuffer::circle(_angleStep, gen_normals)
	);
}

onyx::Mesh onyx::Mesh::cube(float side, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::cube(side, gen_normals, gen_tex_coords),
		IndexBuffer::cube(gen_normals || gen_tex_coords)
	);
}

onyx::Mesh onyx::Mesh::rect_prism(float width, float height, float depth, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::rect_prism(width, height, depth, gen_normals, gen_tex_coords),
		IndexBuffer::rect_prism(gen_normals || gen_tex_coords)
	);
}

onyx::Mesh onyx::Mesh::cylinder(float radius, float height, int n_segments, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::cylinder(radius, height, n_segments, gen_normals, gen_tex_coords),
		IndexBuffer::cylinder(n_segments, gen_normals || gen_tex_coords)
	);
}

onyx::Mesh onyx::Mesh::cylinder(float radius, float height, float angle_step, bool gen_normals, bool gen_tex_coords)
{
	return Mesh(
		VertexBuffer::cylinder(radius, height, angle_step, gen_normals, gen_tex_coords),
		IndexBuffer::cylinder(angle_step, gen_normals || gen_tex_coords)
	);
}
