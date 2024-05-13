#pragma once

#include <vector>

#include "CharRenderable.h"
#include "Shader.h"
#include "Math.h"

namespace Onyx
{
	/*
		@brief A class to represent a renderable string of text.
	 */
	class TextRenderable3D : Disposable
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
		TextRenderable3D(const std::string& text, Font& font, Math::Vec3 color, bool* result = nullptr);

		/*
			@brief Creates a TextRenderable3D from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
			@param result A pointer to a boolean that will be set to true if the object was created successfully, and false otherwise.
		 */
		TextRenderable3D(const std::string& text, Font& font, Math::Vec4 color, bool* result = nullptr);

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
			@param camPos The position of the camera.
		 */
		void render(const Math::Mat4& view, const Math::Mat4& proj, const Math::Vec3& camPos);

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
			@brief Gets the dimensions of the renderable.
			@return The dimensions (width and height), in pixels.
		 */
		Math::Vec2 dimensions() const;

		/*
			@brief Toggles the visibility of the renderable.
			See hide() and show() for more info.
		 */
		void toggleVisibility();

		/*
			@brief Gets the position of the renderable.
			@return The position.
		 */
		const Math::Vec3& getPosition() const;

		/*
			@brief Gets the rotation of the renderable.
			@return The rotation around each axis.
		 */
		const Math::Vec3& getRotation() const;

		/*
			@brief Gets the scale of the renderable.
			@return The scale for each axis.
		 */
		const Math::Vec3& getScale() const;

		/*
			@brief Gets the text that is being rendered.
			@return The text that is being rendered.
		 */
		const std::string& getText() const;

		/*
			@brief Gets the font that is being used.
			@return The font that is being used.
		 */
		const Font& getFont() const;

		/*
			@brief Gets the color of the text.
			@return The color of the text.
		 */
		const Math::Vec4& getColor() const;

		/*
			@brief Gets whether the renderable is hidden.
			See hide() and show() for more info.
			@return Whether the renderable is hidden.
		 */
		bool isHidden() const;

		/*
			@brief Gets the shader associated with the renderable.
			@return A pointer to the shader.
		 */
		Shader* getShader();

		/*
			@brief Sets the text to render.
			Please note that this is a very expensive operation, as the mesh needs to be completely regenerated.
			This should not be called every frame unless necessary (FPS counters, etc).
			@param text The text to render.
		 */
		void setText(const std::string& text);

		/*
			@brief Sets the font to use.
			Please note that this is a very expensive operation, as the mesh needs to be completely regenerated.
			This should not be called every frame.
			@param font The font to use.
		 */
		void setFont(Font& font);

		/*
			@brief Sets the color of the text.
			@param color The color of the text.
		 */
		void setColor(Math::Vec3 color);

		/*
			@brief Sets the color of the text.
			@param color The color of the text.
		 */
		void setColor(Math::Vec4 color);

		/*
			@brief Sets the position of the renderable.
			@param position The new position.
		 */
		void setPosition(const Math::Vec3& position);

		/*
			@brief Sets the rotation of the renderable.
			@param rotations The new rotation around each axis.
		 */
		void setRotation(const Math::Vec3& rotations);

		/*
			@brief Sets the scale of the renderable.
			@param scales The new scale for each axis.
		 */
		void setScale(const Math::Vec3& scales);

		/*
			@brief Translates the renderable by the specified positional amount.
			This function does not set the position, it adds to it.
			The translation is in world space, not local space, so rotation will not affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translate(const Math::Vec3& translation);

		/*
			@brief Translate the renderable by the specified positional amount in local space.
			This function does not set the position, it adds to it.
			The translation is in local space, not world space, so rotation will affect the translation.
			@param translation The positional amount to translate by.
		 */
		void translateLocal(const Math::Vec3& translation);

		/*
			@brief Rotates the renderable by the specified rotation amounts.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
		 */
		void rotate(const Math::Vec3& rotations);

		/*
			@brief Rotates the renderable by the specified rotation amounts around the specified origin.
			This function does not set the rotation, it adds to it.
			@param rotations The rotation amounts around each axis.
			@param origin The origin to rotate around.
		 */
		void rotate(const Math::Vec3& rotations, const Math::Vec3& origin);

		/*
			@brief Scales the renderable by the specified scalar amounts.
			This function does not set the scale, it multiplies it.
			@param scalars The scalar amounts for each axis.
		 */
		void scale(const Math::Vec3& scalars);

		/*
			@brief Scales the renderable on all axes by the specified scalar amount.
			This function does not set the scale, it multiplies it.
			@param scalar The scalar amount for all axes.
		 */
		void scale(float scalar);

		/*
			@brief Resets the renderable's transform.
		 */
		void resetTransform();

		void dispose() override;

	private:
		std::vector<CharRenderable> m_chars;
		std::string m_text;
		Math::Vec4 m_color;

		Shader m_shader;
		Math::Mat4 m_model;

		Math::Vec3 m_position;
		Math::Vec3 m_rotation;
		Math::Vec3 m_scale;

		Font* m_pFont;

		bool m_hidden;

		void updateModel();
	};
}
