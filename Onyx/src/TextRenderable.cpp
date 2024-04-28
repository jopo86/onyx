#include "TextRenderable.h"

#include "Shader.h"

bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::TextRenderable::TextRenderable()
{
	m_pFont = nullptr;
	m_hidden = false;
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
}

Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)
{
	m_pFont = &font;
	m_hidden = false;
	m_text = text;
	m_color = Vec4(color, 1.0f);
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);

	if (!onyx_is_ehandler_nullptr())
	{
		if (font.getGlyphs().size() == 0)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
					.message = "Font has no glyphs loaded.",
					.howToFix = "Load a font from a TTF file before creating a TextRenderable with it."
				}
			);
			return;
		}
		if (text == "")
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
					.message = "Text is empty.",
					.howToFix = "Provide a non-empty string to render.",
					.severity = Warning::Severity::Low
				}
			);
		}
	}

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		m_chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}

	m_shader = Shader::UI_Text();
	m_shader.use();
	m_shader.setVec4("u_color", m_color);
}

Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)
{
	m_pFont = &font;
	m_hidden = false;
	m_text = text;
	m_color = color;
	m_model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);

	if (!onyx_is_ehandler_nullptr())
	{
		if (font.getGlyphs().size() == 0)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
					.message = "Font has no glyphs loaded.",
					.howToFix = "Load a font from a TTF file before creating a TextRenderable with it."
				}
			);
			return;
		}
		if (text == "")
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
					.message = "Text is empty.",
					.howToFix = "Provide a non-empty string to render.",
					.severity = Warning::Severity::Low
				}
			);
		}
		if (color.getW() == 0.0f)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)",
					.message = "Alpha value of text color is 0, text will not be visible.",
					.howToFix = "Change the alpha value to be between 0 and 1, reflecting the text's opacity.",
					.severity = Warning::Severity::Low
				}
			);
		}
	}

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		m_chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}

	m_shader = Shader::UI_Text();
	m_shader.use();
	m_shader.setVec4("u_color", color);
}

void Onyx::TextRenderable::render()
{
	if (m_hidden) return;
	m_shader.use();
	m_shader.setMat4("u_model", m_model);
	for (CharRenderable& c : m_chars) c.render();
}

void Onyx::TextRenderable::render(Mat4 ortho)
{
	if (m_hidden) return;
	m_shader.use();
	m_shader.setMat4("u_model", m_model);
	m_shader.setMat4("u_projection", ortho);
	for (CharRenderable& c : m_chars) c.render();
}

void Onyx::TextRenderable::hide()
{
	m_hidden = true;
}

void Onyx::TextRenderable::show()
{
	m_hidden = false;
}

void Onyx::TextRenderable::toggleVisibility()
{
	m_hidden = !m_hidden;
}

const Onyx::Math::Vec2& Onyx::TextRenderable::getPosition() const
{
	return m_position;
}

float Onyx::TextRenderable::getRotation() const
{
	return m_rotation;
}

const Onyx::Math::Vec2& Onyx::TextRenderable::getScale() const
{
	return m_scale;
}

const std::string& Onyx::TextRenderable::getText() const
{
	return m_text;
}

const Onyx::Font& Onyx::TextRenderable::getFont() const
{
	return *m_pFont;
}

const Vec4& Onyx::TextRenderable::getColor() const
{
	return m_color;
}

bool Onyx::TextRenderable::isHidden() const
{
	return m_hidden;
}

void Onyx::TextRenderable::setText(const std::string& text)
{
	m_text = text;
	for (CharRenderable& c : m_chars) c.dispose();
	m_chars.clear();
	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		m_chars.push_back(CharRenderable(text[i], *m_pFont, advance));
		advance += (*m_pFont)[text[i]].advance >> 6;
	}
}

void Onyx::TextRenderable::setFont(Font& font)
{
	m_pFont = &font;
	for (CharRenderable& c : m_chars) c.dispose();
	m_chars.clear();
	uint advance = 0;
	for (int i = 0; i < m_text.size(); i++)
	{
		m_chars.push_back(CharRenderable(m_text[i], font, advance));
		advance += font[m_text[i]].advance >> 6;
	}
}

void Onyx::TextRenderable::setColor(Vec3 color)
{
	m_color = Vec4(color, 1.0f);
	m_shader.use();
	m_shader.setVec4("u_color", m_color);
}

void Onyx::TextRenderable::setColor(Vec4 color)
{
	m_color = color;
	m_shader.use();
	m_shader.setVec4("u_color", m_color);
}

void Onyx::TextRenderable::setPosition(const Vec2& position)
{
	m_position = position;
	updateModel();
}

void Onyx::TextRenderable::setRotation(float rotation)
{
	m_rotation = rotation;
	updateModel();
}

void Onyx::TextRenderable::setScale(const Vec2& scale)
{
	m_scale = scale;
	updateModel();
}

void Onyx::TextRenderable::translate(const Vec2& translation)
{
	m_position += translation;
	updateModel();
}

void Onyx::TextRenderable::translateLocal(const Vec2& translation)
{
	translate(Math::Rotate(translation, m_rotation));
}

void Onyx::TextRenderable::rotate(float rotation)
{
	m_rotation += rotation;
	updateModel();
}

void Onyx::TextRenderable::scale(const Vec2& scalars)
{
	m_scale.setX(m_scale.getX() * scalars.getX());
	m_scale.setY(m_scale.getY() * scalars.getY());
	updateModel();
}

void Onyx::TextRenderable::scale(float scalar)
{
	m_scale.setX(m_scale.getX() * scalar);
	m_scale.setY(m_scale.getY() * scalar);
	updateModel();
}

void Onyx::TextRenderable::resetTransform()
{
	m_model = Mat4::Identity();
}

void Onyx::TextRenderable::dispose()
{
	for (CharRenderable& c : m_chars) c.dispose();
	m_chars.clear();
	m_shader.dispose();
	m_pFont = nullptr;
}

void Onyx::TextRenderable::updateModel()
{
	m_model = Mat4::Identity();
	m_model.translate(Vec3(m_position, 0.0f));
	m_model.rotate(m_rotation, Vec3(0.0f, 0.0f, 1.0f));
	m_model.scale(Vec3(m_scale, 1.0f));
}
