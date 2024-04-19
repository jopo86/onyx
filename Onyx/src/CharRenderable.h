#pragma once

#include <iostream>

#include "Core.h"
#include "Font.h"

namespace Onyx
{
    /*
        @brief A class to represent a single renderable text character.
        Used by the TextRenderable class.
     */
    class CharRenderable : public Disposable
    {
    public:
        /*
            @brief Creates an empty CharRenderable.
         */
        CharRenderable();

        /*
            @brief Creates a CharRenderable for the specified character and font.
            @param c The character to render.
            @param font The font to use for rendering.
            @param advance The offset of the character on the x-axis.
         */
        CharRenderable(char c, const Font& font, uint advance = 0);

        /*
            @brief Renders the character.
         */
        void render();

        /*
            @brief Gets the character.
            @return The character.
         */
        char getChar() const;

        /*
            @brief Gets the character mesh's VAO.
            @return The VAO.
         */
        uint getVAO() const;
        
        /*
            @brief Gets the character mesh's VBO.
            @return The VBO.
         */
        uint getVBO() const;

        /*
            @brief Gets the character mesh's texture ID.
            @return The texture ID.
         */
        uint getTextureID() const;

        /*
            @brief Disposes of the character.
            Cleans up memory occupied by its mesh and texture.
         */
        void dispose() override;

    private:
        char c;
        uint vao, vbo, tex;
    };
}
