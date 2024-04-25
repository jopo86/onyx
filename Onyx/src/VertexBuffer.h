#pragma once

#include "Core.h"

namespace Onyx
{
	class VertexBuffer
	{
		friend class Mesh;
	public:
		/*
			@brief Creates an empty vertex array.
			Trying to use an vertex array constructed like this will result in undefined behavior.
		 */
		VertexBuffer();

		/*
			@brief Creates an vertex array with the given vertices.
			@param vertices The vertices to be used in the vertex array.
			@param size The size of the vertex array, in bytes.
			@param format The vertex format. Use definitions prefixed with ONYX_VERTEX_FORMAT.
		 */
		VertexBuffer(float* vertices, uint size, Onyx::VertexFormat format);

		static bool HasNormals(Onyx::VertexFormat format);

		static bool HasTextureCoords(Onyx::VertexFormat format);

		static bool HasColors(Onyx::VertexFormat format);

		static VertexBuffer Triangle(float side);

		static VertexBuffer Triangle(float base, float height);

		static VertexBuffer Square(float side);

		static VertexBuffer Quad(float width, float height);

		static VertexBuffer Cube(float side);

		static VertexBuffer RectPrism(float width, float height, float depth);

	private:
		float* vertices;
		uint size;
		Onyx::VertexFormat format;

		bool heap;
	};
}
