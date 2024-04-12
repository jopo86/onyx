#include "Model.h"

#include <OBJ_Loader.h>

#include "ShaderPresets.h"
#include "Math.h"

using Onyx::Math::Vec4;

Onyx::Model::Model()
{

}

Onyx::Model* Onyx::Model::LoadOBJ(const std::string& filepath)
{
    Model* model = new Model;
    AddMalloc(model, false);
    std::string slash = filepath.find("/") ? "/" : "\\";
    model->directory = filepath.substr(0, filepath.find_last_of(slash));
    
    objl::Loader loader;
    if (!loader.LoadFile(filepath))
    {
        Err("Unable to load OBJ model: \"" + filepath + "\"");
        return model;
    }

    for (const objl::Mesh& objlMesh : loader.LoadedMeshes)
    {
        std::vector<float>* vertices = new std::vector<float>;

        for (const objl::Vertex& vertex : objlMesh.Vertices)
        {
            vertices->push_back(vertex.Position.X);
            vertices->push_back(vertex.Position.Y);
            vertices->push_back(vertex.Position.Z);

            vertices->push_back(vertex.Normal.X);
            vertices->push_back(vertex.Normal.Y);
            vertices->push_back(vertex.Normal.Z);

            vertices->push_back(vertex.TextureCoordinate.X);
            vertices->push_back(vertex.TextureCoordinate.Y);
        }

        std::vector<uint>* indices = new std::vector<uint>;
        for (uint index : objlMesh.Indices)
        {
            indices->push_back(index);
        }

        AddMalloc(vertices, false);
        AddMalloc(indices, false);

        model->meshes.push_back(Mesh(
            VertexArray(vertices->data(), vertices->size(), VertexFormat::VNT),
            IndexArray(indices->data(), indices->size())
        ));

        bool hasTexture = objlMesh.MeshMaterial.map_Kd != "";
            
        model->textures.push_back(
            hasTexture ?
            Texture(
                ImageData::Load(model->directory + "/" + objlMesh.MeshMaterial.map_Kd)
            )
            : Texture()
        );

        if (hasTexture) model->shaders.push_back(ShaderPresets::VNT());
        else
        {
            model->shaders.push_back(ShaderPresets::VN_Color(Vec4(objlMesh.MeshMaterial.Kd.X, objlMesh.MeshMaterial.Kd.Y, objlMesh.MeshMaterial.Kd.Z, 1.0f)));
        }
    }

    return model;
}
