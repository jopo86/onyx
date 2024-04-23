#include "Texture.h"

#include <fstream>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stbi/stb_image.h>

bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);

Onyx::Texture::Texture()
{
	tex = 0;
}

Onyx::Texture::Texture(const Texture& other)
{
	tex = other.tex;
}

Onyx::Texture Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)
{
	std::ifstream file(filepath);
	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)",
				.message = "File not found (or access denied): \"" + filepath + "\"",
				.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		return Texture();
	}
	file.close();

	if (!onyx_is_ehandler_nullptr()) if (textureWrap == Onyx::TextureWrap::Null)
    {
		onyx_err(Error{
				.sourceFunction = "Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)",
                .message = "Texture wrap option cannot be null",
                .howToFix = "Enter a valid texture wrap option."
			}
		);
        return Texture();
    }

	if (!onyx_is_ehandler_nullptr()) if (minFilter == Onyx::TextureFilter::Null)
    {
		onyx_err(Error{
			.sourceFunction = "Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)",
            .message = "Minification filter option cannot be null",
            .howToFix = "Enter a valid minification filter option."
			}
		);

        return Texture();
    }

	if (!onyx_is_ehandler_nullptr()) if (magFilter == Onyx::TextureFilter::Null)
	{
		onyx_err(Error{
			.sourceFunction = "Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)",
			.message = "Magnification filter option cannot be null",
			.howToFix = "Enter a valid magnification filter option."
			}
		);
        return Texture();
	}

	int width = 0, height = 0, nChannels = 0;

	stbi_set_flip_vertically_on_load(true);

	ubyte* data = stbi_load(filepath.c_str(), &width, &height, &nChannels, 0);
	if (!onyx_is_ehandler_nullptr()) if (!data)
	{
		onyx_err(Error{
                .sourceFunction = "Onyx::Texture::Load(const std::string& filepath, Onyx::TextureWrap textureWrap, Onyx::TextureFilter minFilter, Onyx::TextureFilter magFilter)",
                .message = "Found file, but failed to load image data: \"" + filepath + "\"",
                .howToFix = "Ensure the file is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
            }
        );
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
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter == Onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter == Onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);

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
