#pragma warning(disable: 26495; disable: 4838)

#include "Font.h"

Onyx::Font::Font()
{
	p_ft = Onyx::GetFreeTypeLibrary();

	ttfFilePath = Onyx::GetResourcePath() + "fonts/Roboto/Roboto-Regular.ttf";
	size = 16;

	populateGlyphs();
}

Onyx::Font::Font(uint size)
{
	p_ft = Onyx::GetFreeTypeLibrary();

	ttfFilePath = Onyx::GetResourcePath() + "fonts/Roboto/Roboto-Regular.ttf";
	this->size = size;

	populateGlyphs();
}

Onyx::Font::Font(std::string ttfFilePath, uint size)
{
	p_ft = Onyx::GetFreeTypeLibrary();

	std::ifstream file(ttfFilePath);
	if (!file.good())
	{
		Err("Font file not found: \"" + ttfFilePath + "\"\nAborting font creation.");
		file.close();
		return;
	}

	file.close();

	this->ttfFilePath = ttfFilePath;
	this->size = size;

	populateGlyphs();
}

void Onyx::Font::populateGlyphs()
{
	if (FT_New_Face(*p_ft, ttfFilePath.c_str(), 0, &face))
	{
		Err("Failed to load font: \"" + ttfFilePath + "\"");
		return;
	}

	FT_Set_Pixel_Sizes(face, 0, size);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (ubyte c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			Err("Failed to load glyph for character '" + std::to_string(c) + "'");
			continue;
		}

		uint tex;
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0, GL_RED, GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Glyph info = {
			tex, face->glyph->bitmap.width, face->glyph->bitmap.rows,
			face->glyph->bitmap_left, face->glyph->bitmap_top,
			static_cast<uint>(face->glyph->advance.x)
		};

		glyphs.insert(std::pair<char, Glyph>(c, info));
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}

std::string Onyx::Font::getTtfFilePath()
{
	return ttfFilePath;
}

uint Onyx::Font::getSize()
{
	return size;
}

std::map<char, Onyx::Glyph> Onyx::Font::getGlyphs()
{
	return glyphs;
}

Onyx::Glyph& Onyx::Font::operator[](char c)
{
	return glyphs.at(c);
}

void Onyx::Font::dispose()
{
	FT_Done_Face(face);
}
