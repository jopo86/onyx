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
    class TextRenderable : Disposable
    {
    public:
		/*
			@brief Creates an empty TextRenderable.
		 */
        TextRenderable();

		/*
			@brief Creates a TextRenderable from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
         */
        TextRenderable(const std::string& text, Font& font, Math::Vec3 color);

		/*
			@brief Creates a TextRenderable from the specified text, font, and color.
			@param text The text to render.
			@param font The font to use.
			@param color The color of the text.
		 */
        TextRenderable(const std::string& text, Font& font, Math::Vec4 color);

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
		void render(Math::Mat4 ortho);

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
		void toggleVisibility();

		/*
			@brief Changes the renderable's position by the specified 2D vector.
			Note that this function inc/decrements the renderable's position, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param xy The vector to move by.
		 */
		void translate(Math::Vec2 xy);

		/*
			@brief Rotates the renderable by the specified degree angle.
			Note that this function inc/decrements the renderable's rotation, it does not set it.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param degrees The degree angle to rotate.
		 */
		void rotate(float degrees);

		/*
			@brief Scales the renderable in all dimensions by the specified scalar.
			Note that this function scales the renderable by whatever its current scale is, it does not set its scale.
			This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param scalar The scale multiplier.
			If the scalar is 0, it will effectively hide the renderable.
		 */
		void scale(float scalar);

		/*
			@brief Scales the renderable by the scalars for each dimension.
			Note that this function scales the renderable by whatever its current scale is, it does not set its scale.
			This means that scale(1) will not reset the renderable's scale, it just wont change it at all.
			Directly setting a transform is not natively supported, that would be up to the user to program.
			@param xyScalar The scalars for each dimension. Here are some examples:
			(1, 1) will not change anything.
			(1, 0.5) will half the renderable's size on the y axis.
			(2, 0.5) will double the renderable's size on the x axis and half it on the y axis.
			If any scalar is 0, it will effectively hide the renderable.
		 */
		void scale(Math::Vec2 xyScalar);

		/*
			@brief Resets the renderable's transforms.
			This resets its position to its original vertex positions, its rotation to 0, and its scale to 1.
		 */
		void resetTransform();

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
			@brief Disposes of the renderable, including the associated mesh, shader, and texture.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

    private:
        std::vector<CharRenderable> chars;
		std::string text;
		Math::Vec4 color;

        Shader shader;
        Math::Mat4 model;

        Font* font;

		bool hidden;
    };
}
