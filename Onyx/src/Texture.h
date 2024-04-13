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
			@brief Creates an empty Texture object.
			Trying to use a texture constructed like this will most likely cause errors.
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
			@param textureWrap The texture wrap option. Repeat by default.
		 */
		static Texture Load(const std::string& filepath, Onyx::TextureWrap textureWrap = Onyx::TextureWrap::Repeat);

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
