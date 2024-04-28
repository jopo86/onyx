#pragma warning(disable: 4244)

#include "CharRenderable.h"

#include <glad/glad.h>

Onyx::CharRenderable::CharRenderable()
{
	m_char = 0;
	m_vao = m_vbo = m_tex = 0;
}

Onyx::CharRenderable::CharRenderable(char c, const Font& font, uint advance)
{
	m_char = c;
	m_vao = m_vbo = m_tex = 0;
	Glyph glyph = font[c];
	m_tex = glyph.tex;

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

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::CharRenderable::render()
{
	glBindTexture(GL_TEXTURE_2D, m_tex);
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

char Onyx::CharRenderable::getChar() const
{
	return m_char;
}

uint Onyx::CharRenderable::getVAO() const
{
	return m_vao;
}

uint Onyx::CharRenderable::getVBO() const
{
	return m_vbo;
}

uint Onyx::CharRenderable::getTextureID() const
{
	return m_tex;
}

void Onyx::CharRenderable::dispose()
{
	if (m_vao) glDeleteVertexArrays(1, &m_vao);
	if (m_vbo) glDeleteBuffers(1, &m_vbo);
	m_vao = m_vbo = m_tex = 0;

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
