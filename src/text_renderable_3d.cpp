#include <onyx/text_renderable_3d.hpp>
#include <onyx/shader.hpp>
#include "internal.hpp"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::Mat4, onyx::math::IVec2;

onyx::TextRenderable3D::TextRenderable3D()
{
	this->p_font = nullptr;
	this->hidden = false;
	this->model = Mat4::identity();
	this->scale_ = Vec3(1.0f);
}

onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, const Vec3& color, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	this->model = Mat4::identity();
	this->scale_ = Vec3(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color)",
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

	this->shader = Shader::text();
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);

	if (result != nullptr) *result = true;
}

onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, const Vec4& color, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = color;
	this->model = Mat4::identity();
	this->scale_ = Vec3(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}
	if (color.get_w() == 0.0f)
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color)",
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

	this->shader = Shader::text();
	this->shader.use();
	this->shader.set_vec4("u_color", color);
	if (result != nullptr) *result = true;
}

onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, const Vec3& color, Shader shader_override, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = Vec4(color, 1.0f);
	this->model = Mat4::identity();
	this->scale_ = Vec3(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color, Shader shader_override)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec3 color, Shader shader_override)",
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

onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, const Vec4& color, Shader shader_override, bool* result)
{
	this->p_font = &font;
	this->hidden = false;
	this->text = text;
	this->color = color;
	this->model = Mat4::identity();
	this->scale_ = Vec3(1.0f);

	if (font.get_glyphs().size() == 0)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
				.message = "Font has no glyphs loaded.",
				.how_to_fix = "load a font from a TTF file before creating a TextRenderable3D with it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}
	this->dimensions_ = font.get_string_dimensions(text);
	if (text == "")
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
				.message = "text is empty.",
				.how_to_fix = "Provide a non-empty string to render.",
				.severity = Warning::Severity::Low
			}
		);
	}
	if (color.get_w() == 0.0f)
	{
		onyx_warn(Warning{
				.source_function = "onyx::TextRenderable3D::TextRenderable3D(const std::string& text, Font& font, Vec4 color, Shader shader_override)",
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

void onyx::TextRenderable3D::render()
{
	if (this->hidden) return;
	this->shader.use();
	this->shader.set_mat4("u_model", this->model);
	for (CharRenderable& c : this->chars) c.render();
}

void onyx::TextRenderable3D::render(const Mat4& view, const Mat4& proj, const Vec3& cam_pos)
{
	if (this->hidden) return;
	this->shader.use();
	this->shader.set_mat4("u_model", this->model);
	this->shader.set_mat4("u_view", view);
	this->shader.set_mat4("u_projection", proj);
	this->shader.set_vec3("u_cam_pos", cam_pos);
	for (CharRenderable& c : this->chars) c.render();
}

void onyx::TextRenderable3D::hide()
{
	this->hidden = true;
}

void onyx::TextRenderable3D::show()
{
	this->hidden = false;
}

void onyx::TextRenderable3D::toggle_visibility()
{
	this->hidden = !this->hidden;
}

const Vec3& onyx::TextRenderable3D::get_position() const
{
	return this->position;
}

const Vec3& onyx::TextRenderable3D::get_rotation() const
{
	return this->rotation;
}

const Vec3& onyx::TextRenderable3D::get_scale() const
{
	return this->scale_;
}

const std::string& onyx::TextRenderable3D::get_text() const
{
	return this->text;
}

const onyx::Font& onyx::TextRenderable3D::get_font() const
{
	return *this->p_font;
}

const Vec4& onyx::TextRenderable3D::get_color() const
{
	return this->color;
}

const Vec2& onyx::TextRenderable3D::get_dimensions() const
{
	return this->dimensions_;
}

float onyx::TextRenderable3D::get_width() const
{
	return this->dimensions_.get_x();
}

float onyx::TextRenderable3D::get_height() const
{
	return this->dimensions_.get_y();
}

bool onyx::TextRenderable3D::is_hidden() const
{
	return this->hidden;
}

onyx::Shader* onyx::TextRenderable3D::get_shader()
{
	return &this->shader;
}

void onyx::TextRenderable3D::set_text(const std::string& new_text)
{
	this->text = new_text;
	for (CharRenderable& c : this->chars) c.dispose();
	this->chars.clear();
	if (this->p_font == nullptr)
	{
		onyx_err(Error{
				.source_function = "onyx::TextRenderable3D::set_text(const std::string& new_text)",
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

void onyx::TextRenderable3D::set_font(Font& font)
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

void onyx::TextRenderable3D::set_color(Vec3 new_color)
{
	this->color = Vec4(new_color, 1.0f);
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);
}

void onyx::TextRenderable3D::set_color(Vec4 new_color)
{
	this->color = new_color;
	this->shader.use();
	this->shader.set_vec4("u_color", this->color);
}

void onyx::TextRenderable3D::set_position(const Vec3& new_position)
{
	this->position = new_position;
	update_model();
}

void onyx::TextRenderable3D::set_rotation(const Vec3& rotations)
{
	this->rotation = rotations;
	update_model();
}

void onyx::TextRenderable3D::set_scale(const Vec3& scales)
{
	this->scale_ = scales;
	update_dimensions();
	update_model();
}

void onyx::TextRenderable3D::translate(const Vec3& translation)
{
	this->position += translation;
	update_model();
}

void onyx::TextRenderable3D::translate_local(const Vec3& translation)
{
	translate(math::rotate(translation, this->rotation));
}

void onyx::TextRenderable3D::rotate(const Vec3& rotations)
{
	this->rotation += rotations;
	update_model();
}

void onyx::TextRenderable3D::rotate(const Vec3& rotations, const Vec3& origin)
{
	Vec3 diff = this->position - origin;
	translate(-diff);
	rotate(rotations);
	diff = math::rotate(diff, rotations);
	translate(diff);
}

void onyx::TextRenderable3D::scale(const Vec3& scalars)
{
	this->scale_.set_x(this->scale_.get_x() * scalars.get_x());
	this->scale_.set_y(this->scale_.get_y() * scalars.get_y());
	this->scale_.set_z(this->scale_.get_z() * scalars.get_z());
	this->dimensions_.set_x(this->dimensions_.get_x() * scalars.get_x());
	this->dimensions_.set_y(this->dimensions_.get_y() * scalars.get_y());
	update_model();
}

void onyx::TextRenderable3D::scale(float scalar)
{
	this->scale_.set_x(this->scale_.get_x() * scalar);
	this->scale_.set_y(this->scale_.get_y() * scalar);
	this->scale_.set_z(this->scale_.get_z() * scalar);
	this->dimensions_ *= scalar;
	update_model();
}

void onyx::TextRenderable3D::reset_transform()
{
	this->position = Vec3(0.0f);
	this->rotation = Vec3(0.0f);
	this->scale_ = Vec3(1.0f);
	update_dimensions();
	update_model();
}

void onyx::TextRenderable3D::dispose()
{
	if (this->disposed) return;
	for (CharRenderable& c : this->chars) c.dispose();
	this->chars.clear();
	this->shader.dispose();
	this->p_font = nullptr;
	this->disposed = true;
}

void onyx::TextRenderable3D::update_model()
{
	this->model = Mat4::identity();
	this->model.translate(this->position);
	this->model.rotate(this->rotation.get_x(), Vec3(1.0f, 0.0f, 0.0f));
	this->model.rotate(this->rotation.get_y(), Vec3(0.0f, 1.0f, 0.0f));
	this->model.rotate(this->rotation.get_z(), Vec3(0.0f, 0.0f, 1.0f));
	this->model.scale(this->scale_);
}

void onyx::TextRenderable3D::update_dimensions()
{
	if (this->p_font == nullptr)
	{
		this->dimensions_ = Vec2(0.0f);
		return;
	}
	IVec2 dims = this->p_font->get_string_dimensions(this->text);
	this->dimensions_.set(dims.get_x() * this->scale_.get_x(), dims.get_y() * this->scale_.get_y());
}
