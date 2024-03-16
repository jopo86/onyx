#include "ImageData.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

Onyx::ImageData::ImageData()
{
	data = nullptr;
	width = height = nChannels = 0;
}

Onyx::ImageData::ImageData(ubyte *data, int width, int height, int nChannels)
{
	this->data = data;
	this->width = width;
	this->height = height;
	this->nChannels = nChannels;
}

Onyx::ImageData Onyx::ImageData::Load(std::string filepath)
{
	int width = 0, height = 0, nChannels = 0;

#ifndef ONYX_STBI_FLIP_FIX
	stbi_set_flip_vertically_on_load(true);
#define ONYX_STBI_FLIP_FIX
#endif

	ubyte* data = stbi_load(filepath.c_str(), &width, &height, &nChannels, 0);
	return ImageData(data, width, height, nChannels);
}

Onyx::ImageData Onyx::ImageData::Load(std::string filepath, ErrorHandler& errorHandler)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		errorHandler.err("failed to locate file: \"" + filepath + "\"");
		return ImageData();
	}
	file.close();

	int width = 0, height = 0, nChannels = 0;

#ifndef ONYX_STBI_FLIP_FIX
	stbi_set_flip_vertically_on_load(true);
#define ONYX_STBI_FLIP_FIX
#endif

	ubyte* data = stbi_load(filepath.c_str(), &width, &height, &nChannels, 0);
	if (!data)
	{
		errorHandler.err("found file, but failed to load image data: \"" + filepath + "\"");
		return ImageData();
	}

	return ImageData(data, width, height, nChannels);
}

ubyte *Onyx::ImageData::getData()
{
	return data;
}

int Onyx::ImageData::getWidth()
{
	return width;
}

int Onyx::ImageData::getHeight()
{
	return height;
}

int Onyx::ImageData::getNChannels()
{
	return nChannels;
}

void Onyx::ImageData::dispose()
{
	stbi_image_free(data);
	data = 0;
	width = height = nChannels = 0;
}
