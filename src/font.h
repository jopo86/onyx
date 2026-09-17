#pragma once

#include <iostream>
#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "core.h"
#include "math_wrappers.h"

namespace onyx
{

	/*
		@brief A struct to represent a glyph/character in a font.
	 */
	struct Glyph
	{
		/*
			@brief The texture ID of the glyph.
		 */
		u32 tex;

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
		int bearing_x;

		/*
			@brief The bearing of the glyph on the y-axis.
		 */
		int bearing_y;

		/*
			@brief The advance of the glyph.
		 */
		u32 advance;
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
			Use the static `load` function to create a valid font.
		 */
		Font();

		/*
			@brief Loads a font from the specified TrueType font file and the specified size.
			@param ttf_file_path The path of the TrueType font file.
			@param size The size of the font.
			@param result A pointer to a boolean that will be set to true if the font was loaded successfully, and false otherwise.
			@return The font.
		 */
		static Font load(const std::string& ttf_file_path, u32 size, bool* result = nullptr);

		/*
			@brief Gets the dimensions of a string if it were to be rendered with this font.
			See get_string_width() and get_string_height() for specific information.
			@param str The string.
			@return The dimensions (width and height) of the string.
		 */
		math::IVec2 get_string_dimensions(const std::string& str) const;

		/*
			@brief Gets the width of a string if it were to be rendered with this font.
			Specifically, this function sums up the advances of each character in the string excluding the last character, and then adds the width of the last character.
			@param str The string.
			@return The width of the string.
		 */
		int get_string_width(const std::string& str) const;

		/*
			@brief Gets the height of a string if it were to be rendered with this font.
			Specifically, this function returns the height of the tallest character in the string.
			@param str The string.
			@return The height of the string.
		 */
		int get_string_height(const std::string& str) const;

		/*
			@brief Gets the path of the TrueType font file.
			@return The path of the TrueType font file.
		 */
		std::string get_ttf_file_path() const;

		/*
			@brief Gets the size of the font.
			@return The size of the font, in pixels.
		 */
		u32 get_size() const;

		/*
			@brief Gets the glyphs of the font.
			@return A map of characters and their corresponding glyphs.
		 */
		std::map<char, Glyph> get_glyphs() const;

		/*
			@brief Gets the glyph of the specified character.
			@param c The character.
			@return The glyph of the character.
		 */
		const Glyph& operator[](char c) const;

		void dispose() override;

	private:
		FT_Library* p_free_type;
		FT_Face face;

		std::string ttf_file_path;
		u32 size;

		std::map<char, Glyph> glyphs;
	};
}
