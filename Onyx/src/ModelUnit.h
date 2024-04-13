#pragma once

#include <iostream>

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

namespace Onyx
{
    class ModelUnit
    {
    public:
        ModelUnit();
        ModelUnit(const std::string& name, Mesh& mesh, Texture& texture, Shader& shader);

        std::string name;
        Mesh mesh;
        Texture texture;
        Shader shader;
    };
}
