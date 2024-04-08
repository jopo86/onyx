#include "Texture.h"

#include <iostream>

Onyx::Texture::Texture()
{
	tex = 0;
}

Onyx::Texture::Texture(ImageData imageData, Onyx::TextureWrap textureWrap)
{
	tex = 0;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	switch (textureWrap)
	{
		case Onyx::TextureWrap::Null:
			Onyx::Err("Texture creation failed: texture wrap is null. (aborted");
			return;

		case Onyx::TextureWrap::Repeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			break;

		case Onyx::TextureWrap::MirroredRepeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
			break;

		case Onyx::TextureWrap::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			break;

		case Onyx::TextureWrap::ClampToBorder:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
			break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, imageData.getWidth(), imageData.getHeight(), 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imageData.getData());
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	imageData.dispose();
}

Onyx::Texture::Texture(ImageData& imageData, bool disposeImageData, Onyx::TextureWrap textureWrap)
{
	tex = 0;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	switch (textureWrap)
	{
		case Onyx::TextureWrap::Repeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			break;

		case Onyx::TextureWrap::MirroredRepeat:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
			break;

		case Onyx::TextureWrap::ClampToEdge:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			break;

		case Onyx::TextureWrap::ClampToBorder:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
			break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, imageData.getWidth(), imageData.getHeight(), 0, imageData.getNChannels() == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, imageData.getData());
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	if (disposeImageData) imageData.dispose();
}

Onyx::Texture::Texture(const Texture& other)
{
	tex = other.tex;
}

void Onyx::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, tex);
}

uint Onyx::Texture::getTextureID() const
{
	return tex;
}

void Onyx::Texture::dispose()
{
	if (tex) glDeleteTextures(1, &tex);
	tex = 0;
}
