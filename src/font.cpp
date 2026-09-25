#include <onyx/font.hpp>

#include <algorithm>
#include <string>
#include <fstream>
#include <glad/glad.h>
#include "internal.hpp"

onyx::Font::Font()
{
	this->p_free_type = nullptr;
	this->face = nullptr;
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
		return Font();
	}

	FT_Set_Pixel_Sizes(font.face, 0, size);

	GLint prev_unpack_alignment = 4;
	glGetIntegerv(GL_UNPACK_ALIGNMENT, &prev_unpack_alignment);
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

			glBindTexture(GL_TEXTURE_2D, 0);
			glPixelStorei(GL_UNPACK_ALIGNMENT, prev_unpack_alignment);
			for (const std::pair<const char, Glyph>& g : font.glyphs)
			{
				if (g.second.tex) glDeleteTextures(1, &g.second.tex);
			}
			FT_Done_Face(font.face);

			if (result != nullptr) *result = false;
			return Font();
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
			.width = static_cast<int>(font.face->glyph->bitmap.width),
			.height = static_cast<int>(font.face->glyph->bitmap.rows),
			.bearing_x = font.face->glyph->bitmap_left,
			.bearing_y = font.face->glyph->bitmap_top,
			.advance = static_cast<u32>(font.face->glyph->advance.x)
		};

		font.glyphs.insert(std::pair<char, Glyph>(static_cast<char>(c), glyph));
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, prev_unpack_alignment);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif

	if (result != nullptr) *result = true;
	return font;
}

onyx::math::IVec2 onyx::Font::get_string_dimensions(const std::string& str) const
{
	return math::IVec2(get_string_width(str), get_string_height(str));
}

int onyx::Font::get_string_width(const std::string& str) const
{
	int width = 0;
	const Glyph* p_last = nullptr;

	for (char c : str)
	{
		const Glyph* p_glyph = get_glyph(c);
		if (p_glyph == nullptr) continue;
		width += p_glyph->advance >> 6;
		p_last = p_glyph;
	}

	if (p_last == nullptr) return 0;
	return width - static_cast<int>(p_last->advance >> 6) + p_last->bearing_x + p_last->width;
}

int onyx::Font::get_string_height(const std::string& str) const
{
	bool found = false;
	int top = 0;
	int bottom = 0;

	for (char c : str)
	{
		const Glyph* p_glyph = get_glyph(c);
		if (p_glyph == nullptr || p_glyph->height == 0) continue;
		int glyph_top = p_glyph->bearing_y;
		int glyph_bottom = p_glyph->bearing_y - p_glyph->height;
		if (!found)
		{
			top = glyph_top;
			bottom = glyph_bottom;
			found = true;
		}
		else
		{
			top = std::max(top, glyph_top);
			bottom = std::min(bottom, glyph_bottom);
		}
	}

	return top - bottom;
}

std::string onyx::Font::get_ttf_file_path() const
{
	return this->ttf_file_path;
}

u32 onyx::Font::get_size() const
{
	return this->size;
}

const std::map<char, onyx::Glyph>& onyx::Font::get_glyphs() const
{
	return this->glyphs;
}

const onyx::Glyph* onyx::Font::get_glyph(char c) const
{
	std::map<char, Glyph>::const_iterator it = this->glyphs.find(c);
	if (it != this->glyphs.end()) return &it->second;
	it = this->glyphs.find('?');
	if (it != this->glyphs.end()) return &it->second;
	return nullptr;
}

const onyx::Glyph& onyx::Font::operator[](char c) const
{
	static const Glyph empty_glyph = {};
	const Glyph* p_glyph = get_glyph(c);
	return p_glyph != nullptr ? *p_glyph : empty_glyph;
}

void onyx::Font::dispose()
{
	if (this->disposed) return;
	for (const std::pair<const char, Glyph>& g : this->glyphs)
	{
		if (g.second.tex) glDeleteTextures(1, &g.second.tex);
	}

#if defined(ONYX_GL_DEBUG_HIGH)
		GL_CHECK_ERROR();
#endif

	this->glyphs.clear();
	if (this->face != nullptr) FT_Done_Face(this->face);
	this->face = nullptr;
	this->p_free_type = nullptr;
	this->ttf_file_path = "";
	this->size = 0;
	this->disposed = true;
}
