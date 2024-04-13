#include "ModelUnit.h"

Onyx::ModelUnit::ModelUnit() {}

Onyx::ModelUnit::ModelUnit(const std::string& name, Mesh& mesh, Texture& texture, Shader& shader) :
    name(name), mesh(mesh), texture(texture), shader(shader)
{}
