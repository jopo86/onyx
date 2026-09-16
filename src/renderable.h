#pragma once

#include "core.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"

namespace onyx
{
	/*
		@brief A class that represents a renderable object.
	 */
	class Renderable : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Renderable();

		/*
			@brief Creates a new Renderable object out of the specified mesh.
			@param mesh The mesh to use.
		 */
		Renderable(Mesh mesh);

		/*
			@brief Creates a new Renderable object out of the specified mesh and shader.
			@param mesh The mesh to use.
			@param shader The shader to use.
		 */
		Renderable(Mesh mesh, Shader shader);

		/*
			@brief Creates a new Renderable object out of the specified mesh, shader, and texture.
			@param mesh The mesh to use.
			@param shader The shader to use.
			@param texture The texture to use.
		 */
		Renderable(Mesh mesh, Shader shader, Texture texture);

		/*
			@brief Renders the object.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
		 */
		void render();

		/*
			@brief Renders the object using the specified view and projection matrices.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
			@param view The view matrix to use, generally from an Camera.
			@param proj The projection matrix to use, generally from an Camera.
			@param cam_pos The position of the camera.
		 */
		void render(const math::Mat4& view, const math::Mat4& proj, const math::Vec3& cam_pos);

		/*
			@brief Hides the renderable.
			This function simply makes render() no longer do anything.
		 */
		void hide();

		/*
			@brief Shows the renderable.
			This function simply makes render() do what it's supposed to.
		 */
		void show();

		/*
			@brief Toggles the visibility of the renderable.
			See hide() and show() for more info.
		 */
		void toggle_visibility();

		/*
			@brief Gets the position of the renderable.
			@return The position.
		 */
		const math::Vec3& get_position() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		const math::Vec3& get_rotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const math::Vec3& get_scale() const;

		/*
			@brief Gets the mesh associated with the renderable.
			@return A pointer to the mesh.
		 */
		Mesh* get_mesh();

		/*
			@brief Gets the shader associated with the renderable.
			@return A pointer to the shader.
		 */
		Shader* get_shader();

		/*
			@brief Gets the texture associated with the renderable.
			@return A pointer to the texture.
		 */
		Texture* get_texture();

		/*
			@brief Gets the model matrix of the renderable.
			@return The model matrix.
		 */
		const math::Mat4& get_model() const;

		/*
			@brief Gets whether the renderable is hidden.
			See hide() and show() for more info.
			@return Whether the renderable is hidden.
		 */
		bool is_hidden() const;

