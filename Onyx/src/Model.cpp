#pragma warning(disable: 4267)

#include "Model.h"

#include <OBJ_Loader.h>

#include "Shader.h"
#include "Math.h"

using Onyx::Math::Vec4;

void onyx_add_malloc(void*, bool);

Onyx::Model::Model() {}

Onyx::Model& Onyx::Model::LoadOBJ(const std::string& filepath)
{
	Model* model = new Model;
	onyx_add_malloc(model, false);
	std::string slash = filepath.find("/") ? "/" : "\\";
	model->directory = filepath.substr(0, filepath.find_last_of(slash));
	
	objl::Loader loader;
	if (!loader.LoadFile(filepath))
	{
		Err("Unable to load OBJ model: \"" + filepath + "\"");
		return *model;
	}

	for (const objl::Mesh& objlMesh : loader.LoadedMeshes)
	{
		bool hasMaterial = objlMesh.MeshMaterial.name != "";
		bool hasTexture = objlMesh.MeshMaterial.map_Kd != "";

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

		ModelUnit unit;
		unit.name = objlMesh.MeshName;

		unit.mesh = Mesh(
			VertexBuffer(vertices->data(), vertices->size() * sizeof(float), VertexFormat::VNT),
			IndexBuffer(indices->data(), indices->size() * sizeof(uint))
		);

		if (hasTexture) {
			unit.texture = Texture::Load(model->directory + "/" + objlMesh.MeshMaterial.map_Kd);
			unit.shader = Shader::VNT();
		}
		else if (hasMaterial) unit.shader = Shader::VN_Color(Vec4(objlMesh.MeshMaterial.Kd.X, objlMesh.MeshMaterial.Kd.Y, objlMesh.MeshMaterial.Kd.Z, 1.0f));
		else unit.shader = Shader::VN_Color(Vec4(1.0f));

		model->data.push_back(unit);

		delete vertices;
		delete indices;
	}

	return *model;
}
