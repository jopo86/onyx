#include <onyx/text_renderable.hpp>

#include <cmath>

#include <onyx/shader.hpp>
#include "internal.hpp"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::Mat4, onyx::math::IVec2;

onyx::TextRenderable::TextRenderable()
{
	this->p_font = nullptr;
	this->hidden = false;
	this->model = Mat4::identity();
	this->z = 0.0f;
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
}

onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, const Vec3& color, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	this->model = Mat4::identity();
	this->z = 0.0f;
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}

	u32 advance = 0;
	for (char c : text)
	{
		const Glyph* p_glyph = font.get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, font, advance));
		advance += p_glyph->advance >> 6;
	}

	this->shader = Shader::ui_text();
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);

	if (result != nullptr) *result = true;
}

onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, const Vec4& color, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = color;
	this->model = Mat4::identity();
	this->z = 0.0f;
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}
	if (color.get_w() == 0.0f)
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color)",
				.message = "Alpha value of text color is 0, text will not be visible.",
				.how_to_fix = "Change the alpha value to be between 0 and 1, reflecting the text's opacity.",
				.severity = Warning::Severity::Low
			}
		);
	}

	u32 advance = 0;
	for (char c : text)
	{
		const Glyph* p_glyph = font.get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, font, advance));
		advance += p_glyph->advance >> 6;
	}

	this->shader = Shader::ui_text();
	this->shader.use();
	this->shader.set_vec4("u_color", color);

	if (result != nullptr) *result = true;
}

onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, const Vec3& color, Shader shader_override, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	this->model = Mat4::identity();
	this->z = 0.0f;
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color, Shader shader_override)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec3 color, Shader shader_override)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}

	u32 advance = 0;
	for (char c : text)
	{
		const Glyph* p_glyph = font.get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, font, advance));
		advance += p_glyph->advance >> 6;
	}

	this->shader = shader_override;
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);

	if (result != nullptr) *result = true;
}

onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, const Vec4& color, Shader shader_override, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = color;
	this->model = Mat4::identity();
	this->z = 0.0f;
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}
	if (color.get_w() == 0.0f)
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable::TextRenderable(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
				.message = "Alpha value of text color is 0, text will not be visible.",
				.how_to_fix = "Change the alpha value to be between 0 and 1, reflecting the text's opacity.",
				.severity = Warning::Severity::Low
			}
		);
	}

	u32 advance = 0;
	for (char c : text)
	{
		const Glyph* p_glyph = font.get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, font, advance));
		advance += p_glyph->advance >> 6;
	}

	this->shader = shader_override;
	this->shader.use();
	this->shader.set_vec4("u_color", color);

	if (result != nullptr) *result = true;
}

void onyx::TextRenderable::render()
{
	if (this->hidden) return;
	this->shader.use();
	this->shader.set_mat4("u_model", this->model);
	for (CharRenderable& c : this->chars) c.render();
}

void onyx::TextRenderable::render(Mat4 ortho)
{
	if (this->hidden) return;
	this->shader.use();
	this->shader.set_mat4("u_model", this->model);
	this->shader.set_mat4("u_projection", ortho);
	for (CharRenderable& c : this->chars) c.render();
}

void onyx::TextRenderable::hide()
{
	this->hidden = true;
}

void onyx::TextRenderable::show()
{
	this->hidden = false;
}

void onyx::TextRenderable::toggle_visibility()
{
	this->hidden = !this->hidden;
}

const onyx::math::Vec2& onyx::TextRenderable::get_position() const
{
	return this->position;
}

float onyx::TextRenderable::get_rotation() const
{
	return this->rotation;
}

const onyx::math::Vec2& onyx::TextRenderable::get_scale() const
{
	return this->scale_;
}

const std::string& onyx::TextRenderable::get_text() const
{
	return this->text;
}

const onyx::Font& onyx::TextRenderable::get_font() const
{
	return *this->p_font;
}

const Vec4& onyx::TextRenderable::get_color() const
{
	return this->color;
}

const Vec2& onyx::TextRenderable::get_dimensions() const
{
	return this->dimensions_;
}

float onyx::TextRenderable::get_width() const
{
	return this->dimensions_.get_x();
}

float onyx::TextRenderable::get_height() const
{
	return this->dimensions_.get_y();
}

