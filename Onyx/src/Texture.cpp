#include "Texture.h"

#include <fstream>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

Onyx::Texture::Texture()
{
	tex = 0;
}

Onyx::Texture::Texture(const Texture& other)
{
	tex = other.tex;
}

Onyx::Texture Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		Err("failed to locate file: \"" + filepath + "\"");
		return Texture();
	}
	file.close();

	int width = 0, height = 0, nChannels = 0;

	stbi_set_flip_vertically_on_load(true);

	ubyte* data = stbi_load(filepath.c_str(), &width, &height, &nChannels, 0);
	if (!data)
	{
		Err("found file, but failed to load image data: \"" + filepath + "\"");
		return Texture();
	}

	Texture texture;

	texture.tex = 0;

	glGenTextures(1, &texture.tex);
	glBindTexture(GL_TEXTURE_2D, texture.tex);

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

	glTexImage2D(GL_TEXTURE_2D, 0, nChannels == 4 ? GL_RGBA : GL_RGB, width, height, 0, nChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif


	return texture;
}

void Onyx::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, tex);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

uint Onyx::Texture::getTextureID() const
{
	return tex;
}

void Onyx::Texture::dispose()
{
	if (tex) glDeleteTextures(1, &tex);
	tex = 0;

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
