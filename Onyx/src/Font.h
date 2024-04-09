#pragma once

#include <string>
#include <map>
#include <fstream>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <glad/glad.h>

#include "Core.h"
#include "Math.h"

namespace Onyx
{

	/*
		@brief A struct to represent a glyph/character in a font.
	 */
	struct Glyph
	{
		/*
			@brief The texture ID of the glyph.
		 */
		uint tex;

		/*
			@brief The width of the glyph.
		 */
		int width;

		/*
			@brief The height of the glyph.
		 */
		int height;

		/*
			@brief The bearing of the glyph on the x-axis.
		 */
		int bearingX;

		/*
			@brief The bearing of the glyph on the y-axis.
		 */
		int bearingY;

		/*
			@brief The advance of the glyph.
		 */
		uint advance;
	};

	/*
		@brief A class to represent a font.
	 */
	class Font : public Disposable
	{
	public:
		/*
			@brief Creates an empty font.
			Using a font constructued like this will result in undefined behavior.
			Use the static Load() function to load a font from a TrueType font file.
		 */
		Font();

		/*
			@brief Loads a font from the specified TrueType font file and the specified size.
			@param ttfFilePath The path of the TrueType font file.
			@param size The size of the font.
			@return The font.
		 */
		static Font Load(const std::string& ttfFilePath, uint size);

		/*
			@brief Gets the path of the TrueType font file.
			@return The path of the TrueType font file.
		 */
		std::string getTtfFilePath() const;

		/*
			@brief Gets the size of the font.
			@return The size of the font.
		 */
		uint getSize() const;

		/*
			@brief Gets the glyphs of the font.
			@return A map of characters and their corresponding glyphs.
		 */
		std::map<char, Glyph> getGlyphs() const;

		const Glyph& operator[](char c) const;

		/*
			@brief Disposes of the font.
		 */
		void dispose() override;

	private:
		FT_Library* p_ft;
		FT_Face face;

		std::string ttfFilePath;
		uint size;

		std::map<char, Glyph> glyphs;
	};
}