		/*
			@brief Sets the position of the renderable.
			@param position The new position.
		 */
		void set_position(const math::Vec3& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotations The new rotation around each axis.
		 */
		void set_rotation(const math::Vec3& rotations);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void set_scale(const math::Vec3& scales);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const math::Vec3& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate_local(const math::Vec3& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(const math::Vec3& rotations);

		/*
			@brief Rotates the renderable by the specified rotation amounts around the specified origin.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
			@param origin The origin to rotate around.
		 */
		void rotate(const math::Vec3& rotations, const math::Vec3& origin);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const math::Vec3& scalars);

		/*
			@brief Scales the renderable on all axes by the specified scalar amount.
			This function does not set the scale, it multiplies it.
			@param scalar The scalar amount for all axes.
		 */
		void scale(float scalar);
		
		/*
			@brief Resets the renderable's transform.
		 */
		void reset_transform();

		/*
			@brief Sets the mesh of the renderable.
		 !	Not recommended unless you know what you're doing.
			@param mesh The new mesh.
		 */
		void set_mesh(Mesh mesh);

		/*
			@brief Sets the shader of the renderable.
		 !	Not recommended unless you know what you're doing.
			@param shader The new shader.
		 */
		void set_shader(Shader shader);

		/*
			@brief Sets the texture of the renderable.
		 *	This will only take effect if the shader uses a texture to render.
		 	@param texture The new texture.
		 */
		void set_texture(Texture texture);

		/*
			@brief Sets the color of the renderable.
		 *	This will only take effect if the shader uses a color to render.
		 *	All this function does is set a uniform variable in the shader.
		 	@param color The new color, as a Vec3.
		 */
		void set_color(const math::Vec3& color);

		/*
			@brief Sets the color of the renderable.
		 *	This will only take effect if the shader uses a color to render.
		 *	All this function does is set a uniform variable in the shader.
		 	@param color The new color, as a Vec4.
		 */
		void set_color(const math::Vec4& color);

		void dispose() override;

	private:
		Mesh mesh;
		Shader shader;
		Texture texture;

		math::Mat4 model;
		math::Mat4 inverse_model;

		math::Vec3 position;
		math::Vec3 rotation;
		math::Vec3 scale_;

		bool hidden;

		void update_model();

	public:

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_triangle(float side, math::Vec3 rgb);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_triangle(float side, math::Vec4 rgba);

		/*
			@brief Creates a triangle renderable with the specified base, height, and color.
			@param base The base length.
			@param height The height.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_triangle(float base, float height, math::Vec3 rgb);

		/*
			@brief Creates a triangle renderable with the specified base, height, and color.
			@param base The base length.
			@param height The height.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_triangle(float base, float height, math::Vec4 rgba);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `colored_triangle` overloads")]]
		static Renderable colored_triangle(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec3 rgb);

		/*
			@deprecatd This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `colored_triangle` overloads")]]
		static Renderable colored_triangle(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec4 rgba);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param side The side length.
			@return The resulting renderable.
		 */
		static Renderable vertex_colored_triangle(float side);

		/*
			@brief Creates a triangle renderable with the specified base and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param base The base length.
			@param height The height.
			@return The resulting renderable.
		 */
		static Renderable vertex_colored_triangle(float base, float height);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `vertex_colored_triangle` overloads")]]
		static Renderable vertex_colored_triangle(math::Vec2 a, math::Vec2 b, math::Vec2 c);

		/*
			@brief Creates an equilateral triangle renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable textured_triangle(float side, Texture texture);

		/*
			@brief Creates a triangle renderable with the specified base, height, and texture.
			@param base The base length.
			@param height The height.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable textured_triangle(float base, float height, Texture texture);

		/*
* 			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `textured_triangle` overloads")]]
		static Renderable textured_triangle(math::Vec2 a, math::Vec2 b, math::Vec2 c, Texture texture);

		/*
			@brief Creates a square renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_square(float side, math::Vec3 rgb);

		/*
			@brief Creates a square renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_square(float side, math::Vec4 rgba);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and color.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_quad(float width, float height, math::Vec3 rgb);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and color.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting renderable.
		 */
		static Renderable colored_quad(float width, float height, math::Vec4 rgba);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `colored_quad` overloads")]]
		static Renderable colored_quad(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec2 d, math::Vec3 rgb);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `colored_quad` overloads")]]
		static Renderable colored_quad(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec2 d, math::Vec4 rgba);

		/*
			@brief Creates a square renderable with the specified side length and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param side The side length.
			@return The resulting renderable.
		 */
		static Renderable vertex_colored_square(float side);

		/*
			@brief Creates a rectangle renderable with the specified width and height, and uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@return The resulting renderable.
		 */
		static Renderable vertex_colored_quad(float width, float height);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `vertex_colored_quad` overloads")]]
		static Renderable vertex_colored_quad(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec2 d);

		/*
			@brief Creates a square renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable textured_square(float side, Texture texture);

		/*
			@brief Creates a rectangle renderable with the specified width, height, and texture.
			@param width The width of the rectangle.
			@param height The height of the rectangle.
			@param texture The texture to use.
			@return The resulting renderable.
		 */
		static Renderable textured_quad(float width, float height, Texture texture);

		/*
			@deprecated This function is deprecated and will be removed in the next major release.
		 */
		[[deprecated("This function is deprecated and will be removed in the next major release. Use the other `textured_quad` overloads")]]
		static Renderable textured_quad(math::Vec2 a, math::Vec2 b, math::Vec2 c, math::Vec2 d, Texture texture);

		/*
			@brief Creates a circle renderable with the specified radius, number of segments, and color.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_circle(float radius, int n_segments, math::Vec3 rgb);

		/*
			@brief Creates a circle renderable with the specified radius, number of segments, and color.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_circle(float radius, int n_segments, math::Vec4 rgba);

		/*
			@brief Creates a circle renderable with the specified radius, angle step, and color.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_circle(float radius, float angle_step, math::Vec3 rgb);

		/*
			@brief Creates a circle renderable with the specified radius, angle step, and color.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_circle(float radius, float angle_step, math::Vec4 rgba);

		/*
			@brief Creates a circle renderable with the specified radius, number of segments, and texture.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable vertex_colored_circle(float radius, int n_segments);

		/*
			@brief Creates a circle renderable with the specified radius, angle step, and texture.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable vertex_colored_circle(float radius, float angle_step);

		/*
			@brief Creates a circle renderable with the specified radius, number of segments, and texture.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_circle(float radius, int n_segments, Texture texture);

		/*
			@brief Creates a circle renderable with the specified radius, angle step, and texture.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_circle(float radius, float angle_step, Texture texture);

		/*
			@brief Creates a cube renderable with the specified side length and color.
			@param side The side length.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cube(float side, math::Vec3 rgb);

		/*
			@brief Creates a cube renderable with the specified side length and color.
			@param side The side length.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cube(float side, math::Vec4 rgba);

		/*
			@brief Creates a cube renderable with the specified side length and texture.
			@param side The side length.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_cube(float side, Texture texture);

		/*
			@brief Creates a rectangular prism renderable with the specified width, height, depth, and color.
			@param width The width.
			@param height The height.
			@param depth The depth.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_rect_prism(float width, float height, float depth, math::Vec3 rgb);

		/*
			@brief Creates a rectangular prism renderable with the specified width, height, depth, and color.
			@param width The width.
			@param height The height.
			@param depth The depth.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_rect_prism(float width, float height, float depth, math::Vec4 rgba);

		/*
			@brief Creates a rectangular prism renderable with the specified width, height, depth, and texture.
			@param width The width.
			@param height The height.
			@param depth The depth.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_rect_prism(float width, float height, float depth, Texture texture);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, number of segments, and color.
			@param radius The radius.
			@param height The height.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cylinder(float radius, float height, int n_segments, math::Vec3 rgb);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, number of segments, and color.
			@param radius The radius.
			@param height The height.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cylinder(float radius, float height, int n_segments, math::Vec4 rgba);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, angle step, and color.
			@param radius The radius.
			@param height The height.
			@param angle_step The angle step, in degrees, between circle vertices.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cylinder(float radius, float height, float angle_step, math::Vec3 rgb);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, angle step, and color.
			@param radius The radius.
			@param height The height.
			@param angle_step The angle step, in degrees, between circle vertices.
			@param rgba The color, specified as red, green blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting mesh.
		 */
		static Renderable colored_cylinder(float radius, float height, float angle_step, math::Vec4 rgba);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, number of segments, and texture.
			@param radius The radius.
			@param height The height.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_cylinder(float radius, float height, int n_segments, Texture texture);

		/*
			@brief Creates a cylinder renderable with the specified radius, height, angle step, and texture.
			@param radius The radius.
			@param height The height.
			@param angle_step The angle step, in degrees, between circle vertices.
			@param texture The texture to use.
			@return The resulting mesh.
		 */
		static Renderable textured_cylinder(float radius, float height, float angle_step, Texture texture);
	};
}
