#include "TextRenderable3D.h"

#include "Shader.h"

void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::TextRenderable3D::TextRenderable3D()
{
	m_pFont = nullptr;
	m_hidden = false;
	m_model = Mat4::Identity();
	m_scale = Vec3(1.0f);
}

Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color, bool* result)
{
	m_pFont = &font;
	m_hidden = false;
	m_text = text;
	m_color = Vec4(color, 1.0f);
	m_model = Mat4::Identity();
	m_scale = Vec3(1.0f);

	if (font.getGlyphs().size() == 0)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
				.message = "Font has no glyphs loaded.",
				.howToFix = "Load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	if (text == "")
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
				.message = "Text is empty.",
				.howToFix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		m_chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}

	m_shader = Shader::Text();
	m_shader.use();
	m_shader.setVec4("u_color", m_color);

	if (result != nullptr) *result = true;
}

Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color, bool* result)
{
	m_pFont = &font;
	m_hidden = false;
	m_text = text;
	m_color = color;
	m_model = Mat4::Identity();
	m_scale = Vec3(1.0f);

	if (font.getGlyphs().size() == 0)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
				.message = "Font has no glyphs loaded.",
				.howToFix = "Load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	if (text == "")
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
				.message = "Text is empty.",
				.howToFix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}
	if (color.getW() == 0.0f)
	{
		onyx_warn(Warning{
				.sourceFunction = "Onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color)",
				.message = "Alpha value of text color is 0, text will not be visible.",
				.howToFix = "Change the alpha value to be between 0 and 1, reflecting the text's opacity.",
				.severity = Warning::Severity::Low
			}
		);
	}

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		m_chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}

	m_shader = Shader::Text();
	m_shader.use();
	m_shader.setVec4("u_color", color);
	if (result != nullptr) *result = true;
}

void Onyx::TextRenderable3D::render()
{
	if (m_hidden) return;
	m_shader.use();
	m_shader.setMat4("u_model", m_model);
	for (CharRenderable& c : m_chars) c.render();
}

void Onyx::TextRenderable3D::render(const Mat4& view, const Mat4& proj, const Vec3& camPos)
{
	if (m_hidden) return;
	m_shader.use();
	m_shader.setMat4("u_model", m_model);
	m_shader.setMat4("u_view", view);
	m_shader.setMat4("u_projection", proj);
	m_shader.setVec3("u_camPos", camPos);
	for (CharRenderable& c : m_chars) c.render();
}

void Onyx::TextRenderable3D::hide()
{
	m_hidden = true;
}

void Onyx::TextRenderable3D::show()
{
	m_hidden = false;
}

Onyx::Math::Vec2 Onyx::TextRenderable3D::dimensions() const
{
	Math::IVec2 strDims = m_pFont->getStringDimensions(m_text);
	return Math::Vec2(strDims.getX() * m_scale.getX(), strDims.getY() * m_scale.getY());
}

void Onyx::TextRenderable3D::toggleVisibility()
{
	m_hidden = !m_hidden;
}

const Vec3& Onyx::TextRenderable3D::getPosition() const
{
	return m_position;
}

const Vec3& Onyx::TextRenderable3D::getRotation() const
{
	return m_rotation;
}

const Vec3& Onyx::TextRenderable3D::getScale() const
{
	return m_scale;
}

const std::string& Onyx::TextRenderable3D::getText() const
{
	return m_text;
}

const Onyx::Font& Onyx::TextRenderable3D::getFont() const
{
	return *m_pFont;
}

const Vec4& Onyx::TextRenderable3D::getColor() const
{
	return m_color;
}

bool Onyx::TextRenderable3D::isHidden() const
{
	return m_hidden;
}

Onyx::Shader* Onyx::TextRenderable3D::getShader()
{
	return &m_shader;
}

void Onyx::TextRenderable3D::setText(const std::string& text)
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

void Onyx::TextRenderable3D::setFont(Font& font)
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

void Onyx::TextRenderable3D::setColor(Vec3 color)
{
	m_color = Vec4(color, 1.0f);
	m_shader.use();
	m_shader.setVec4("u_color", m_color);
}

void Onyx::TextRenderable3D::setColor(Vec4 color)
{
	m_color = color;
	m_shader.use();
	m_shader.setVec4("u_color", m_color);
}

void Onyx::TextRenderable3D::setPosition(const Vec3& position)
{
	m_position = position;
	updateModel();
}

void Onyx::TextRenderable3D::setRotation(const Vec3& rotations)
{
	m_rotation = rotations;
	updateModel();
}

void Onyx::TextRenderable3D::setScale(const Vec3& scales)
{
	m_scale = scales;
	updateModel();
}

void Onyx::TextRenderable3D::translate(const Vec3& translation)
{
	m_position += translation;
	updateModel();
}

void Onyx::TextRenderable3D::translateLocal(const Vec3& translation)
{
	translate(Math::Rotate(translation, m_rotation));
}

void Onyx::TextRenderable3D::rotate(const Vec3& rotations)
{
	m_rotation += rotations;
	updateModel();
}

void Onyx::TextRenderable3D::rotate(const Vec3& rotations, const Vec3& origin)
{
	Vec3 diff = m_position - origin;
	translate(-diff);
	rotate(rotations);
	diff = Math::Rotate(diff, rotations);
	translate(diff);
}

void Onyx::TextRenderable3D::scale(const Vec3& scalars)
{
	m_scale.setX(m_scale.getX() * scalars.getX());
	m_scale.setY(m_scale.getY() * scalars.getY());
	m_scale.setZ(m_scale.getZ() * scalars.getZ());
	updateModel();
}

void Onyx::TextRenderable3D::scale(float scalar)
{
	m_scale.setX(m_scale.getX() * scalar);
	m_scale.setY(m_scale.getY() * scalar);
	m_scale.setZ(m_scale.getZ() * scalar);
	updateModel();
}

void Onyx::TextRenderable3D::resetTransform()
{
	m_position = Vec3(0.0f);
	m_rotation = Vec3(0.0f);
	m_scale = Vec3(1.0f);
	updateModel();
}

void Onyx::TextRenderable3D::dispose()
{
	for (CharRenderable& c : m_chars) c.dispose();
	m_chars.clear();
	m_shader.dispose();
	m_pFont = nullptr;
}

void Onyx::TextRenderable3D::updateModel()
{
	m_model = Mat4::Identity();
	m_model.translate(m_position);
	m_model.rotate(m_rotation.getX(), Vec3(1.0f, 0.0f, 0.0f));
	m_model.rotate(m_rotation.getY(), Vec3(0.0f, 1.0f, 0.0f));
	m_model.rotate(m_rotation.getZ(), Vec3(0.0f, 0.0f, 1.0f));
	m_model.scale(m_scale);
}