bool onyx::TextRenderable::is_hidden() const
{
	return this->hidden;
}

int onyx::TextRenderable::get_z_index() const
{
	return static_cast<int>(std::lround(this->z * 1000.0f));
}

void onyx::TextRenderable::set_text(const std::string& new_text)
{
	this->text = new_text;
	for (CharRenderable& c : this->chars) c.dispose();
	this->chars.clear();
	if (this->p_font == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable::set_text(const std::string& new_text)",
				.message = "Font pointer is null (the renderable was default-constructed or disposed).",
				.how_to_fix = "Set a font with set_font() before setting the text."
			}
		);
		update_dimensions();
		return;
	}
	u32 advance = 0;
	for (char c : new_text)
	{
		const Glyph* p_glyph = this->p_font->get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, *this->p_font, advance));
		advance += p_glyph->advance >> 6;
	}
	update_dimensions();
}

void onyx::TextRenderable::set_font(Font& font)
{
	this->p_font = &font;
	for (CharRenderable& c : this->chars) c.dispose();
	this->chars.clear();
	u32 advance = 0;
	for (char c : this->text)
	{
		const Glyph* p_glyph = font.get_glyph(c);
		if (p_glyph == nullptr) continue;
		this->chars.push_back(CharRenderable(c, font, advance));
		advance += p_glyph->advance >> 6;
	}
	update_dimensions();
}

void onyx::TextRenderable::set_color(Vec3 new_color)
{
	this->color = Vec4(new_color, 1.0f);
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);
}

void onyx::TextRenderable::set_color(Vec4 new_color)
{
	this->color = new_color;
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);
}

void onyx::TextRenderable::set_position(const Vec2& new_position)
{
	this->position = new_position;
	update_model();
}

void onyx::TextRenderable::set_rotation(float new_rotation)
{
	this->rotation = new_rotation;
	update_model();
}

void onyx::TextRenderable::set_scale(const Vec2& scale)
{
	this->scale_ = scale;
	update_dimensions();
	update_model();
}

void onyx::TextRenderable::translate(const Vec2& translation)
{
	this->position += translation;
	update_model();
}

void onyx::TextRenderable::translate_local(const Vec2& translation)
{
	translate(math::rotate(translation, this->rotation));
}

void onyx::TextRenderable::rotate(float angle)
{
	this->rotation += angle;
	update_model();
}

void onyx::TextRenderable::scale(const Vec2& scalars)
{
	this->scale_.set_x(this->scale_.get_x() * scalars.get_x());
	this->scale_.set_y(this->scale_.get_y() * scalars.get_y());
	this->dimensions_.set_x(this->dimensions_.get_x() * scalars.get_x());
	this->dimensions_.set_y(this->dimensions_.get_y() * scalars.get_y());
	update_model();
}

void onyx::TextRenderable::scale(float scalar)
{
	this->scale_.set_x(this->scale_.get_x() * scalar);
	this->scale_.set_y(this->scale_.get_y() * scalar);
	this->dimensions_ *= scalar;
	update_model();
}

void onyx::TextRenderable::reset_transform()
{
	this->position = Vec2(0.0f);
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	update_dimensions();
	update_model();
}

void onyx::TextRenderable::set_z_index(int z_index)
{
	this->z = z_index / 1000.0f;
	update_model();
}

void onyx::TextRenderable::dispose()
{
	if (this->disposed) return;
	for (CharRenderable& c : this->chars) c.dispose();
	this->chars.clear();
	this->shader.dispose();
	this->p_font = nullptr;
	this->disposed = true;
}

void onyx::TextRenderable::update_model()
{
	this->model = Mat4::identity();
	this->model.translate(Vec3(this->position, this->z));
	this->model.rotate(this->rotation, Vec3(0.0f, 0.0f, 1.0f));
	this->model.scale(Vec3(this->scale_, 1.0f));
}

void onyx::TextRenderable::update_dimensions()
{
	if (this->p_font == nullptr)
	{
		this->dimensions_ = Vec2(0.0f);
		return;
	}
	IVec2 dims = this->p_font->get_string_dimensions(this->text);
	this->dimensions_.set(dims.get_x() * this->scale_.get_x(), dims.get_y() * this->scale_.get_y());
}
