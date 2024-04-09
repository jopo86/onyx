#pragma warning(disable: 4244)

#include "TextRenderer.h"

using Onyx::Math::Mat4;

bool Onyx::TextRenderer::wireframe = false;

Onyx::TextRenderer::TextRenderer() 
{
	vao = vbo = 0;
}

Onyx::TextRenderer::TextRenderer(Window& window)
{
	window.p_textRenderer = this;

	shader = Shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Text.vert")),
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Text.frag"))
	);
	Projection proj = Projection::Orthographic(0.0f, window.getBufferWidth(), window.getBufferHeight(), 0.0f);
	shader.use();
	shader.setMat4("u_projection", proj.getMatrix());

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Onyx::TextRenderer::render(const std::string& text, Onyx::Math::Vec2 pos, Onyx::Math::Vec3 color)
{
	shader.use();
	shader.setVec3("u_textColor", color);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(vao);

	for (char c : text)
	{
		Glyph glyph = font[c];

		float x = pos.getX() + glyph.bearingX;
		float y = pos.getY() - glyph.height + glyph.bearingY;
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

		glBindTexture(GL_TEXTURE_2D, glyph.tex);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		pos.setX(pos.getX() + (glyph.advance >> 6));
	}
}

void Onyx::TextRenderer::render(const std::string& text, Onyx::Math::Vec2 pos, float scale, Onyx::Math::Vec3 color)
{
	shader.use();
	shader.setVec3("u_textColor", color);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(vao);

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Glyph glyph = font[*c];

		float x = pos.getX() + glyph.bearingX * scale;
		float y = pos.getY() - (glyph.height - glyph.bearingY) * scale;
		float w = glyph.width * scale;
		float h = glyph.height * scale;

		float vertices[6][4] = {
			{ x,     y + h,   0.0f, 0.0f },
			{ x,     y,       0.0f, 1.0f },
			{ x + w, y,       1.0f, 1.0f },

			{ x,     y + h,   0.0f, 0.0f },
			{ x + w, y,       1.0f, 1.0f },
			{ x + w, y + h,   1.0f, 0.0f }
		};

		glBindTexture(GL_TEXTURE_2D, glyph.tex);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		pos.setX(pos.getX() + (glyph.advance >> 6) * scale);
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Onyx::TextRenderer::StartRender()
{
	glDisable(GL_DEPTH_TEST);
	wireframe = Renderer::IsWireframe();
	Renderer::SetWireframe(false);
}

void Onyx::TextRenderer::EndRender()
{
	glEnable(GL_DEPTH_TEST);
	Renderer::SetWireframe(wireframe);
}

uint Onyx::TextRenderer::getVAO() const
{
	return vao;
}

uint Onyx::TextRenderer::getVBO() const
{
	return vbo;
}

const Onyx::Font* Onyx::TextRenderer::getFont() const
{
	return &font;
}

void Onyx::TextRenderer::setFont(Font& font)
{
	this->font = font;
}
