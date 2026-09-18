#pragma once

#include <onyx/core.hpp>
#include <onyx/math_wrappers.hpp>
#include <onyx/mesh.hpp>
#include <onyx/texture.hpp>
#include <onyx/shader.hpp>

namespace onyx
{
	/*
		@brief A class that represents a renderable UI object.
		A renderable can be rendered directly, or through the Renderer class.
		This class is disposable.
	 */
	class UiRenderable : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		UiRenderable();

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and color.
			@param mesh The mesh to use.
			@param rgba The color, specified as red, green, and blue values ranging from 0 to 1.
			@param z_index The z-index of the renderable (should not be over 1000 or under -1000). Default: 0
		 */
		UiRenderable(Mesh mesh, math::Vec3 rgb, u32 z_index = 0);

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and color.
			@param mesh The mesh to use.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@param z_index The z-index of the renderable (should not be over 1000 or under -1000). Default: 0
		 */
		UiRenderable(Mesh mesh, math::Vec4 rgba, u32 z_index = 0);

		/*
			@brief Creates a new UiRenderable object out of the specified mesh and texture.
			The mesh vertex array should be VT format.
			@param mesh The mesh to use.
			@param texture The texture to use.
			@param z_index The z-index of the renderable (should not be over 1000 or under -1000). Default: 0
			@param result A pointer to a boolean that will be set to true if the renderable was created successfully, and false otherwise.
		 */
		UiRenderable(Mesh mesh, Texture texture, u32 z_index = 0, bool* result = nullptr);

		/*
			@brief Renders the object.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
		 */
		void render();

		/*
			@brief Renders the object and updates the orthographic projection matrix.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
			@param ortho The orthographic projection matrix to use.
		 */
		void render(math::Mat4 ortho);

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
		const math::Vec2& get_position() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		float get_rotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const math::Vec2& get_scale() const;

		/*
			@brief Gets the mesh associated with the renderable.
			@return The mesh.
		 */
		Mesh get_mesh() const;

		/*
			@brief Gets the shader associated with the renderable.
			@return The shader.
		 */
		Shader get_shader() const;

		/*
			@brief Gets the texture associated with the renderable.
			@return The texture.
		 */
		Texture get_texture() const;

		/*
			@brief Gets whether the renderable is hidden.
			See hide() and show() for more info.
			@return Whether the renderable is hidden.
		 */
		bool is_hidden() const;

		/*
			@brief Gets the z-index of the renderable.
			@return The z-index of the renderable.
		 */
		int get_z_index() const;

		/*
			@brief Sets the position of the renderable.
			@param position The new position.
		 */
		void set_position(const math::Vec2& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotation The new rotation.
		 */
		void set_rotation(float rotation);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void set_scale(const math::Vec2& scale);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const math::Vec2& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate_local(const math::Vec2& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(float rotation);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const math::Vec2& scalars);

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

		/*
			@brief Sets the z-index of the renderable.
			@param z_index The z-index (should not be over 1000 or under -1000).
		 */
		void set_z_index(int z_index);

		void dispose() override;

	private:
		Mesh mesh;
		Shader shader;
		Texture texture;

		math::Mat4 model;

		math::Vec2 position;
		float z;
		float rotation;
		math::Vec2 scale_;

		bool hidden;

		void update_model();

	public:

		/*
			@brief Generates a colored triangle UI renderable with the specified side lengths.
			@param side The side length of the triangle.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_triangle(float side, math::Vec3 rgb);

		/*
			@brief Generates a colored triangle UI renderable with the specified side lengths.
			@param side The side length of the triangle.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_triangle(float side, math::Vec4 rgba);

		/*
			@brief Generates a colored triangle UI renderable with the specified base and height.
			@param base The base length of the triangle.
			@param height The height of the triangle.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_triangle(float base, float height, math::Vec3 rgb);

		/*
			@brief Generates a colored triangle UI renderable with the specified base and height.
			@param base The base length of the triangle.
			@param height The height of the triangle.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_triangle(float base, float height, math::Vec4 rgba);

		/*
			@brief Generates a textured triangle UI renderable with the specified side lengths.
			@param side The side length of the triangle.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_triangle(float side, Texture texture);

		/*
			@brief Generates a textured triangle UI renderable with the specified base and height.
			@param base The base length of the triangle.
			@param height The height of the triangle.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_triangle(float base, float height, Texture texture);

		/*
			@brief Generates a colored square UI renderable with the specified side length.
			@param side The side length of the square.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_square(float side, math::Vec3 rgb);

		/*
			@brief Generates a colored square UI renderable with the specified side length.
			@param side The side length of the square.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_square(float side, math::Vec4 rgba);

		/*
			@brief Generates a textured square UI renderable with the specified side length.
			@param side The side length of the square.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_square(float side, Texture texture);

		/*
			@brief Generates a colored quad UI renderable with the specified width and height.
			@param width The width of the quad.
			@param height The height of the quad.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_quad(float width, float height, math::Vec3 rgb);

		/*
			@brief Generates a colored quad UI renderable with the specified width and height.
			@param width The width of the quad.
			@param height The height of the quad.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_quad(float width, float height, math::Vec4 rgba);

		/*
			@brief Generates a textured quad UI renderable with the specified width and height.
			@param width The width of the quad.
			@param height The height of the quad.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_quad(float width, float height, Texture texture);

		/*
			@brief Generates a colored circle UI renderable with the specified radius and number of segments.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_circle(float radius, int n_segments, math::Vec3 rgb);

		/*
			@brief Generates a colored circle UI renderable with the specified radius and number of segments.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_circle(float radius, int n_segments, math::Vec4 rgba);

		/*
			@brief Generates a colored circle UI renderable with the specified radius and angle step.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param rgb The color, specified as red, green, and blue values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_circle(float radius, float angle_step, math::Vec3 rgb);

		/*
			@brief Generates a colored circle UI renderable with the specified radius and angle step.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The generated renderable.
		 */
		static UiRenderable colored_circle(float radius, float angle_step, math::Vec4 rgba);

		/*
			@brief Generates a textured circle UI renderable with the specified radius and number of segments.
			@param radius The radius of the circle.
			@param n_segments The number of line segments used to approximate the circle outline.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_circle(float radius, int n_segments, Texture texture);

		/*
			@brief Generates a textured circle UI renderable with the specified radius and angle step.
			@param radius The radius of the circle.
			@param angle_step The angle step, in degrees, between vertices.
			@param texture The texture to use.
			@return The generated renderable.
		 */
		static UiRenderable textured_circle(float radius, float angle_step, Texture texture);
	};
}
