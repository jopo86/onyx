#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

namespace Onyx
{

	struct ModelUnit
	{
		std::string name;
		Mesh mesh;
		Texture texture;
		Shader shader;
	};

	class Model
	{
		friend class ModelRenderable;
	public:

		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
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
			@param result A pointer to a boolean that will be set to true if the model was loaded successfully, and false otherwise.
		 */
		static Model& LoadOBJ(const std::string& filepath, bool* result = nullptr);

	private:

		std::string m_directory;
		std::vector<ModelUnit> m_data;
	};
}
