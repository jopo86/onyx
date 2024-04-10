#pragma once

#include "Core.h"
#include "ImageData.h"

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
			@brief Creates an empty Texture object.
			Trying to use a texture constructed like this will most likely cause errors.
		 */
		Texture();

		/*
			@brief Creates a new Texture object from the specified image data.
			Disposes of the image data after use.
			This should be used for image data created anonymously, not as a variable.
			@param imageData The image data to use and dispose.
			@param textureWrap The texture wrap option. Use definitions prefixed with ONYX_TEXTURE_WRAP. Repeat by default.
		 */
		Texture(ImageData imageData, Onyx::TextureWrap textureWrap = Onyx::TextureWrap::Repeat);

		/*
			@brief Creates a new Texture object from the specified image data.
			Disposes of the image data after use if the second argument is true.
			This should be used for image data created as a variable, not anonymously.
			@param imageData The image data to use.
			@param disposeImageData Whether to dispose the image data after use.
			@param textureWrap The texture wrap option. Use definitions prefixed with ONYX_TEXTURE_WRAP. Repeat by default.
		 */
		Texture(ImageData& imageData, bool disposeImageData, Onyx::TextureWrap textureWrap = Onyx::TextureWrap::Repeat);

		/*
			@brief Creates a new Texture object from another texture object.
		 !	This function does not copy the texture data, rather the texture ID.
		 !	This means that the texture data is shared, and disposing of one texture will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other texture object.
		*/
		Texture(const Texture& other);

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

		/*
			@brief Disposes of the texture.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		uint tex;
	};
}
