#pragma once

#include "Core.h"

namespace Onyx
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
		IndexBuffer(uint* indices, uint size);


	private:
		uint* m_indices;
		uint m_size;

		bool m_heap;

	public:

		/*
			@brief Generates an index buffer for a triangle.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Triangle(bool normals = false);

		/*
			@brief Generates an index buffer for a square. (Same as quad)
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Square(bool normals = false);

		/*
			@brief Generates an index buffer for a quad. (Same as square)
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Quad(bool normals = false);

		/*
			@brief Generates an index buffer for a circle with the specified number of line segments.
			@param nSegments The number of line segments used to approximate the circle outline.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Circle(int nSegments, bool normals = false);

		/*
			@brief Generates an index buffer for a circle with the specified angle step.
			@param angleStep The angle step, in degrees, between vertices.
			@param normals Whether the vertex buffer was generated with normals (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Circle(float angleStep, bool normals = false);

		/*
			@brief Generates an index buffer for a cube. (Same as rect prism)
			@param normalsOrTexCoords Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Cube(bool normalsOrTexCoords = false);

		/*
			@brief Generates an index buffer for a rect prism. (Same as cube)
			@param normalsOrTexCoords Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer RectPrism(bool normalsOrTexCoords = false);

		/*
			@brief Generates an index buffer for a cylinder with the specified number of line segments for its circles.
			@param nSegments The number of line segments used to approximate the circle outline.
			@param normals Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Cylinder(int nSegments, bool normalsOrTexCoords = false);

		/*
			@brief Generates an index buffer for a cylinder with the specified angle step for its circles.
			@param angleStep The angle step, in degrees, between circle vertices.
			@param normals Whether the vertex buffer was generated with normals AND/OR texture coordinates (this is needed because it increases the number of vertices).
			@return The generated index buffer.
		 */
		static IndexBuffer Cylinder(float angleStep, bool normalsOrTexCoords = false);
	};
}
