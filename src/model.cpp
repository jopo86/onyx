#include <onyx/model.hpp>

#include <fstream>
#include <string>
#include <vector>

#include <OBJ_Loader.h>

#include <onyx/shader.hpp>
#include <onyx/math_wrappers.hpp>
#include "internal.hpp"

using onyx::math::Vec4;

onyx::Model::Model() {}

onyx::Model& onyx::Model::load_obj(const std::string& filepath, bool* result)
{
	Model* model = new Model;
	onyx_add_malloc(model, false);

	std::ifstream file(filepath);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Model::load_obj(const std::string& filepath, bool* result)",
				.message = "Failed to open file: \"" + filepath + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return *model;
	}
	file.close();

	// Accept both separators regardless of platform; an empty directory means the working directory
	std::size_t last_separator = filepath.find_last_of("/\\");
	model->directory = last_separator == std::string::npos ? "" : filepath.substr(0, last_separator);
	
	objl::Loader loader;
	if (!loader.LoadFile(filepath))
	{
		onyx_err(Error{
				.source_function = "onyx::Model::load_obj(const std::string& filepath, bool* result)",
				.message = "File found, but failed to load model from: \"" + filepath + "\"",
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
			VertexBuffer(vertices->data(), static_cast<u32>(vertices->size() * sizeof(float)), VertexFormat::PNT),
			IndexBuffer(indices->data(), static_cast<u32>(indices->size() * sizeof(u32)))
		);

		bool texture_result = false;
		if (has_texture)
		{
			std::string texture_path = model->directory.empty() ? objl_mesh.MeshMaterial.map_Kd : model->directory + "/" + objl_mesh.MeshMaterial.map_Kd;
			unit.texture = Texture::load(texture_path, &texture_result);
			if (!texture_result)
			{
				onyx_warn(Warning{
						.source_function = "onyx::Model::load_obj(const std::string& filepath, bool* result)",
						.message = "Failed to load texture \"" + texture_path + "\" for mesh \"" + objl_mesh.MeshName + "\", using the material color instead.",
						.how_to_fix = "Ensure the texture referenced by the .mtl file exists relative to the .obj file.",
						.severity = Warning::Severity::Med
					}
				);
			}
		}

		if (has_texture && texture_result) unit.shader = Shader::pnt();
		else if (has_material) unit.shader = Shader::pn_color(Vec4(objl_mesh.MeshMaterial.Kd.X, objl_mesh.MeshMaterial.Kd.Y, objl_mesh.MeshMaterial.Kd.Z, 1.0f));
		else unit.shader = Shader::pn_color(Vec4(1.0f));

		model->data.push_back(unit);

		delete vertices;
		delete indices;
	}

	if (result != nullptr) *result = true;
	return *model;
}
