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
			@return The generated index buffer.
		 */
		static IndexBuffer Triangle();

		/*
			@brief Generates an index buffer for a square. (Same as quad)
			@return The generated index buffer.
		 */
		static IndexBuffer Square();

		/*
			@brief Generates an index buffer for a quad. (Same as square)
			@return The generated index buffer.
		 */
		static IndexBuffer Quad();

		/*
			@brief Generates an index buffer for a circle with the specified number of line segments.
			@param nSegments The number of line segments used to approximate the circle outline.
			@return The generated index buffer.
		 */
		static IndexBuffer Circle(int nSegments);

		/*
			@brief Generates an index buffer for a circle with the specified angle step.
			@param angleStep The angle step, in degrees, between vertices.
			@return The generated index buffer.
		 */
		static IndexBuffer Circle(float angleStep);

		/*
			@brief Generates an index buffer for a cube. (Same as rect prism)
			@return The generated index buffer.
		 */
		static IndexBuffer Cube();

		/*
			@brief Generates an index buffer for a rect prism. (Same as cube)
			@return The generated index buffer.
		 */
		static IndexBuffer RectPrism();
	};
}
