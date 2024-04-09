#pragma once

#include "Core.h"

namespace Onyx
{
	/*
		@brief A class to represent an array of indices, to be used in the creation of a mesh.
	 */
	class IndexArray
	{
	public:
		/*
			@brief Creates an empty index array.
			Trying to use an index array constructed like this will result in undefined behavior.
		 */
		IndexArray();

		/*
			@brief Creates an index array with the given indices.
			@param indices The indices to be used in the index array.
			@param size The size of the index array, in bytes.
		 */
		IndexArray(uint* indices, ushort size);

		/*
			@brief Gets the index data of the index array.
			@return The index data of the index array.
		 */
		uint* getIndices() const;

		/*
			@brief Gets the size of the index array.
			@return The size of the index array, in bytes.
		 */
		ushort getSize() const;

		/*
			@brief Sets the index data of the index array.
			@param indices The new index data of the index array.
		 */
		void setIndices(uint* indices);

		/*
			@brief Sets the size of the index array.
			@param size The new size of the index array, in bytes.
		 */
		void setSize(ushort size);

	private:
		uint* indices;
		ushort size;
	};
}
