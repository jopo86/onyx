#include "renderable.h"

#include <glad/glad.h>

void onyx_warn(const onyx::Warning&);

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, 
onyx::math::Mat4;

onyx::Renderable::Renderable() 
{
	this->model = Mat4(1.0f);
	this->inverse_model = math::inverse(this->model);
	this->scale_ = Vec3(1.0f);
	this->hidden = false;
}

onyx::Renderable::Renderable(Mesh mesh)
{
	this->mesh = mesh;
	this->shader = Shader::p_color(Vec4::white());
	this->model = Mat4(1.0f);
	this->inverse_model = math::inverse(this->model);
	this->scale_ = Vec3(1.0f);
	this->hidden = false;
}

onyx::Renderable::Renderable(Mesh mesh, Shader shader)
{
	this->mesh = mesh;
	this->shader = shader;
	this->model = Mat4(1.0f);
	this->inverse_model = math::inverse(this->model);
	this->scale_ = Vec3(1.0f);
	this->hidden = false;
}

onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)
{
	if (!VertexBuffer::has_texture_coords(mesh.get_vertex_format()))
	{
		onyx_warn(Warning{
				.source_function = "onyx::Renderable::Renderable(Mesh mesh, Shader shader, Texture texture)",
				.message = "The mesh contains a vertex buffer that is not of a format with texture coordinates. It will most likely have problems rendering.",
				.how_to_fix = "Use a vertex format with texture coords: pt, pct, pnt, or pnct",
				.severity = Warning::Severity::High
			}
		);
	}
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	this->model = Mat4(1.0f);
	this->inverse_model = math::inverse(this->model);
	this->scale_ = Vec3(1.0f);
	this->hidden = false;
}

