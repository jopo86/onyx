#pragma once

#include "Core.h"

namespace Onyx
{
	class VertexArray
	{
	public:
		/*
			@brief Creates an empty vertex array.
			Trying to use an vertex array constructed like this will result in undefined behavior.
		 */
		VertexArray();

		/*
			@brief Creates an vertex array with the given vertices.
			@param vertices The vertices to be used in the vertex array.
			@param size The size of the vertex array, in bytes.
			@param format The vertex format. Use definitions prefixed with ONYX_VERTEX_FORMAT.
			@param heap Whether the first argument is on the heap or not.
			This is important for freeing the memory when the vertex array is used by a mesh.
		 */
		VertexArray(float* vertices, ushort size, int format, bool heap);


		/*
			@brief Gets the vertex data of the vertex array.
			@return The vertex data of the vertex array.
		 */
		float* getVertices() const;

		/*
			@brief Gets the size of the vertex array.
			@return The size of the vertex array, in bytes.
		 */
		ushort getSize() const;

		/*
			@brief Gets the vertex format of the vertex array.
			@return The vertex format of the vertex array.
		 */
		int getFormat() const;

		/*
			@brief Gets whether the vertex data is on the heap or not.
			@return Whether the vertex data is on the heap or not.
		 */
		bool isOnHeap() const;

		/*
			@brief Sets the vertex data of the vertex array.
			@param vertices The new vertex data of the vertex array.
		 */
		void setVertices(float* vertices);

		/*
			@brief Sets the size of the vertex array.
			@param size The new size of the vertex array, in bytes.
		 */
		void setSize(ushort size);

		/*
			@brief Sets the vertex format of the vertex array.
			@param format The new vertex format of the vertex array.
		 */
		void setFormat(int format);

	private:
		float* vertices;
		ushort size;
		int format;
		bool heap;
	};
}
