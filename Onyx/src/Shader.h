#pragma once

#include <glad/glad.h>

#include "Core.h"
#include "ErrorHandler.h"
#include "Math.h"

namespace Onyx
{
	/*
		@brief A class to represent a shader.
		This class takes GLSL shader source code and compiles it into a usable shader object.
		Most shader needs are covered by the ShaderPresets namespace.
		This class is disposable.
	 */
	class Shader : public Disposable
	{
	public:
		/*
			@brief Creates an empty Shader object.
			Trying to use a shader constructed like this will most likely result in errors.
		 */
		Shader();

		/*
			@brief Creates a new Shader object from the specified vertex and fragment shader source code.
			This function may cause errors, it is recommended to use the overload with an error handler.
			@param vertSource The vertex shader source code.
			@param fragSource The fragment shader source code.
		 */
		Shader(const char* vertSource, const char* fragSource);

		/*
			@brief Creates a new Shader object from another shader object.
		 !	This function does not copy the shader data, rather the shader program ID.
		 !	This means that the shader data is shared, and disposing of one shader will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other shader object.
		*/
		Shader(const Shader& other);

		/*
			@brief Uses the shader.
			Not needed if using renderables.
		 */
		void use() const;

		/*
			@brief Gets the ID of the OpenGL shader program.
			Access to the program ID is provided for the library, as well as for advanced users.
			@return The ID of the OpenGL shader program.
		 */
		uint getProgramID() const;

		/*
			@brief Gets the vertex shader source code.
			@return The vertex shader source code.
		 */
		const char* getVertSource() const;

		/*
			@brief Gets the fragment shader source code.
			@return The fragment shader source code.
		 */
		const char* getFragSource() const;

		/*
			@brief Sets a boolean uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setBool(const char* varName, bool val);

		/*
			@brief Sets an integer uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setInt(const char* varName, int val);

		/*
			@brief Sets an unsigned integer uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setUint(const char* varName, uint val);

		/*
			@brief Sets a float uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setFloat(const char* varName, float val);

		/*
			@brief Sets a double uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setDouble(const char* varName, double val);

		/*
			@brief Sets a vec2 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setVec2(const char* varName, const Math::Vec2& val);

		/*
			@brief Sets a vec3 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setVec3(const char* varName, const Math::Vec3& val);

		/*
			@brief Sets a vec4 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setVec4(const char* varName, const Math::Vec4& val);

		/*
			@brief Sets a dvec2 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setDVec2(const char* varName, const Math::DVec2& val);

		/*
			@brief Sets a dvec3 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setDVec3(const char* varName, const Math::DVec3& val);

		/*
			@brief Sets a dvec4 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setDVec4(const char* varName, const Math::DVec4& val);

		/*
			@brief Sets a ivec2 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec2(const char* varName, const Math::IVec2& val);

		/*
			@brief Sets a ivec3 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec3(const char* varName, const Math::IVec3& val);

		/*
			@brief Sets a ivec4 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec4(const char* varName, const Math::IVec4& val);

		// TODO: UVecs

		/*
			@brief Sets a 2x2 matrix uniform variable in the shader.
			This function is the exact same as setMat2().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat2x2(const char* varName, const Math::Mat2x2& val, bool normalize = false);

		/*
			@brief Sets a 2x2 matrix uniform variable in the shader.
			This function is the exact same as setMat2x2().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat2(const char* varName, const Math::Mat2& val, bool normalize = false);

		/*
			@brief Sets a 2x3 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat2x3(const char* varName, const Math::Mat2x3& val, bool normalize = false);

		/*
			@brief Sets a 2x4 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat2x4(const char* varName, const Math::Mat2x4& val, bool normalize = false);

		/*
			@brief Sets a 3x2 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat3x2(const char* varName, const Math::Mat3x2& val, bool normalize = false);

		/*
			@brief Sets a 3x3 matrix uniform variable in the shader.
			This function is the exact same as setMat3().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat3x3(const char* varName, const Math::Mat3x3& val, bool normalize = false);

		/*
			@brief Sets a 3x3 matrix uniform variable in the shader.
			This function is the exact same as setMat3x3().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat3(const char* varName, const Math::Mat3& val, bool normalize = false);

		/*
			@brief Sets a 3x4 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat3x4(const char* varName, const Math::Mat3x4& val, bool normalize = false);

		/*
			@brief Sets a 4x2 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat4x2(const char* varName, const Math::Mat4x2& val, bool normalize = false);

		/*
			@brief Sets a 4x3 matrix uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat4x3(const char* varName, const Math::Mat4x3& val, bool normalize = false);

		/*
			@brief Sets a 4x4 matrix uniform variable in the shader.
			This function is the exact same as setMat4().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat4x4(const char* varName, const Math::Mat4x4& val, bool normalize = false);

		/*
			@brief Sets a 4x4 matrix uniform variable in the shader.
			This function is the exact same as setMat4x4().
			@param varName The name of the variable.
			@param val The value to set the variable to.
			@param normalize Whether or not to normalize the matrix.
		 */
		void setMat4(const char* varName, const Math::Mat4x4& val, bool normalize = false);

		// TODO: DMats

		/*
			@brief Disposes of the shader.
			This clears up any memory that the object was using.
			This function should be used when the object is no longer needed, such as just before the program ends or the object goes out of scope.
		 */
		void dispose() override;

	private:
		uint prog;
		const char* vertSource,	* fragSource;
	};
}
