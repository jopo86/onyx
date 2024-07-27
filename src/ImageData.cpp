#include "ImageData.h"

#include <fstream>

#include <stbi/stb_image.h>

void onyx_err(const Onyx::Error&);

Onyx::ImageData::ImageData()
{
    m_pixels = nullptr;
    m_width = m_height = 0;
    m_format = ImageFormat::Null;
}

Onyx::ImageData Onyx::ImageData::Load(const std::string& filepath, bool* result)
{
    ImageData retval;

    std::ifstream file(filepath);
    if (!file.is_open())
    {
        onyx_err(Error{
            .sourceFunction = "Onyx::ImageData::Load(const std::string& filepath, bool* result)",
            .message = "File not found (or access denied): \"" + filepath + "\"",
            .howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
        });
        if (result) *result = false;
        return retval;
    }
    file.close();

    int nChannels = 0;
    retval.m_pixels = stbi_load(filepath.c_str(), &retval.m_width, &retval.m_height, &nChannels, 0);
    if (!retval.m_pixels)
    {
        onyx_err(Error{
            .sourceFunction = "Onyx::ImageData::Load(const std::string& filepath, bool* result)",
            .message = "Found file, but failed to load image data: \"" + filepath + "\"",
            .howToFix = "Ensure the file is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
        });
        if (result) *result = false;
        return retval;
    }

    if (nChannels >= 5) retval.m_format = ImageFormat::Other;
    else retval.m_format = (ImageFormat)nChannels;

    if (result) *result = true;
    return retval;
}

ubyte* Onyx::ImageData::getPixels() const
{
    return m_pixels;
}

int Onyx::ImageData::getWidth() const
{
    return m_width;
}

int Onyx::ImageData::getHeight() const
{
    return m_height;
}

Onyx::ImageFormat Onyx::ImageData::getFormat() const
{
    return m_format;
}

void Onyx::ImageData::dispose()
{
    stbi_image_free(m_pixels);
    m_width = m_height = 0;
    m_format = ImageFormat::Null;
}
