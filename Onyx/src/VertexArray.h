#pragma once

#include "Core.h"

namespace Onyx
{
	class VertexArray
	{
	public:
		VertexArray();
		VertexArray(float* vertices, ushort size, int format, bool heap);

		float* getVertices();

		ushort getSize();

		int getFormat();

		bool isOnHeap();

		void setVertices(float* vertices);

		void setSize(ushort size);

		void setFormat(int format);

	private:
		float* vertices;
		ushort size;
		int format;
		bool heap;
	};
}