void onyx::Renderable::render()
{
	if (this->hidden) return;
	this->shader.use();
	this->texture.bind();
	this->shader.set_mat4("u_model", this->model);
	this->shader.set_mat4("u_inverseModel", this->inverse_model);
	glBindVertexArray(this->mesh.get_vao());
	glDrawElements(GL_TRIANGLES, this->mesh.get_indices_size() / sizeof(u32), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Renderable::render(const Mat4& view, const Mat4& proj, const Vec3& cam_pos)
{
	if (this->hidden) return;
	this->shader.use();
	this->texture.bind();
	this->shader.set_mat4("u_model", this->model);
	this->shader.set_mat4("u_inverseModel", this->inverse_model);
	this->shader.set_mat4("u_view", view);
	this->shader.set_mat4("u_projection", proj);
	this->shader.set_vec3("u_camPos", cam_pos);
	glBindVertexArray(this->mesh.get_vao());
	glDrawElements(GL_TRIANGLES, this->mesh.get_indices_size() / sizeof(u32), GL_UNSIGNED_INT, nullptr);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glUseProgram(0);

#if defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Renderable::hide()
{
	this->hidden = true;
}

void onyx::Renderable::show()
{
	this->hidden = false;
}

void onyx::Renderable::toggle_visibility()
{
	this->hidden = !this->hidden;
}

const Vec3& onyx::Renderable::get_position() const
{
	return this->position;
}

const Vec3& onyx::Renderable::get_rotation() const
{
	return this->rotation;
}

const Vec3& onyx::Renderable::get_scale() const
{
	return this->scale_;
}

onyx::Mesh* onyx::Renderable::get_mesh()
{
	return &this->mesh;
}

onyx::Shader* onyx::Renderable::get_shader()
{
	return &this->shader;
}

onyx::Texture* onyx::Renderable::get_texture()
{
	return &this->texture;
}

const Mat4& onyx::Renderable::get_model() const
{
	return this->model;
}

bool onyx::Renderable::is_hidden() const
{
	return this->hidden;
}

void onyx::Renderable::set_position(const Vec3& position)
{
	this->position = position;
	update_model();
}

void onyx::Renderable::set_rotation(const Vec3& rotations)
{
	this->rotation = rotations;
	update_model();
}

void onyx::Renderable::set_scale(const Vec3& scales)
{
	this->scale_ = scales;
	update_model();
}

void onyx::Renderable::translate(const Vec3& translation)
{
	this->position += translation;
	update_model();
}

void onyx::Renderable::translate_local(const Vec3& translation)
{
	translate(math::rotate(translation, this->rotation));
}

void onyx::Renderable::rotate(const Vec3& rotations)
{
	this->rotation += rotations;
	update_model();
}

void onyx::Renderable::rotate(const Vec3& rotations, const Vec3& origin)
{
	Vec3 diff = this->position - origin;
	translate(-diff);
	rotate(rotations);
	diff = math::rotate(diff, rotations);
	translate(diff);
}

void onyx::Renderable::scale(const Vec3& scalars)
{
	this->scale_.set_x(this->scale_.get_x() * scalars.get_x());
	this->scale_.set_y(this->scale_.get_y() * scalars.get_y());
	this->scale_.set_z(this->scale_.get_z() * scalars.get_z());
	update_model();
}

void onyx::Renderable::scale(float scalar)
{
	this->scale_.set_x(this->scale_.get_x() * scalar);
	this->scale_.set_y(this->scale_.get_y() * scalar);
	this->scale_.set_z(this->scale_.get_z() * scalar);
	update_model();
}

void onyx::Renderable::reset_transform()
{
	this->position = Vec3(0.0f);
	this->rotation = Vec3(0.0f);
	this->scale_ = Vec3(1.0f);
	this->model = Mat4::identity();
}

void onyx::Renderable::set_mesh(Mesh mesh)
{
	this->mesh = mesh;
}

void onyx::Renderable::set_shader(Shader shader)
{
	this->shader = shader;
}

void onyx::Renderable::set_texture(Texture texture)
{
	this->texture = texture;
}

void onyx::Renderable::set_color(const Vec3& color)
{
	this->shader.use();
	this->shader.set_vec4("u_color", Vec4(color, 1.0f));
}

void onyx::Renderable::set_color(const Vec4& color)
{
	this->shader.use();
	this->shader.set_vec4("u_color", color);
}

void onyx::Renderable::dispose()
{
	if (this->disposed) return;
	this->texture.dispose();
	this->shader.dispose();
	this->mesh.dispose();
	this->disposed = true;
}

void onyx::Renderable::update_model()
{
	this->model = Mat4::identity();
	this->model.translate(this->position);
	this->model.rotate(this->rotation.get_x(), Vec3(1.0f, 0.0f, 0.0f));
	this->model.rotate(this->rotation.get_y(), Vec3(0.0f, 1.0f, 0.0f));
	this->model.rotate(this->rotation.get_z(), Vec3(0.0f, 0.0f, 1.0f));
	this->model.scale(this->scale_);
	this->inverse_model = math::inverse(this->model);
}

onyx::Renderable onyx::Renderable::colored_triangle(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::triangle(side, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_triangle(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::triangle(side, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_triangle(float base, float height, Vec3 rgb)
{
	return Renderable(
		Mesh::triangle(base, height, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_triangle(float base, float height, Vec4 rgba)
{
	return Renderable(
		Mesh::triangle(base, height, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_triangle(Vec2 a, Vec2 b, Vec2 c, Vec3 rgb)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::colored_triangle(Vec2 a, Vec2 b, Vec2 c, Vec4 rgba)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::vertex_colored_triangle(float side)
{
	return Renderable(
		Mesh::triangle(side, true),
		Shader::pn_xyz_to_rgb()
	);
}

onyx::Renderable onyx::Renderable::vertex_colored_triangle(float base, float height)
{
	return Renderable(
		Mesh::triangle(base, height, true),
		Shader::pn_xyz_to_rgb()
	);
}

onyx::Renderable onyx::Renderable::vertex_colored_triangle(Vec2 a, Vec2 b, Vec2 c)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::textured_triangle(float side, Texture texture)
{
	return Renderable(
		Mesh::triangle(side, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_triangle(float base, float height, Texture texture)
{
	return Renderable(
		Mesh::triangle(base, height, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_triangle(Vec2 a, Vec2 b, Vec2 c, Texture texture)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::colored_square(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::square(side, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_square(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::square(side, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_quad(float width, float height, Vec3 rgb)
{
	return Renderable(
		Mesh::quad(width, height, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_quad(float width, float height, Vec4 rgba)
{
	return Renderable(
		Mesh::quad(width, height, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec3 rgb)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::colored_quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Vec4 rgba)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::vertex_colored_square(float side)
{
	return vertex_colored_quad(side, side);
}

onyx::Renderable onyx::Renderable::vertex_colored_quad(float width, float height)
{
	return Renderable(
		Mesh::quad(width, height, true),
		Shader::pn_xyz_to_rgb()
	);
}

onyx::Renderable onyx::Renderable::vertex_colored_quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::textured_square(float side, Texture texture)
{
	return Renderable(
		Mesh::square(side, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_quad(float width, float height, Texture texture)
{
	return Renderable(
		Mesh::quad(width, height, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d, Texture texture)
{
	return Renderable();
}

onyx::Renderable onyx::Renderable::colored_circle(float radius, int n_segments, math::Vec3 rgb)
{
	return Renderable(
		Mesh::circle(radius, n_segments, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_circle(float radius, int n_segments, math::Vec4 rgba)
{
	return Renderable(
		Mesh::circle(radius, n_segments, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_circle(float radius, float angle_step, math::Vec3 rgb)
{
	return Renderable(
		Mesh::circle(radius, angle_step, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_circle(float radius, float angle_step, math::Vec4 rgba)
{
	return Renderable(
		Mesh::circle(radius, angle_step, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::vertex_colored_circle(float radius, int n_segments)
{
	return Renderable(
		Mesh::circle(radius, n_segments, true),
		Shader::pn_xyz_to_rgb()
	);
}

onyx::Renderable onyx::Renderable::vertex_colored_circle(float radius, float angle_step)
{
	return Renderable(
		Mesh::circle(radius, angle_step, true),
		Shader::pn_xyz_to_rgb()
	);
}

onyx::Renderable onyx::Renderable::textured_circle(float radius, int n_segments, Texture texture)
{
	return Renderable(
		Mesh::circle(radius, n_segments, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_circle(float radius, float angle_step, Texture texture)
{
	return Renderable(
		Mesh::circle(radius, angle_step, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::colored_cube(float side, Vec3 rgb)
{
	return Renderable(
		Mesh::cube(side, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_cube(float side, Vec4 rgba)
{
	return Renderable(
		Mesh::cube(side, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::textured_cube(float side, Texture texture)
{
	return Renderable(
		Mesh::cube(side, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::colored_rect_prism(float width, float height, float depth, Vec3 rgb)
{
	return Renderable(
		Mesh::rect_prism(width, height, depth, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_rect_prism(float width, float height, float depth, Vec4 rgba)
{
	return Renderable(
		Mesh::rect_prism(width, height, depth, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::textured_rect_prism(float width, float height, float depth, Texture texture)
{
	return Renderable(
		Mesh::rect_prism(width, height, depth, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::colored_cylinder(float radius, float height, int n_segments, Vec3 rgb)
{
	return Renderable(
		Mesh::cylinder(radius, height, n_segments, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_cylinder(float radius, float height, int n_segments, Vec4 rgba)
{
	return Renderable(
		Mesh::cylinder(radius, height, n_segments, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::colored_cylinder(float radius, float height, float angle_step, Vec3 rgb)
{
	return Renderable(
		Mesh::cylinder(radius, height, angle_step, true),
		Shader::pn_color(Vec4(rgb, 1.0f))
	);
}

onyx::Renderable onyx::Renderable::colored_cylinder(float radius, float height, float angle_step, Vec4 rgba)
{
	return Renderable(
		Mesh::cylinder(radius, height, angle_step, true),
		Shader::pn_color(rgba)
	);
}

onyx::Renderable onyx::Renderable::textured_cylinder(float radius, float height, int n_segments, Texture texture)
{
	return Renderable(
		Mesh::cylinder(radius, height, n_segments, true, true),
		Shader::pnt(),
		texture
	);
}

onyx::Renderable onyx::Renderable::textured_cylinder(float radius, float height, float angle_step, Texture texture)
{
	return Renderable(
		Mesh::cylinder(radius, height, angle_step, true, true),
		Shader::pnt(),
		texture
	);
}
