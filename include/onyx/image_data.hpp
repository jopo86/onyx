#pragma once

#include <onyx/core.hpp>

namespace onyx
{
    enum class ImageFormat
    {
        Null = 0,
        Grayscale = 1,
        GrayscaleAlpha = 2,
        RGB = 3,
        RGBA = 4,
        Other = 5
    };

    class ImageData : public Disposable
    {
    public:
        ImageData();
        
        static ImageData load(const std::string& filepath, bool* result = nullptr);

        u8* get_pixels() const;
        int get_width() const;
        int get_height() const;
        ImageFormat get_format() const;

        void dispose();

    private:
        u8* pixels;
        int width, height;
        ImageFormat format;
    };
}
