#include <cmath>

#include <glad/glad.h>

#include <onyx/ui_renderable.hpp>
#include <onyx/shader.hpp>
#include "internal.hpp"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::Mat4;

onyx::UiRenderable::UiRenderable() 
{
	this->model = Mat4::identity();
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	this->hidden = false;
	this->z = 0.0f;
}

onyx::UiRenderable::UiRenderable(Mesh mesh, Vec3 rgb, int z_index)
{
	this->mesh = mesh;
	this->shader = Shader::p_ui_color(Vec4(rgb, 1.0f));
	this->model = Mat4::identity();
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	this->hidden = false;
	this->z = z_index / 1000.0f;
}

onyx::UiRenderable::UiRenderable(Mesh mesh, math::Vec4 rgba, int z_index)
{
	this->mesh = mesh;
	this->shader = Shader::p_ui_color(rgba);
	this->model = Mat4::identity();
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	this->hidden = false;
	this->z = z_index / 1000.0f;

}

onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture, int z_index, bool* result) 
{
	this->mesh = mesh;
	this->texture = texture;
	this->shader = Shader::pt_ui();
	this->model = Mat4::identity();
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	this->hidden = false;
	this->z = z_index / 1000.0f;

	if (!VertexBuffer::has_texture_coords(mesh.get_vertex_format()))
	{
		onyx_err(Error{
				.source_function = "onyx::UiRenderable::UiRenderable(Mesh mesh, Texture texture)",
				.message = "The mesh contains a vertex buffer that is not of a format with texture coordinates. It will most likely have problems rendering.",
				.how_to_fix = "Use a vertex format with texture coords: pt, pct, pnt, or pnct"
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	if (result != nullptr) *result = true;
}

void onyx::UiRenderable::render()
{
	if (this->hidden) return;
	this->shader.use();
	this->texture.bind();
	this->shader.set_mat4("u_model", this->model);
	glBindVertexArray(this->mesh.get_vao());
	glDrawElements(GL_TRIANGLES, this->mesh.get_indices_size() / sizeof(u32), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::UiRenderable::render(Mat4 ortho)
{
	if (this->hidden) return;
	this->shader.use();
	this->texture.bind();
	this->shader.set_mat4("u_model", this->model);
	this->shader.set_mat4("u_projection", ortho);
	glBindVertexArray(this->mesh.get_vao());
	glDrawElements(GL_TRIANGLES, this->mesh.get_indices_size() / sizeof(u32), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::UiRenderable::hide()
{
	this->hidden = true;
}

void onyx::UiRenderable::show()
{
	this->hidden = false;
}

void onyx::UiRenderable::toggle_visibility()
{
	this->hidden = !this->hidden;
}

const onyx::math::Vec2& onyx::UiRenderable::get_position() const
{
	return this->position;
}

float onyx::UiRenderable::get_rotation() const
{
	return this->rotation;
}

const onyx::math::Vec2& onyx::UiRenderable::get_scale() const
{
	return this->scale_;
}

onyx::Mesh onyx::UiRenderable::get_mesh() const
{
	return this->mesh;
}

onyx::Shader onyx::UiRenderable::get_shader() const
{
	return this->shader;
}

onyx::Texture onyx::UiRenderable::get_texture() const
{
	return this->texture;
}

bool onyx::UiRenderable::is_hidden() const
{
	return this->hidden;
}

int onyx::UiRenderable::get_z_index() const
{
	return static_cast<int>(std::lround(this->z * 1000.0f));
}

void onyx::UiRenderable::set_position(const Vec2& new_position)
{
	this->position = new_position;
	update_model();
}

void onyx::UiRenderable::set_rotation(float new_rotation)
{
	this->rotation = new_rotation;
	update_model();
}

void onyx::UiRenderable::set_scale(const Vec2& scale)
{
	this->scale_ = scale;
	update_model();
}

void onyx::UiRenderable::translate(const Vec2& translation)
{
	this->position += translation;
	update_model();
}

void onyx::UiRenderable::translate_local(const Vec2& translation)
{
	translate(math::rotate(translation, this->rotation));
}

void onyx::UiRenderable::rotate(float angle)
{
	this->rotation += angle;
	update_model();
}

void onyx::UiRenderable::scale(const Vec2& scalars)
{
	this->scale_.set_x(this->scale_.get_x() * scalars.get_x());
	this->scale_.set_y(this->scale_.get_y() * scalars.get_y());
	update_model();
}

void onyx::UiRenderable::scale(float scalar)
{
	this->scale_.set_x(this->scale_.get_x() * scalar);
	this->scale_.set_y(this->scale_.get_y() * scalar);
	update_model();
}

void onyx::UiRenderable::reset_transform()
{
	this->position = Vec2(0.0f);
	this->rotation = 0.0f;
	this->scale_ = Vec2(1.0f);
	update_model();
}

void onyx::UiRenderable::set_mesh(Mesh new_mesh)
{
	this->mesh = new_mesh;
}

void onyx::UiRenderable::set_shader(Shader new_shader)
{
	this->shader = new_shader;
}

void onyx::UiRenderable::set_texture(Texture new_texture)
{
	this->texture = new_texture;
}

void onyx::UiRenderable::set_color(const Vec3& color)
{
	this->shader.use();
	this->shader.set_vec4("u_color", Vec4(color, 1.0f));
}

void onyx::UiRenderable::set_color(const Vec4& color)
{
	this->shader.use();
	this->shader.set_vec4("u_color", color);
}

void onyx::UiRenderable::set_z_index(int z_index)
{
	this->z = z_index / 1000.0f;
	update_model();
}

void onyx::UiRenderable::dispose()
{
	if (this->disposed) return;
	this->mesh.dispose();
	this->shader.dispose();
	this->texture.dispose();
	this->disposed = true;
}

void onyx::UiRenderable::update_model()
{
	this->model = Mat4::identity();
	this->model.translate(Vec3(this->position, this->z));
	this->model.rotate(this->rotation, Vec3(0.0f, 0.0f, 1.0f));
	this->model.scale(Vec3(this->scale_, 1.0f));
}

onyx::UiRenderable onyx::UiRenderable::colored_triangle(float side, math::Vec3 rgb)
{
	return UiRenderable(Mesh::triangle(side), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_triangle(float side, math::Vec4 rgba)
{
	return UiRenderable(Mesh::triangle(side), rgba);
}

onyx::UiRenderable onyx::UiRenderable::colored_triangle(float base, float height, math::Vec3 rgb)
{
	return UiRenderable(Mesh::triangle(base, height), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_triangle(float base, float height, math::Vec4 rgba)
{
	return UiRenderable(Mesh::triangle(base, height), rgba);
}

onyx::UiRenderable onyx::UiRenderable::textured_triangle(float side, Texture texture)
{
	return UiRenderable(Mesh::triangle(side, false, true), texture);
}

onyx::UiRenderable onyx::UiRenderable::textured_triangle(float base, float height, Texture texture)
{
	return UiRenderable(Mesh::triangle(base, height, false, true), texture);
}

onyx::UiRenderable onyx::UiRenderable::colored_square(float side, math::Vec3 rgb)
{
	return UiRenderable(Mesh::square(side), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_square(float side, math::Vec4 rgba)
{
	return UiRenderable(Mesh::square(side), rgba);
}

onyx::UiRenderable onyx::UiRenderable::textured_square(float side, Texture texture)
{
	return UiRenderable(Mesh::square(side, false, true), texture);
}

onyx::UiRenderable onyx::UiRenderable::colored_quad(float width, float height, math::Vec3 rgb)
{
	return UiRenderable(Mesh::quad(width, height), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_quad(float width, float height, math::Vec4 rgba)
{
	return UiRenderable(Mesh::quad(width, height), rgba);
}

onyx::UiRenderable onyx::UiRenderable::textured_quad(float width, float height, Texture texture)
{
	return UiRenderable(Mesh::quad(width, height, false, true), texture);
}

onyx::UiRenderable onyx::UiRenderable::colored_circle(float radius, int n_segments, math::Vec3 rgb)
{
	return UiRenderable(Mesh::circle(radius, n_segments), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_circle(float radius, int n_segments, math::Vec4 rgba)
{
	return UiRenderable(Mesh::circle(radius, n_segments), rgba);
}

onyx::UiRenderable onyx::UiRenderable::colored_circle(float radius, float angle_step, math::Vec3 rgb)
{
	return UiRenderable(Mesh::circle(radius, angle_step), rgb);
}

onyx::UiRenderable onyx::UiRenderable::colored_circle(float radius, float angle_step, math::Vec4 rgba)
{
	return UiRenderable(Mesh::circle(radius, angle_step), rgba);
}

onyx::UiRenderable onyx::UiRenderable::textured_circle(float radius, int n_segments, Texture texture)
{
	return UiRenderable(Mesh::circle(radius, n_segments, false, true), texture);
}

onyx::UiRenderable onyx::UiRenderable::textured_circle(float radius, float angle_step, Texture texture)
{
	return UiRenderable(Mesh::circle(radius, angle_step, false, true), texture);
}
