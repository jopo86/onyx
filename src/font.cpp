#pragma warning(disable: 26495; disable: 4838)

#include "font.h"

#include <string>
#include <fstream>
#include <glad/glad.h>

FT_Library* onyx_get_ft();
void onyx_err(const onyx::Error&);

onyx::Font::Font()
{
	this->p_free_type = nullptr;
	this->ttf_file_path = "";
	this->size = 0;
}

onyx::Font onyx::Font::load(const std::string& ttf_file_path, u32 size, bool* result)
{
	std::ifstream file(ttf_file_path);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Font::load(const std::string& ttf_file_path, u32 size)",
				.message = "File not found (or access denied): \"" + ttf_file_path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		if (result != nullptr) *result = false;
		return Font();
	}
	file.close();

	Font font;
	font.p_free_type = onyx_get_ft();
	font.ttf_file_path = ttf_file_path;
	font.size = size;
	
	if (FT_New_Face(*font.p_free_type, ttf_file_path.c_str(), 0, &font.face))
	{
		onyx_err(Error{
				.source_function = "onyx::Font::load(const std::string& ttf_file_path, u32 size)",
				.message = "Found file, but failed to load font: \"" + ttf_file_path + "\"",
				.how_to_fix = "Ensure the file is a valid TrueType font file."
			}
		);
		if (result != nullptr) *result = false;
		return font;
	}

	FT_Set_Pixel_Sizes(font.face, 0, size);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (u8 c = 0; c < 128; c++)
	{
		if (FT_Load_Char(font.face, c, FT_LOAD_RENDER))
		{
			onyx_err(Error{
					.source_function = "onyx::Font::load(const std::string& ttf_file_path, u32 size)",
					.message = "Failed to load glyph: '" + std::to_string(c) + "' from font: \"" + ttf_file_path + "\"",
					.how_to_fix = "Ensure the font file is a valid TrueType font file."
				}
			);
			if (result != nullptr) *result = false;
			return font;
		}

		u32 tex;
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RED,
			font.face->glyph->bitmap.width,
			font.face->glyph->bitmap.rows,
			0, GL_RED, GL_UNSIGNED_BYTE,
			font.face->glyph->bitmap.buffer
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Glyph glyph = {
			.tex = tex, 
			.width = abs((int)font.face->glyph->bitmap.width), 
			.height = abs((int)font.face->glyph->bitmap.rows),
			.bearing_x = font.face->glyph->bitmap_left, 
			.bearing_y = font.face->glyph->bitmap_top,
			.advance = static_cast<u32>(font.face->glyph->advance.x)
		};

		font.glyphs.insert(std::pair<char, Glyph>(c, glyph));
	}

	glBindTexture(GL_TEXTURE_2D, 0);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif

	if (result != nullptr) *result = true;
	return font;
}

onyx::math::IVec2 onyx::Font::get_string_dimensions(const std::string& str) const
{
	int width = 0;
	int height = 0;

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		Glyph glyph = this->glyphs.at(c);
		width += glyph.advance >> 6;
		height = std::max(height, glyph.height);
	}

	return math::IVec2(width, height);
}

int onyx::Font::get_string_width(const std::string& str) const
{
	int width = 0;

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		Glyph glyph = this->glyphs.at(c);
		width += glyph.advance >> 6;
	}

	return width;
}

int onyx::Font::get_string_height(const std::string& str) const
{
	int height = 0;

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		Glyph glyph = this->glyphs.at(c);
		height = std::max(height, glyph.height);
	}

	return height;
}

std::string onyx::Font::get_ttf_file_path() const
{
	return this->ttf_file_path;
}

u32 onyx::Font::get_size() const
{
	return this->size;
}

std::map<char, onyx::Glyph> onyx::Font::get_glyphs() const
{
	return this->glyphs;
}

const onyx::Glyph& onyx::Font::operator[](char c) const
{
	return this->glyphs.at(c);
}

void onyx::Font::dispose()
{
	if (this->disposed) return;
	for (const std::pair<char, Glyph>& g : this->glyphs)
	{
		if (g.second.tex) glDeleteTextures(1, &g.second.tex);
	}

#if defined(ONYX_GL_DEBUG_HIGH)
		GL_CHECK_ERROR();
#endif

	this->glyphs.clear();
	FT_Done_Face(this->face);
	this->p_free_type = nullptr;
	this->ttf_file_path = "";
	this->size = 0;
	this->disposed = true;
}
