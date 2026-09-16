#pragma warning(disable: 4267)

#include "model.h"

#include <fstream>

#include <OBJ_Loader.h>

#include "shader.h"
#include "math.h"

using onyx::math::Vec4;

void onyx_add_malloc(void*, bool);
void onyx_err(const onyx::Error&);

onyx::Model::Model() {}

onyx::Model& onyx::Model::load_obj(const std::string& filepath, bool* result)
{
	Model* model = new Model;
	onyx_add_malloc(model, false);

	std::ifstream file(filepath);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Model::load_obj(const std::string& filepath)",
				.message = "Failed to open file: + \"" + filepath + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return *model;
	}
	file.close();

	std::string slash = filepath.find("/") ? "/" : "\\";
	model->directory = filepath.substr(0, filepath.find_last_of(slash));
	
	objl::Loader loader;
	if (!loader.LoadFile(filepath))
	{
		onyx_err(Error{
				.source_function = "onyx::Model::load_obj(const std::string& filepath)",
				.message = "File found, but failed to load model from: + \"" + filepath + "\"",
				.how_to_fix = "Ensure the file is an OBJ file and is not corrupt."
			}
		);
		if (result != nullptr) *result = false;
		return *model;
	}

	for (const objl::Mesh& objl_mesh : loader.LoadedMeshes)
	{
		bool has_material = objl_mesh.MeshMaterial.name != "";
		bool has_texture = objl_mesh.MeshMaterial.map_Kd != "";

		std::vector<float>* vertices = new std::vector<float>;

		for (const objl::Vertex& vertex : objl_mesh.Vertices)
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

		std::vector<u32>* indices = new std::vector<u32>;
		for (u32 index : objl_mesh.Indices)
		{
			indices->push_back(index);
		}

		ModelUnit unit;
		unit.name = objl_mesh.MeshName;

		unit.mesh = Mesh(
			VertexBuffer(vertices->data(), vertices->size() * sizeof(float), VertexFormat::PNT),
			IndexBuffer(indices->data(), indices->size() * sizeof(u32))
		);

		if (has_texture) {
			unit.texture = Texture::load(model->directory + "/" + objl_mesh.MeshMaterial.map_Kd);
			unit.shader = Shader::pnt();
		}
		else if (has_material) unit.shader = Shader::pn_color(Vec4(objl_mesh.MeshMaterial.Kd.X, objl_mesh.MeshMaterial.Kd.Y, objl_mesh.MeshMaterial.Kd.Z, 1.0f));
		else unit.shader = Shader::pn_color(Vec4(1.0f));

		model->data.push_back(unit);

		delete vertices;
		delete indices;
	}

	if (result != nullptr) *result = true;
	return *model;
}
