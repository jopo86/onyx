#pragma once

#include <iostream>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Core.h"

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
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
			Use the static `Load` function to create a valid font.
		 */
		Font();

		/*
			@brief Loads a font from the specified TrueType font file and the specified size.
			@param ttfFilePath The path of the TrueType font file.
			@param size The size of the font.
			@param result A pointer to a boolean that will be set to true if the font was loaded successfully, and false otherwise.
			@return The font.
		 */
		static Font Load(const std::string& ttfFilePath, uint size, bool* result = nullptr);

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
			@brief Destroys the object, freeing any used memory.
			Do not use the object after this is called.
		 */
		void dispose() override;

	private:
		FT_Library* m_pFreeType;
		FT_Face m_face;

		std::string m_ttfFilePath;
		uint m_size;

		std::map<char, Glyph> m_glyphs;
	};
}
