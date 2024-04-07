#pragma once

#include <fstream>

#include "Core.h"
#include "ErrorHandler.h"

namespace Onyx
{

	/*
		@brief A class to contain image data.
		This includes the actual byte data of the image, dimensions, and the format (RGB/RGBA).
		This class is disposable.
	 */
	class ImageData : public Disposable
	{
	public:
		/*
			@brief Creates an empty ImageData object.
			Trying to use image data constructed like this will most likely cause errors.
		 */
		ImageData();

		/*
			@brief Creates a new ImageData object with the specified byte data, dimensions, and format.
			Format is specified by number of channels: 3 = RGB, 4 = RGBA.
		 */
		ImageData(ubyte* data, int width, int height, int nChannels);

		/*
			@brief Creates a new ImageData object from another image data object.
		 !	This function does not copy the image data, it shares it between the two.
		 !	This means that disposing of one image data will dispose of the other.
		 !	This is used appropriately in the renderable presets, but should be used elsewhere with caution.
			@param other The other image data object.
		*/
		ImageData(const ImageData& other);

		/*
			@brief Creates a new ImageData object from the image at the specified file path.
			@param filepath The file path to the image.
			@return The ImageData object that was created.
		 */
		static ImageData Load(std::string filepath);

		/*
			@brief Gets the actual byte data of the image.
			This is used by the library, it does not have much use for the user.
			@return A pointer (array) to the byte data.
		 */
		ubyte* getData() const;

		/*
			@brief Gets the width of the image.
			@return The width of the image.
		 */
		int getWidth() const;

		/*
			@brief Gets the height of the image.
			@return The height of the image.
		 */
		int getHeight() const;

		/*
			@brief Gets the format of the image.
			@return The format of the image as a number of channels: 3 = RGB, 4 = RGBA.
		 */
		int getNChannels() const;

		/*
			@brief Disposes of the image data.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		ubyte* data;
		int width, height, nChannels;
	};
}
