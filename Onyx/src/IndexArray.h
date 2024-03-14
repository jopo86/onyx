#pragma once

#include "Core.h"

namespace Onyx
{
	class IndexArray
	{
	public:
		IndexArray();
		IndexArray(uint* indices, ushort size, bool heap);

		uint* getIndices();

		ushort getSize();

		bool isOnHeap();

		void setIndices(uint* indices);

		void setSize(ushort size);

	private:
		uint* indices;
		ushort size;
		bool heap;
	};
}
