#pragma once

#include <string>

#include "Core.h"
#include "Font.h"
#include "Math.h"
#include "Window.h"
#include "Shader.h"
#include "File.h"
#include "Projection.h"
#include "Renderer.h"

namespace Onyx
{
	/*
		@brief A class that can render text to the screen.
	 */
	class TextRenderer
	{
		friend class Window;

	public:
		/*
			@brief Creates an empty text renderer.
		 !	Trying to use a text renderer constructed like this will result in undefined behavior.
		 */
		TextRenderer();

		/*
			@brief Creates a text renderer associated with the specified window.
			@param window The associated window.
			Note: the text renderer will render text to whichever window's context is active, but the position will be relative to its 'associated' window.
		 */
		TextRenderer(Window& window);

		/*
			@brief Renders text to the screen using the currently set font.
		 !	Will most likely cause a crash if a font is not set before calling this function.
			@param text The text to render.
			@param pos The position to render the text at (bottom left of the window is (0, 0)).
			@param color The color of the text, specified as three RGB values between 0 and 1.
		 */
		void render(const std::string& text, Onyx::Math::Vec2 pos, Onyx::Math::Vec3 color);

		/*
			@brief Renders text to the screen using the currently set font.
		 !	Will most likely cause a crash if a font is not set before calling this function.
			@param text The text to render.
			@param pos The position to render the text at (bottom left of the window is (0, 0)).
			@param scale The scale of the text, where 1 is the default scale.
			@param color The color of the text, specified as three RGB values between 0 and 1.
		 */
		void render(const std::string& text, Onyx::Math::Vec2 pos, float scale, Onyx::Math::Vec3 color);

		/*
			@brief This function isn't actually necessary for text rendering.
			What it does is ensure that text is always rendered in front of everything else.
		 !	Rendering order / depth testing will be messed up if StartRender is used but EndRender is not.
		 */
		static void StartRender();

		/*
			@brief This function isn't actually necessary for text rendering, unless StartRender is used.
			What StartRender does is ensure that text is always rendered in front of everything else.
		 !	Rendering order / depth testing will be messed up if StartRender is used but EndRender is not.
		 */
		static void EndRender();

		/*
			@brief Gets the VAO used by the text renderer.
			@return The vertex array object.
		 */
		uint getVAO() const;

		/*
			@brief Gets the VBO used by the text renderer.
			@return The vertex buffer object.
		 */
		uint getVBO() const;

		/*
			@brief Gets the font of the text renderer.
			@return A pointer to the font.
		 */
		const Onyx::Font* getFont() const;

		/*
			@brief Sets the font of the text renderer.
		 *	This should be called before renderText is called.
			@param font The font to use.
		 */
		void setFont(Font& font);

	private:
		uint vao, vbo;
		Shader shader;

		Font font;

		static bool wireframe;
	};
}
