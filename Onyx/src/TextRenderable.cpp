#include "TextRenderable.h"

#include "Shader.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::TextRenderable::TextRenderable()
{
	font = nullptr;
	hidden = false;
	model = Mat4::Identity();
}

Onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)
{
	this->font = &font;
	hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	model = Mat4::Identity();

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

void Onyx::TextRenderable::translate(Vec2 xy)
{
	if (xy.isZero()) return;
	model.translate(Vec3(xy, 0.0f));
}

void Onyx::TextRenderable::rotate(float degrees)
{
	if (degrees == 0.0f) return;
	model.rotate(degrees, Vec3(0.0f, 0.0f, 1.0f));
}

void Onyx::TextRenderable::scale(float scalar)
{
	if (scalar == 1.0f) return;
	model.scale(Vec3(scalar, scalar, 1.0f));
}

void Onyx::TextRenderable::scale(Vec2 xyScalar)
{
	if (xyScalar.getX() == 1.0f && xyScalar.getY() == 1.0f) return;
	model.scale(Vec3(xyScalar, 1.0f));
}

void Onyx::TextRenderable::resetTransform()
{
	model = Mat4::Identity();
}

void Onyx::TextRenderable::setText(const std::string& text)
{
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

void Onyx::TextRenderable::dispose()
{
	for (CharRenderable& c : chars) c.dispose();
	shader.dispose();
	font = nullptr;
}
