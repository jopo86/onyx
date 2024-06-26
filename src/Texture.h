#pragma once

#include "Core.h"

namespace Onyx
{
	/*
		@brief A class to represent a texture that can be applied to a mesh, preferably via a renderable.
		This class is disposable.
	 */
	class Texture : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Texture();

		/*
			@brief Creates a new Texture object from another texture object.
		 !	This function does not copy the texture data, rather the texture ID.
		 !	This means that the texture data is shared, and disposing of one texture will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other texture object.
		*/
		Texture(const Texture& other);

		/*
			@brief Creates a new Texture object from the specified image filepath.
			@param filepath The path of the image.
			@param result A pointer to a boolean that will be set to true if the texture was loaded successfully, and false otherwise.
			@param textureWrap The texture wrap option. Repeat by default.
			@param minFilter The minification filter (applied when the texture is shrunk). Nearest by default.
			@param magFilter The magnification filter (applied when the texture is enlarged). Linear by default.
		 */
		static Texture Load(const std::string& filepath, bool* result = nullptr, Onyx::TextureWrap textureWrap = Onyx::TextureWrap::Repeat, Onyx::TextureFilter minFilter = Onyx::TextureFilter::Nearest, Onyx::TextureFilter magFilter = Onyx::TextureFilter::Linear);

		/*
			@brief Binds the texture.
			Not needed if using renderables.
		 */
		void bind() const;

		/*
			@brief Gets the ID of the texture in OpenGL.
			Access to the texture ID is provided for the library, as well as for advanced users.
			@return The ID of the OpenGL texture.
		 */
		uint getTextureID() const;

		void dispose() override;

	private:
		uint m_tex;
	};
}
