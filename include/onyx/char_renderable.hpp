#pragma once

#include <onyx/core.hpp>
#include <onyx/font.hpp>

namespace onyx
{
	/*
		@brief A class to represent a single renderable text character.
		Used by the TextRenderable class.
	 */
	class CharRenderable : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		CharRenderable();

		/*
			@brief Creates a CharRenderable for the specified character and font.
			@param c The character to render.
			@param font The font to use for rendering.
			@param advance The offset of the character on the x-axis.
		 */
		CharRenderable(char c, const Font& font, u32 advance = 0);

		/*
			@brief Renders the character.
		 */
		void render();

		/*
			@brief Gets the character.
			@return The character that the renderable represents.
		 */
		char get_char() const;

		/*
			@brief Gets the character mesh's VAO.
			@return The VAO.
		 */
		u32 get_vao() const;
		
		/*
			@brief Gets the character mesh's VBO.
			@return The VBO.
		 */
		u32 get_vbo() const;

		/*
			@brief Gets the character mesh's texture ID.
			@return The texture ID.
		 */
		u32 get_texture_id() const;

		void dispose() override;

	private:
		char char_;
		u32 vao, vbo, tex;
	};
}
