#include <onyx/image_data.hpp>

#include <fstream>

#include <stbi/stb_image.h>

void onyx_err(const onyx::Error&);

onyx::ImageData::ImageData()
{
    this->pixels = nullptr;
    this->width = this->height = 0;
    this->format = ImageFormat::Null;
}

onyx::ImageData onyx::ImageData::load(const std::string& filepath, bool* result)
{
    ImageData retval;

    std::ifstream file(filepath);
    if (!file.is_open())
    {
        onyx_err(Error{
            .source_function = "onyx::ImageData::load(const std::string& filepath, bool* result)",
            .message = "File not found (or access denied): \"" + filepath + "\"",
            .how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
        });
        if (result) *result = false;
        return retval;
    }
    file.close();

    int n_channels = 0;
    retval.pixels = stbi_load(filepath.c_str(), &retval.width, &retval.height, &n_channels, 0);
    if (!retval.pixels)
    {
        onyx_err(Error{
            .source_function = "onyx::ImageData::load(const std::string& filepath, bool* result)",
            .message = "Found file, but failed to load image data: \"" + filepath + "\"",
            .how_to_fix = "Ensure the file is a valid image file. Supported formats: .jpg/.jpeg, .png, .tga, .bmp, .psd, .gif, .hdr, .pic, .pnm"
        });
        if (result) *result = false;
        return retval;
    }

    if (n_channels >= 5) retval.format = ImageFormat::Other;
    else retval.format = (ImageFormat)n_channels;

    if (result) *result = true;
    return retval;
}

u8* onyx::ImageData::get_pixels() const
{
    return this->pixels;
}

int onyx::ImageData::get_width() const
{
    return this->width;
}

int onyx::ImageData::get_height() const
{
    return this->height;
}

onyx::ImageFormat onyx::ImageData::get_format() const
{
    return this->format;
}

void onyx::ImageData::dispose()
{
    stbi_image_free(this->pixels);
    this->width = this->height = 0;
    this->format = ImageFormat::Null;
}
