#pragma once

#include "Core.h"

namespace Onyx
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
        
        static ImageData Load(const std::string& filepath, bool* result = nullptr);

        ubyte* getPixels() const;
        int getWidth() const;
        int getHeight() const;
        ImageFormat getFormat() const;

        void dispose();

    private:
        ubyte* m_pixels;
        int m_width, m_height;
        ImageFormat m_format;
    };
}
