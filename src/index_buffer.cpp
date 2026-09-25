#include <onyx/index_buffer.hpp>
#include <onyx/math_wrappers.hpp>
#include "internal.hpp"

#include <cmath>
#include <vector>

// Converts an angle step (in degrees) to the number of circle segments, shared by the vertex and index buffer generators
// so that both always agree on the vertex count.
static int segment_count(float angle_step_deg)
{
	float n = roundf(360.0f / angle_step_deg);
	if (!(n >= 3.0f)) return 3;
	if (n > 1000000.0f) return 1000000;
	return (int)n;
}

onyx::IndexBuffer::IndexBuffer()
{
	this->indices = nullptr;
	this->size = 0;
	this->heap = false;
}

onyx::IndexBuffer::IndexBuffer(u32* indices, u32 size)
{
	this->indices = indices;
	this->size = size;
	this->heap = false;
}

onyx::IndexBuffer onyx::IndexBuffer::triangle(bool normals)
{
	if (normals)
	{
		u32* indices = new u32[6]{
			0, 1, 2,
			3, 4, 5
		};

		IndexBuffer ib(indices, 6 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
	else
	{
		u32* indices = new u32[3]{
			0, 1, 2
		};

		IndexBuffer ib(indices, 3 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
}

onyx::IndexBuffer onyx::IndexBuffer::square(bool normals)
{
	return quad(normals);
}

onyx::IndexBuffer onyx::IndexBuffer::quad(bool normals)
{
	if (normals)
	{
		u32* indices = new u32[12]{
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			6, 7, 4
		};

		IndexBuffer ib(indices, 12 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
	else
	{
		u32* indices = new u32[6]{
			0, 1, 2,
			2, 3, 0
		};

		IndexBuffer ib(indices, 6 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
}

onyx::IndexBuffer onyx::IndexBuffer::circle(int n_segments, bool normals)
{
	return circle(360.0f / n_segments, normals);
}

onyx::IndexBuffer onyx::IndexBuffer::circle(float angle_step_deg, bool normals)
{
	if (normals)
	{
		int n_vertices = segment_count(angle_step_deg);

		std::vector<u32>* indices = new std::vector<u32>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < n_vertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = n_vertices + 1; i < 2 * n_vertices - 1; i++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(n_vertices);
		}

		return IndexBuffer(indices->data(), static_cast<u32>(indices->size() * sizeof(u32)));
	}
	else
	{
		int n_vertices = segment_count(angle_step_deg);

		std::vector<u32>* indices = new std::vector<u32>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < n_vertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		return IndexBuffer(indices->data(), static_cast<u32>(indices->size() * sizeof(u32)));
	}
}

onyx::IndexBuffer onyx::IndexBuffer::cube(bool normals_or_tex_coords)
{
	return rect_prism(normals_or_tex_coords);
}

onyx::IndexBuffer onyx::IndexBuffer::rect_prism(bool normals_or_tex_coords)
{
	if (normals_or_tex_coords)
	{
		u32* indices = new u32[36]{
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			6, 7, 4,

			8, 9, 10,
			10, 11, 8,

			12, 13, 14,
			14, 15, 12,

			16, 17, 18,
			18, 19, 16,

			20, 21, 22,
			22, 23, 20
		};

		IndexBuffer ib(indices, 36 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
	else
	{
		u32* indices = new u32[36]{
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

		IndexBuffer ib(indices, 36 * sizeof(u32));
		ib.heap = true;
		return ib;
	}
}

onyx::IndexBuffer onyx::IndexBuffer::cylinder(int n_segments, bool normals_or_tex_coords)
{
	return cylinder(360.0f / n_segments, normals_or_tex_coords);
}

onyx::IndexBuffer onyx::IndexBuffer::cylinder(float angle_step_deg, bool normals_or_tex_coords)
{
	if (normals_or_tex_coords)
	{
		int n_vertices = segment_count(angle_step_deg);

		std::vector<u32>* indices = new std::vector<u32>;
		onyx_add_malloc(indices, false);

		for (int i = 1; i < n_vertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = n_vertices + 1; i < 2 * n_vertices - 1; i++)
		{
			indices->push_back(n_vertices);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = 2 * n_vertices, j = 3 * n_vertices; i < 3 * n_vertices - 1 || j < 4 * n_vertices - 1; i++, j++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(j);

			indices->push_back(i + 1);
			indices->push_back(j + 1);
			indices->push_back(j);
		}

		indices->push_back(3 * n_vertices - 1);
		indices->push_back(2 * n_vertices);
		indices->push_back(4 * n_vertices - 1);

		indices->push_back(2 * n_vertices);
		indices->push_back(3 * n_vertices);
		indices->push_back(4 * n_vertices - 1);

		return IndexBuffer(indices->data(), static_cast<u32>(indices->size() * sizeof(u32)));
	}
	else
	{
		int n_vertices = segment_count(angle_step_deg);

		std::vector<u32>* indices = new std::vector<u32>;
		onyx_add_malloc(indices, false);
		
		for (int i = 1; i < n_vertices - 1; i++)
		{
			indices->push_back(0);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = n_vertices + 1; i < 2 * n_vertices - 1; i++)
		{
			indices->push_back(n_vertices);
			indices->push_back(i);
			indices->push_back(i + 1);
		}

		for (int i = 0, j = n_vertices; i < n_vertices - 1 || j < 2 * n_vertices - 1; i++, j++)
		{
			indices->push_back(i);
			indices->push_back(i + 1);
			indices->push_back(j);

			indices->push_back(i + 1);
			indices->push_back(j + 1);
			indices->push_back(j);
		}

		indices->push_back(n_vertices - 1);
		indices->push_back(0);
		indices->push_back(2 * n_vertices - 1);

		indices->push_back(0);
		indices->push_back(n_vertices);
		indices->push_back(2 * n_vertices - 1);

		return IndexBuffer(indices->data(), static_cast<u32>(indices->size() * sizeof(u32)));
	}
}
