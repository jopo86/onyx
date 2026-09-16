#pragma once

#include "core.h"
#include "image_data.h"

namespace onyx
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
			@brief Creates a new Texture object from the specified image data.
		 !	Please note that the image data is not disposed after the texture is created.
			@param image_data The image data to create the texture from.
			@param texture_wrap The texture wrap option. Repeat by default.
			@param min_filter The minification filter (applied when the texture is shrunk). Nearest by default.
			@param mag_filter The magnification filter (applied when the texture is enlarged). Linear by default.
		 */
		Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap = onyx::TextureWrap::Repeat, onyx::TextureFilter min_filter = onyx::TextureFilter::Nearest, onyx::TextureFilter mag_filter = onyx::TextureFilter::Linear);

		/*
			@brief Creates a new Texture object from the specified image filepath.
			@param filepath The path of the image.
			@param result A pointer to a boolean that will be set to true if the texture was loaded successfully, and false otherwise.
			@param texture_wrap The texture wrap option. Repeat by default.
			@param min_filter The minification filter (applied when the texture is shrunk). Nearest by default.
			@param mag_filter The magnification filter (applied when the texture is enlarged). Linear by default.
		 */
		static Texture load(const std::string& filepath, bool* result = nullptr, onyx::TextureWrap texture_wrap = onyx::TextureWrap::Repeat, onyx::TextureFilter min_filter = onyx::TextureFilter::Nearest, onyx::TextureFilter mag_filter = onyx::TextureFilter::Linear);

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
		u32 get_texture_id() const;

		void dispose() override;

	private:
		u32 tex;
	};
}
