#include "texture.h"

#include <fstream>

#include <glad/glad.h>

#include <stbi/stb_image.h>

void onyx_err(const onyx::Error&);

onyx::Texture::Texture()
{
	this->tex = 0;
}

onyx::Texture::Texture(const Texture& other)
{
	this->tex = other.tex;
}

onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)
{
	this->tex = 0;

	if (texture_wrap == onyx::TextureWrap::Null)
	{
		onyx_err(Error{
				.source_function = "onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
				.message = "Texture wrap option cannot be null",
				.how_to_fix = "Enter a valid texture wrap option."
			}
		);
		return;
	}

	if (min_filter == onyx::TextureFilter::Null)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Minification filter option cannot be null",
			.how_to_fix = "Enter a valid minification filter option."
			}
		);
		return;
	}

	if (mag_filter == onyx::TextureFilter::Null)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Magnification filter option cannot be null",
			.how_to_fix = "Enter a valid magnification filter option."
			}
		);
		return;
	}

	if (image_data.get_format() == ImageFormat::Null)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Image data format cannot be null",
			.how_to_fix = "Ensure the image data is valid."
			}
		);
		return;
	}

	if (image_data.get_format() != ImageFormat::RGB && image_data.get_format() != ImageFormat::RGBA)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::Texture(const ImageData& image_data, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Image data format must be RGB or RGBA",
			.how_to_fix = "Ensure the image data is in RGB or RGBA format."
			}
		);
		return;
	}

	this->tex = 0;

	glGenTextures(1, &this->tex);
	glBindTexture(GL_TEXTURE_2D, this->tex);

	switch (texture_wrap)
	{
	case onyx::TextureWrap::Repeat:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;

	case onyx::TextureWrap::MirroredRepeat:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		break;

	case onyx::TextureWrap::ClampToEdge:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter == onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter == onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, image_data.get_format() == ImageFormat::RGBA ? GL_RGBA : GL_RGB, image_data.get_width(), image_data.get_height(), 0, image_data.get_format() == ImageFormat::RGBA ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image_data.get_pixels());
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

onyx::Texture onyx::Texture::load(const std::string& filepath, bool* result, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)
{
	std::ifstream file(filepath);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Texture::load(const std::string& filepath, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
				.message = "File not found (or access denied): \"" + filepath + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		if (result != nullptr) *result = false;
		return Texture();
	}
	file.close();

	if (texture_wrap == onyx::TextureWrap::Null)
	{
		onyx_err(Error{
				.source_function = "onyx::Texture::load(const std::string& filepath, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
				.message = "Texture wrap option cannot be null",
				.how_to_fix = "Enter a valid texture wrap option."
			}
		);
		if (result != nullptr) *result = false;
		return Texture();
	}

	if (min_filter == onyx::TextureFilter::Null)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::load(const std::string& filepath, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Minification filter option cannot be null",
			.how_to_fix = "Enter a valid minification filter option."
			}
		);
		if (result != nullptr) *result = false;
		return Texture();
	}

	if (mag_filter == onyx::TextureFilter::Null)
	{
		onyx_err(Error{
			.source_function = "onyx::Texture::load(const std::string& filepath, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
			.message = "Magnification filter option cannot be null",
			.how_to_fix = "Enter a valid magnification filter option."
			}
		);
		if (result != nullptr) *result = false;
		return Texture();
	}

	int width = 0, height = 0, n_channels = 0;

	u8* data = stbi_load(filepath.c_str(), &width, &height, &n_channels, 0);
	if (!data)
	{
		onyx_err(Error{
				.source_function = "onyx::Texture::load(const std::string& filepath, onyx::TextureWrap texture_wrap, onyx::TextureFilter min_filter, onyx::TextureFilter mag_filter)",
				.message = "Found file, but failed to load image data: \"" + filepath + "\"",
				.how_to_fix = "Ensure the file is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
			}
		);
		if (result != nullptr) *result = false;
		return Texture();
	}

	Texture texture;

	texture.tex = 0;

	glGenTextures(1, &texture.tex);
	glBindTexture(GL_TEXTURE_2D, texture.tex);

	switch (texture_wrap)
	{
	case onyx::TextureWrap::Repeat:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;

	case onyx::TextureWrap::MirroredRepeat:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		break;

	case onyx::TextureWrap::ClampToEdge:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter == onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter == onyx::TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, n_channels == 4 ? GL_RGBA : GL_RGB, width, height, 0, n_channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif

	if (result != nullptr) *result = true;
	return texture;
}

void onyx::Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->tex);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

u32 onyx::Texture::get_texture_id() const
{
	return this->tex;
}

void onyx::Texture::dispose()
{
	if (this->disposed) return;
	if (this->tex) glDeleteTextures(1, &this->tex);
	this->tex = 0;
	this->disposed = true;

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}
