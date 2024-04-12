#pragma once


#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Onyx
{

	class Model
	{
	public:
		Model();

		/*
			Loads a model from an OBJ file.
			Credit to Bly7 on GitHub for the OBJ Loader library.
			https://github.com/Bly7/OBJ-Loader
			@param filepath The path of the OBJ file.
		 */
		static Model* LoadOBJ(const std::string& filepath);

		std::string directory;

		std::vector<Mesh> meshes;
		std::vector<Texture> textures;
		std::vector<Shader> shaders;
	};
}
