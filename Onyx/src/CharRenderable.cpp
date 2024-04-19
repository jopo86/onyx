#pragma warning(disable: 4244)

#include "CharRenderable.h"

#include <glad/glad.h>

Onyx::CharRenderable::CharRenderable()
{
	c = 0;
	vao = vbo = tex = 0;
}

Onyx::CharRenderable::CharRenderable(char c, const Font& font, uint advance)
{
	this->c = c;
	vao = vbo = tex = 0;
	Glyph glyph = font[c];
	tex = glyph.tex;

	float x = glyph.bearingX + advance;
	float y = glyph.bearingY - glyph.height;
	float w = glyph.width;
	float h = glyph.height;

	float vertices[6][4] = {
		{ x,     y + h,   0.0f, 0.0f },
		{ x,     y,       0.0f, 1.0f },
		{ x + w, y,       1.0f, 1.0f },

		{ x,     y + h,   0.0f, 0.0f },
		{ x + w, y,       1.0f, 1.0f },
		{ x + w, y + h,   1.0f, 0.0f }
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Onyx::CharRenderable::render()
{
	glBindTexture(GL_TEXTURE_2D, tex);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

char Onyx::CharRenderable::getChar() const
{
	return c;
}

uint Onyx::CharRenderable::getVAO() const
{
	return vao;
}

uint Onyx::CharRenderable::getVBO() const
{
	return vbo;
}

uint Onyx::CharRenderable::getTextureID() const
{
	return tex;
}

void Onyx::CharRenderable::dispose()
{
	if (vao) glDeleteVertexArrays(1, &vao);
	if (vbo) glDeleteBuffers(1, &vbo);
	vao = vbo = tex = 0;
}
