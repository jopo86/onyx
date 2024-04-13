#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "ModelUnit.h"

namespace Onyx
{

	class Model
	{
		friend class ModelRenderable;
	public:
		Model();

		/*
			Loads a model from an OBJ file.

			There are several things to note here:
			The model is created on the heap to prevent stack overflow with large models.
			The model returned is the dereferenced (heap) model pointer.
			The library cleans up the heap memory automatically when it is terminated.
			If there is no .mtl (material) file in the same directory as the .obj file, the object will be completely white.
			Transparency is currently not supported.

			Credit to Bly7 on GitHub for the OBJ Loader library.
			https://github.com/Bly7/OBJ-Loader
			@param filepath The path of the OBJ file.
		 */
		static Model& LoadOBJ(const std::string& filepath);

	private:

		std::string directory;
		std::vector<ModelUnit> data;
	};
}
