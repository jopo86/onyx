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
			@brief Creates an empty index array.
			Trying to use an index array constructed like this will result in undefined behavior.
		 */
		IndexBuffer();

		/*
			@brief Creates an index array with the given indices.
			@param indices The indices to be used in the index array.
			@param size The size of the index array, in bytes.
		 */
		IndexBuffer(uint* indices, uint size);

		static IndexBuffer Triangle();

		static IndexBuffer Square();

		static IndexBuffer Quad();

		static IndexBuffer Cube();

		static IndexBuffer RectPrism();

	private:
		uint* indices;
		uint size;

		bool heap;
	};
}
