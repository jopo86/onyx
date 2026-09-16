#pragma warning(disable: 4244)

#include "char_renderable.h"

#include <glad/glad.h>

onyx::CharRenderable::CharRenderable()
{
	this->char_ = 0;
	this->vao = this->vbo = this->tex = 0;
}

onyx::CharRenderable::CharRenderable(char c, const Font& font, u32 advance)
{
	this->char_ = c;
	this->vao = this->vbo = this->tex = 0;
	Glyph glyph = font[c];
	this->tex = glyph.tex;

	float x = glyph.bearing_x + (int)advance;
	float y = glyph.bearing_y - glyph.height;
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

	glGenVertexArrays(1, &this->vao);
	glGenBuffers(1, &this->vbo);

	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::CharRenderable::render()
{
	glBindTexture(GL_TEXTURE_2D, this->tex);
	glBindVertexArray(this->vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

char onyx::CharRenderable::get_char() const
{
	return this->char_;
}

u32 onyx::CharRenderable::get_vao() const
{
	return this->vao;
}

u32 onyx::CharRenderable::get_vbo() const
{
	return this->vbo;
}

u32 onyx::CharRenderable::get_texture_id() const
{
	return this->tex;
}

void onyx::CharRenderable::dispose()
{
	if (this->disposed) return;
	if (this->vao) glDeleteVertexArrays(1, &this->vao);
	if (this->vbo) glDeleteBuffers(1, &this->vbo);
	this->vao = this->vbo = this->tex = 0;
	this->disposed = true;

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}
