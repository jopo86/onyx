#pragma once

#include <iostream>

#include "Core.h"
#include "Math.h"

namespace Onyx
{
	/*
		@brief A class to represent a shader.
	 */
	class Shader : public Disposable
	{
	public:
		/*
			@brief Default constructor, initializes member variables.
			Using an object created with this constructor will result in undefined behavior.
		 */
		Shader();

		/*
			@brief Creates a new Shader object from the specified vertex and fragment shader source code.
			@param vertSource The vertex shader source code.
			@param fragSource The fragment shader source code.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
		 */
		Shader(const char* vertSource, const char* fragSource, bool* result = nullptr);

		

		/*
			@brief Creates a new Shader object from another shader object.
		 !	This function does not copy the shader data, rather the shader program ID.
		 !	This means that the shader data is shared, and disposing of one shader will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other shader object.
		*/
		Shader(const Shader& other);

		/*
			@brief Loads a new Shader object from the specified vertex and fragment shader source code file paths.
			@param vertSource The vertex shader file path.
			@param fragSource The fragment shader file path.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
			@return The loaded shader.
		 */
		static Shader LoadSource(const std::string& vertPath, const std::string& fragPath, bool* result = nullptr);
		
		/*
			@brief Loads a new Shader object from the combined shader source code.
			See https://github.com/jopo86/onyx/wiki/guides#custom-shaders-guide for info on 'combining' shader types into one source file.
			@param combinedSource The combined shader source code.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
			@return The loaded shader.
		 */
		static Shader LoadSource(const std::string& combinedPath, bool* result = nullptr);

		/*
			@brief Loads a new Shader object from the specified shader program binary (already compiled).
			Please note that a binary file that was not saved by Onyx will likely not be successfully loaded with Onyx.
			@param filename The filename, including the path. Extension must be .bin
			@param result A pointer to a boolean that will be set to true if the shader was successfully loaded, and false otherwise.
		 */
		static Shader LoadBinary(const std::string& filename, bool* result = nullptr);

		/*
			@brief Uses the shader.
			Not needed if using renderables.
		 */
		void use() const;

		/*
			@brief Saves the compiled shader program binary to a file.
			@param dir The directory to save the file to. A slash at the end will be ignored.
			@param filename The name of the file. Any extension at the end will be replaced with .bin
			@param result A pointer to a boolean that will be set to true if the shader was successfully saved, and false otherwise.
		 */
		void saveBinary(const std::string& dir, const std::string& filename, bool* result = nullptr) const;

		/*
			@brief Gets the ID of the OpenGL shader program.
			Access to the program ID is provided for the library, as well as for advanced users.
			@return The ID of the OpenGL shader program.
		 */
		uint getProgramID() const;

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
			@brief Sets an ivec2 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec2(const char* varName, const Math::IVec2& val);

		/*
			@brief Sets an ivec3 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec3(const char* varName, const Math::IVec3& val);

		/*
			@brief Sets an ivec4 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setIVec4(const char* varName, const Math::IVec4& val);

		/*
			@brief Sets a uvec2 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setUVec2(const char* varName, const Math::UVec2& val);

		/*
			@brief Sets a uvec3 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setUVec3(const char* varName, const Math::UVec3& val);

		/*
			@brief Sets a uvec4 uniform variable in the shader.
			@param varName The name of the variable.
			@param val The value to set the variable to.
		 */
		void setUVec4(const char* varName, const Math::UVec4& val);

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
		void setMat4(const char* varName, const Math::Mat4& val, bool normalize = false);

		void dispose() override;

	private:
		uint m_prog;

		static std::pair<std::string, std::string> ParseCombined(const std::string& combinedPath, bool* result);

	public:
		/*
			@brief Returns a shader that colors the mesh the specified color.
			Meant for vertex format P, compatible with all formats.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting shader.
		 */
		static Shader P_Color(Onyx::Math::Vec4 rgba);

		/*
			@brief Returns a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			Meant for vertex format P, compatible with all formats.
			@return The resulting shader.
		 */
		static Shader P_XYZtoRGB();

		/*
			@brief Returns a shader that colors the mesh with the colors found in the vertex array.
			Meant for vertex format PC, compatible with any vertex format that provides positions and colors.
			@return The resulting shader.
		 */
		static Shader PC();

		/*
			@brief Returns a shader that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format PT, compatible with any vertex format that provides positions and texture coordinates.
			@return The resulting shader.
		 */
		static Shader PT();

		/*
			@brief Returns a shader that colors/textures the mesh with a blend of the colors and texture coordinates found in the vertex array.
			Meant for vertex format PCT, compatible with any vertex format that provides positions, colors, and texture coordinates.
			@return The resulting shader.
		 */
		static Shader PCT();

		/*
			@brief Returns a shader that colors the mesh the specified color.
			Meant for vertex format PN, compatible with any vertex format that provides positions and normals.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting shader.
		 */
		static Shader PN_Color(Onyx::Math::Vec4 rgba);

		/*
			@brief Returns a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			Meant for vertex format PN, compatible with any vertex format that provides positions and normals.
			@return The resulting shader.
		 */
		static Shader PN_XYZtoRGB();

		/*
			@brief Returns a shader that colors the mesh with the normals found in the vertex array.
			Meant for vertex format PNC, compatible with any vertex format that provides positions, normals, and colors.
			@return The resulting shader.
		 */
		static Shader PNC();

		/*
			@brief Returns a shader that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format PNT, compatible with any vertex format that provides positions, normals, and texture coordinates.
			@return The resulting shader.
		 */
		static Shader PNT();

		/*
			@brief Returns a shader that colors/textures the mesh with a blend of the colors, normals, and texture coordinates found in the vertex array.
			Compatible only with vertex format PNCT.
			@return The resulting shader.
		 */
		static Shader PNCT();

		/*
			@brief Returns a shader for UI elements that colors the mesh the specified color.
			Meant for vertex format P, compatible with all formats.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1
			@return The resulting shader.
		 */
		static Shader P_UI_Color(Onyx::Math::Vec4 rgba);

		/*
			@brief Returns a shader for UI elements that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format PT, compatible with any vertex format that provides positions and texture coordinates.
			@return The resulting shader.
		 */
		static Shader PT_UI();

		/*
			@brief Returns a shader for UI text elements.
			Incompatible with any vertex format, only used by `TextRenderable`.
			@return The resulting shader.
		 */
		static Shader UI_Text();

		/*
			@brief Returns a shader for 3D text elements.
			Incompatible with any vertex format, only used by `TextRenderable3D`.
			@return The resulting shader.
		 */
		static Shader Text();
	};
}
