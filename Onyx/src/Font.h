#pragma once

#include <string>
#include <map>
#include <fstream>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glad/glad.h>

#include "Core.h"
#include "ErrorHandler.h"
#include "Math.h"

namespace Onyx
{

	struct Glyph
	{
		uint tex;
		int width;
		int height;
		int bearingX;
		int bearingY;
		uint advance;
	};

	class Font : public Disposable
	{
	public:
		Font();
		Font(uint size);
		Font(std::string ttfFilePath, uint size);
		Font(std::string ttfFilePath, uint size, ErrorHandler& errorHandler);

		std::string getTtfFilePath();
		uint getSize();
		std::map<char, Glyph> getGlyphs();

		Glyph& operator[](char c);

		void dispose() override;

	private:
		FT_Library* p_ft;
		FT_Face face;

		std::string ttfFilePath;
		uint size;

		std::map<char, Glyph> glyphs;

		void populateGlyphs(ErrorHandler* errorHandler = nullptr);
	};
}
