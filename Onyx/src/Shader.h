#pragma once

#include <glad/glad.h>

#include "Core.h"
#include "ErrorHandler.h"
#include "Math.h"

namespace Onyx
{
	/*
	 * @brief A class to represent a shader.
	 * This class takes GLSL shader source code and compiles it into a usable shader object.
	 * Most shader needs are covered by the ShaderPresets namespace.
	 * This class is disposable.
	 */
	class Shader : public Disposable
	{
	public:
		/*
		 * @brief Creates an empty Shader object.
		 * Trying to use a shader constructed like this will most likely result in errors.
		 */
		Shader();

		/*
		 * @brief Creates a new Shader object from the specified vertex and fragment shader source code.
		 * This function may cause errors, it is recommended to use the overload with an error handler.
		 * @param vertSource The vertex shader source code.
		 * @param fragSource The fragment shader source code.
		 */
		Shader(const char* vertSource, const char* fragSource);

		/*
		 * @brief Creats a new Shader object from the specified vertex and fragment shader source code.
		 * Passes any OpenGL errors to the specified error handler.
		 * @param vertSource The vertex shader source code.
		 * @param fragSource The fragment shader source code.
		 */
		Shader(const char* vertSource, const char* fragSource, ErrorHandler& errorHandler);

		/*
		 * @brief Uses the shader.
		 * Not needed if using renderables.
		 */
		void use();

		/*
		 * @brief Gets the ID of the OpenGL shader program.
		 * Access to the program ID is provided for the library, as well as for advanced users.
		 * @return The ID of the OpenGL shader program.
		 */
		uint getProgramID();

		/*
		 * @brief Gets the vertex shader source code.
		 * @return The vertex shader source code.
		 */
		const char* getVertSource();

		/*
		 * @brief Gets the fragment shader source code.
		 * @return The fragment shader source code.
		 */
		const char* getFragSource();

		/*
		 * @brief Sets a uniform vec4 variable.
		 * @param name The name of the variable.
		 * @param v0 The first vector component.
		 * @param v1 The second vector component.
		 * @param v2 The third vector component.
		 * @param v3 The fourth vector component.
		 */
		void uniform(const char* name, float v0, float v1, float v2, float v3);

		/*
		 * @brief Sets a uniform vec3 variable.
		 * @param name The name of the variable.
		 * @param vec The vector.
		 */
		void uniform(const char* name, Onyx::Math::Vec3 vec);

		/*
		 * @brief Sets a uniform 4x4 matrix variable.
		 * @param name The name of the variable.
		 * @param mat The 4x4 matrix.
		 */
		void uniform(const char* name, Onyx::Math::Mat4 mat);

		/*
		 * @brief Disposes of the shader.
		 * This clears up any memory that the object was using.
		 * This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		uint prog;
		const char* vertSource, * fragSource;
	};
}
