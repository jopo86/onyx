#pragma once

#include <string>
#include <vector>

#include <onyx/char_renderable.hpp>
#include <onyx/shader.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx
{
	/*
		@brief A class to represent a renderable string of text.
	 */
	class TextRenderable3D : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		TextRenderable3D();

		/*
			@brief Creates a TextRenderable3D from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
			@param result A pointer to a boolean that will be set to true if the object was created successfully, and false otherwise.
		 */
		TextRenderable3D(const std::string& text, Font& font, const math::Vec3& color, bool* result = nullptr);

		/*
			@brief Creates a TextRenderable3D from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
			@param result A pointer to a boolean that will be set to true if the object was created successfully, and false otherwise.
		 */
		TextRenderable3D(const std::string& text, Font& font, const math::Vec4& color, bool* result = nullptr);

		/*
			@brief Creates a TextRenderable3D from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
			@param shader_override The shader to use instead of the default 3D text shader.
			@param result A pointer to a boolean that will be set to true if the object was created successfully, and false otherwise.
		 */
		TextRenderable3D(const std::string& text, Font& font, const math::Vec3& color, Shader shader_override, bool* result = nullptr);

		/*
			@brief Creates a TextRenderable3D from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
			@param shader_override The shader to use instead of the default 3D text shader.
			@param result A pointer to a boolean that will be set to true if the object was created successfully, and false otherwise.
		 */
		TextRenderable3D(const std::string& text, Font& font, const math::Vec4& color, Shader shader_override, bool* result = nullptr);

		/*
			@brief Renders the object.
			This function, more technically, uses the shader, binds the texture, binds the VAO, draws, unbinds the VAO, unbinds the texture, and unuses the shader.
		 */
		void render();

		/*
			@brief Renders the object and updates the orthographic projection matrix.
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
			@brief Gets the text that is being rendered.
			@return The text that is being rendered.
		 */
		const std::string& get_text() const;

		/*
			@brief Gets the font that is being used.
			@return The font that is being used.
		 */
		const Font& get_font() const;

		/*
			@brief Gets the color of the text.
			@return The color of the text.
		 */
		const math::Vec4& get_color() const;

		/*
			@brief Gets the dimensions of the renderable.
			@return The dimensions (width and height)
		 */
		const math::Vec2& get_dimensions() const;

		/*
			@brief Gets the width of the renderable.
			@return The width.
		 */
		float get_width() const;

		/*
			@brief Gets the height of the renderable.
			@return The height.
		 */
		float get_height() const;

		/*
			@brief Gets whether the renderable is hidden.
			See hide() and show() for more info.
			@return Whether the renderable is hidden.
		 */
		bool is_hidden() const;

		/*
			@brief Gets the shader associated with the renderable.
			@return A pointer to the shader.
		 */
		Shader* get_shader();

		/*
			@brief Sets the text to render.
			Please note that this is a very expensive operation, as the mesh needs to be completely regenerated.
			This should not be called every frame unless necessary (FPS counters, etc).
			@param new_text The text to render.
		 */
		void set_text(const std::string& new_text);

		/*
			@brief Sets the font to use.
			Please note that this is a very expensive operation, as the mesh needs to be completely regenerated.
			This should not be called every frame.
			@param font The font to use.
		 */
		void set_font(Font& font);

		/*
			@brief Sets the color of the text.
			@param new_color The color of the text.
		 */
		void set_color(math::Vec3 new_color);

		/*
			@brief Sets the color of the text.
			@param new_color The color of the text.
		 */
		void set_color(math::Vec4 new_color);

		/*
			@brief Sets the position of the renderable.
			@param new_position The new position.
		 */
		void set_position(const math::Vec3& new_position);

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
			@brief Resets the renderable's transform (position, rotation, and scale).
			The dimensions are recalculated for the reset scale.
		 */
		void reset_transform();

		void dispose() override;

	private:
		std::vector<CharRenderable> chars;
		std::string text;
		math::Vec4 color;

		Shader shader;
		math::Mat4 model;

		math::Vec3 position;
		math::Vec3 rotation;
		math::Vec3 scale_;

		math::Vec2 dimensions_;

		Font* p_font;

		bool hidden;

		void update_model();
		void update_dimensions();
	};
}
