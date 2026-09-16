#pragma once

#include "core.h"

namespace onyx
{
	/*
		@brief A class to represent an array of indices, to be used in the creation of a mesh.
	 */
	class IndexBuffer
	{
		friend class Mesh;
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		IndexBuffer();

		/*
			@brief Creates an index array with the given indices.
			@param indices The indices to be used in the index array.
			@param size The size of the index array, in bytes.
		 */
		IndexBuffer(u32* indices, u32 size);


	private:
		u32* indices;
		u32 size;

		bool heap;

	public:

		/*
			@brief Generates an index buffer for a triangle.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer triangle(bool normals = false);

		/*
			@brief Generates an index buffer for a square. (Same as quad)
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer square(bool normals = false);

		/*
			@brief Generates an index buffer for a quad. (Same as square)
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer quad(bool normals = false);

		/*
			@brief Generates an index buffer for a circle with the specified number of line segments.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer circle(int n_segments, bool normals = false);

		/*
			@brief Generates an index buffer for a circle with the specified angle step.
			@param angle_step The angle step, in degrees, between vertices.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer circle(float angle_step, bool normals = false);

		/*
			@brief Generates an index buffer for a cube. (Same as rect prism)
			@param normals_or_tex_coords Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer cube(bool normals_or_tex_coords = false);

		/*
			@brief Generates an index buffer for a rect prism. (Same as cube)
			@param normals_or_tex_coords Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer rect_prism(bool normals_or_tex_coords = false);

		/*
			@brief Generates an index buffer for a cylinder with the specified number of line segments for its circles.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param normals Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer cylinder(int n_segments, bool normals_or_tex_coords = false);

		/*
			@brief Generates an index buffer for a cylinder with the specified angle step for its circles.
			@param angle_step The angle step, in degrees, between circle vertices.
			@param normals Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer cylinder(float angle_step, bool normals_or_tex_coords = false);
	};
}
