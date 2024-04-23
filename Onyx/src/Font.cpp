#pragma warning(disable: 26495; disable: 4838)

#include "Font.h"

#include <string>
#include <fstream>
#include <glad/glad.h>

FT_Library* onyx_get_ft();
bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);

Onyx::Font::Font()
{
	p_ft = nullptr;
	ttfFilePath = "";
	size = 0;
}

Onyx::Font Onyx::Font::Load(const std::string& ttfFilePath, uint size)
{
	std::ifstream file(ttfFilePath);
	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Font::Load(const std::string& ttfFilePath, uint size)",
				.message = "File not found (or access denied): \"" + ttfFilePath + "\"",
				.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		return Font();
	}
	file.close();

	Font font;
	font.p_ft = onyx_get_ft();
	font.ttfFilePath = ttfFilePath;
	font.size = size;
	
	if (FT_New_Face(*font.p_ft, ttfFilePath.c_str(), 0, &font.face))
	{
		if (!onyx_is_ehandler_nullptr()) onyx_err(Error{
				.sourceFunction = "Onyx::Font::Load(const std::string& ttfFilePath, uint size)",
                .message = "Found file, but failed to load font: \"" + ttfFilePath + "\"",
                .howToFix = "Ensure the file is a valid TrueType font file."
			}
		);
		return font;
	}

	FT_Set_Pixel_Sizes(font.face, 0, size);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (ubyte c = 0; c < 128; c++)
	{
		if (FT_Load_Char(font.face, c, FT_LOAD_RENDER))
		{
			if (!onyx_is_ehandler_nullptr()) onyx_err(Error{
				    .sourceFunction = "Onyx::Font::Load(const std::string& ttfFilePath, uint size)",
                    .message = "Failed to load glyph: '" + std::to_string(c) + "' from font: \"" + ttfFilePath + "\"",
                    .howToFix = "Ensure the font file is a valid TrueType font file."
                }
            );
			continue;
		}

		uint tex;
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
			tex, font.face->glyph->bitmap.width, font.face->glyph->bitmap.rows,
			font.face->glyph->bitmap_left, font.face->glyph->bitmap_top,
			static_cast<uint>(font.face->glyph->advance.x)
		};

		font.glyphs.insert(std::pair<char, Glyph>(c, glyph));
	}

	glBindTexture(GL_TEXTURE_2D, 0);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif

	return font;
}

std::string Onyx::Font::getTtfFilePath() const
{
	return ttfFilePath;
}

uint Onyx::Font::getSize() const
{
	return size;
}

std::map<char, Onyx::Glyph> Onyx::Font::getGlyphs() const
{
	return glyphs;
}

const Onyx::Glyph& Onyx::Font::operator[](char c) const
{
	return glyphs.at(c);
}

void Onyx::Font::dispose()
{
	for (const std::pair<char, Glyph>& g : glyphs)
	{
		if (g.second.tex) glDeleteTextures(1, &g.second.tex);
	}

#if defined(ONYX_GL_DEBUG_HIGH)
		glCheckError();
#endif

	glyphs.clear();
	FT_Done_Face(face);
	p_ft = nullptr;
	ttfFilePath = "";
	size = 0;
}
