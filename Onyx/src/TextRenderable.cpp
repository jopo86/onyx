#include "TextRenderable.h"

#include "Shader.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::TextRenderable::TextRenderable()
{
	font = nullptr;
	hidden = false;
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);
}

Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)
{
	this->font = &font;
	hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}

	shader = Shader::UI_Text();
	shader.use();
	shader.setVec4("u_color", this->color);
}

Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)
{
	this->font = &font;
	hidden = false;
	this->text = text;
	this->color = color;
	model = Mat4::Identity();
	m_rotation = 0.0f;
	m_scale = Vec2(1.0f);

	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
    {
        chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
    }

	shader = Shader::UI_Text();
	shader.use();
	shader.setVec4("u_color", color);
}

void Onyx::TextRenderable::render()
{
	if (hidden) return;
	shader.use();
	shader.setMat4("u_model", model);
	for (CharRenderable& c : chars) c.render();
}

void Onyx::TextRenderable::render(Mat4 ortho)
{
	if (hidden) return;
	shader.use();
	shader.setMat4("u_model", model);
	shader.setMat4("u_projection", ortho);
	for (CharRenderable& c : chars) c.render();
}

void Onyx::TextRenderable::hide()
{
	hidden = true;
}

void Onyx::TextRenderable::show()
{
	hidden = false;
}

void Onyx::TextRenderable::toggleVisibility()
{
	hidden = !hidden;
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
    return text;
}

const Onyx::Font& Onyx::TextRenderable::getFont() const
{
    return *font;
}

const Vec4& Onyx::TextRenderable::getColor() const
{
    return color;
}

bool Onyx::TextRenderable::isHidden() const
{
    return hidden;
}

void Onyx::TextRenderable::setText(const std::string& text)
{
	this->text = text;
	for (CharRenderable& c : chars) c.dispose();
	chars.clear();
	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		chars.push_back(CharRenderable(text[i], *font, advance));
		advance += (*font)[text[i]].advance >> 6;
	}
}

void Onyx::TextRenderable::setFont(Font& font)
{
	this->font = &font;
	for (CharRenderable& c : chars) c.dispose();
	chars.clear();
	uint advance = 0;
	for (int i = 0; i < text.size(); i++)
	{
		chars.push_back(CharRenderable(text[i], font, advance));
		advance += font[text[i]].advance >> 6;
	}
}

void Onyx::TextRenderable::setColor(Vec3 color)
{
	this->color = Vec4(color, 1.0f);
	shader.use();
	shader.setVec4("u_color", this->color);
}

void Onyx::TextRenderable::setColor(Vec4 color)
{
	this->color = color;
	shader.use();
	shader.setVec4("u_color", color);
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
	model = Mat4::Identity();
}

void Onyx::TextRenderable::dispose()
{
	for (CharRenderable& c : chars) c.dispose();
	chars.clear();
	shader.dispose();
	font = nullptr;
}

void Onyx::TextRenderable::updateModel()
{
	model = Mat4::Identity();
	model.translate(Vec3(m_position, 0.0f));
	model.rotate(m_rotation, Vec3(0.0f, 0.0f, 1.0f));
	model.scale(Vec3(m_scale, 1.0f));
}
