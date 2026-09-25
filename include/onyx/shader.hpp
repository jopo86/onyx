#pragma once

#include <string>
#include <utility>

#include <onyx/core.hpp>
#include <onyx/math_wrappers.hpp>

namespace onyx
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
			@param vert_source The vertex shader source code.
			@param frag_source The fragment shader source code.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
		 */
		Shader(const char* vert_source, const char* frag_source, bool* result = nullptr);

		/*
			@brief Creates a new Shader object from another shader object.
		 !	This function does not copy the shader data, rather the shader program ID.
		 !	This means that the shader data is shared, and disposing of one shader will dispose of the other.
		 !	This is used appropriately in the Renderable class, but should be used elsewhere with caution.
			@param other The other shader object.
		 */
		Shader(const Shader& other);

		/*
			@brief Assigns another shader object to this one.
		 !	Like the copy constructor, this shares the shader program ID rather than copying the data.
			@param other The other shader object.
			@return A reference to this object.
		 */
		Shader& operator=(const Shader& other) = default;

		/*
			@brief Loads a new Shader object from the specified vertex and fragment shader source code file paths.
			@param vert_path The vertex shader file path.
			@param frag_path The fragment shader file path.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
			@return The loaded shader.
		 */
		static Shader load_source(const std::string& vert_path, const std::string& frag_path, bool* result = nullptr);
		
		/*
			@brief Loads a new Shader object from the combined shader source code.
			See https://github.com/jopo86/onyx/wiki/guides#custom-shaders-guide for info on 'combining' shader types into one source file.
			@param combined_path The combined shader source file path.
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
			@return The loaded shader.
		 */
		static Shader load_source(const std::string& combined_path, bool* result = nullptr);

		/*
			@brief Compiles a new Shader object from combined shader source code held in memory.
			Unlike load_source(), this takes the GLSL itself rather than a file path, so it does not
			touch the filesystem. This is how the library compiles its own built-in shaders.
			See https://github.com/jopo86/onyx/wiki/guides#custom-shaders-guide for info on 'combining' shader types into one source file.
			@param combined_source The combined shader source code (vertex code, #switch, fragment code).
			@param result A pointer to a boolean that will be set to true if the shader was successfully compiled, and false otherwise.
			@return The compiled shader.
		 */
		static Shader from_source(const std::string& combined_source, bool* result = nullptr);

		/*
			@brief Loads a new Shader object from the specified shader program binary (already compiled).
			Please note that a binary file that was not saved by Onyx will likely not be successfully loaded with Onyx.
			@param filename The path of the binary file, as saved by save_binary().
			@param result A pointer to a boolean that will be set to true if the shader was successfully loaded, and false otherwise.
			@return The loaded shader.
		 */
		static Shader load_binary(const std::string& filename, bool* result = nullptr);

		/*
			@brief Uses the shader.
			Not needed if using renderables.
		 */
		void use() const;

		/*
			@brief Saves the compiled shader program binary to a file.
			@param dir The directory to save the file to, created if it does not exist. A slash at the end will be ignored. May be empty to use the working directory.
			@param filename The name of the file. Any extension at the end will be replaced with .bin
			@param result A pointer to a boolean that will be set to true if the shader was successfully saved, and false otherwise.
		 */
		void save_binary(const std::string& dir, const std::string& filename, bool* result = nullptr) const;

		/*
			@brief Gets the ID of the OpenGL shader program.
			Access to the program ID is provided for the library, as well as for advanced users.
			@return The ID of the OpenGL shader program.
		 */
		u32 get_program_id() const;

		/*
			@brief Sets a boolean uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_bool(const char* var_name, bool val);

		/*
			@brief Sets an integer uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_int(const char* var_name, int val);

		/*
			@brief Sets an unsigned integer uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_uint(const char* var_name, u32 val);

		/*
			@brief Sets a float uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_float(const char* var_name, float val);

		/*
			@brief Sets a double uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_double(const char* var_name, double val);

		/*
			@brief Sets a vec2 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_vec2(const char* var_name, const math::Vec2& val);

		/*
			@brief Sets a vec3 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_vec3(const char* var_name, const math::Vec3& val);

		/*
			@brief Sets a vec4 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_vec4(const char* var_name, const math::Vec4& val);

		/*
			@brief Sets a dvec2 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_dvec2(const char* var_name, const math::DVec2& val);

		/*
			@brief Sets a dvec3 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_dvec3(const char* var_name, const math::DVec3& val);

		/*
			@brief Sets a dvec4 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_dvec4(const char* var_name, const math::DVec4& val);

		/*
			@brief Sets an ivec2 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_ivec2(const char* var_name, const math::IVec2& val);

		/*
			@brief Sets an ivec3 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_ivec3(const char* var_name, const math::IVec3& val);

		/*
			@brief Sets an ivec4 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_ivec4(const char* var_name, const math::IVec4& val);

		/*
			@brief Sets a uvec2 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_uvec2(const char* var_name, const math::UVec2& val);

		/*
			@brief Sets a uvec3 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_uvec3(const char* var_name, const math::UVec3& val);

		/*
			@brief Sets a uvec4 uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
		 */
		void set_uvec4(const char* var_name, const math::UVec4& val);

		/*
			@brief Sets a 2x2 matrix uniform variable in the shader.
			This function is the exact same as set_mat2().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat2x2(const char* var_name, const math::Mat2x2& val, bool transpose = false);

		/*
			@brief Sets a 2x2 matrix uniform variable in the shader.
			This function is the exact same as set_mat2x2().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat2(const char* var_name, const math::Mat2& val, bool transpose = false);

		/*
			@brief Sets a 2x3 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat2x3(const char* var_name, const math::Mat2x3& val, bool transpose = false);

		/*
			@brief Sets a 2x4 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat2x4(const char* var_name, const math::Mat2x4& val, bool transpose = false);

		/*
			@brief Sets a 3x2 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat3x2(const char* var_name, const math::Mat3x2& val, bool transpose = false);

		/*
			@brief Sets a 3x3 matrix uniform variable in the shader.
			This function is the exact same as set_mat3().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat3x3(const char* var_name, const math::Mat3x3& val, bool transpose = false);

		/*
			@brief Sets a 3x3 matrix uniform variable in the shader.
			This function is the exact same as set_mat3x3().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat3(const char* var_name, const math::Mat3& val, bool transpose = false);

		/*
			@brief Sets a 3x4 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat3x4(const char* var_name, const math::Mat3x4& val, bool transpose = false);

		/*
			@brief Sets a 4x2 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat4x2(const char* var_name, const math::Mat4x2& val, bool transpose = false);

		/*
			@brief Sets a 4x3 matrix uniform variable in the shader.
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat4x3(const char* var_name, const math::Mat4x3& val, bool transpose = false);

		/*
			@brief Sets a 4x4 matrix uniform variable in the shader.
			This function is the exact same as set_mat4().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat4x4(const char* var_name, const math::Mat4x4& val, bool transpose = false);

		/*
			@brief Sets a 4x4 matrix uniform variable in the shader.
			This function is the exact same as set_mat4x4().
			@param var_name The name of the variable.
			@param val The value to set the variable to.
			@param transpose Whether OpenGL should transpose the matrix when uploading it (false for the library's column-major matrices).
		 */
		void set_mat4(const char* var_name, const math::Mat4& val, bool transpose = false);

		void dispose() override;

	private:
		u32 prog;

		static std::pair<std::string, std::string> parse_combined(const std::string& combined_path, bool* result);

		// Splits already-loaded combined source into { vertex, fragment } at the #switch line.
		static std::pair<std::string, std::string> split_combined_source(const std::string& source, const std::string& origin, bool* result);

	public:
		/*
			@brief Returns a shader that colors the mesh the specified color.
			Meant for vertex format P, compatible with all formats.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting shader.
		 */
		static Shader p_color(onyx::math::Vec4 rgba);

		/*
			@brief Returns a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			Meant for vertex format P, compatible with all formats.
			@return The resulting shader.
		 */
		static Shader p_xyz_to_rgb();

		/*
			@brief Returns a shader that colors the mesh with the colors found in the vertex array.
			Meant for vertex format pc, compatible with any vertex format that provides positions and colors.
			@return The resulting shader.
		 */
		static Shader pc();

		/*
			@brief Returns a shader that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format pt, compatible with any vertex format that provides positions and texture coordinates.
			@return The resulting shader.
		 */
		static Shader pt();

		/*
			@brief Returns a shader that colors/textures the mesh with a blend of the colors and texture coordinates found in the vertex array.
			Meant for vertex format pct, compatible with any vertex format that provides positions, colors, and texture coordinates.
			@return The resulting shader.
		 */
		static Shader pct();

		/*
			@brief Returns a shader that colors the mesh the specified color.
			Meant for vertex format PN, compatible with any vertex format that provides positions and normals.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1.
			@return The resulting shader.
		 */
		static Shader pn_color(onyx::math::Vec4 rgba);

		/*
			@brief Returns a shader that uses the XYZ position of each vertex as the RGB color of that vertex, and blends the colors in between vertices.
			Meant for vertex format PN, compatible with any vertex format that provides positions and normals.
			@return The resulting shader.
		 */
		static Shader pn_xyz_to_rgb();

		/*
			@brief Returns a shader that colors the mesh with the normals found in the vertex array.
			Meant for vertex format pnc, compatible with any vertex format that provides positions, normals, and colors.
			@return The resulting shader.
		 */
		static Shader pnc();

		/*
			@brief Returns a shader that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format pnt, compatible with any vertex format that provides positions, normals, and texture coordinates.
			@return The resulting shader.
		 */
		static Shader pnt();

		/*
			@brief Returns a shader that colors/textures the mesh with a blend of the colors, normals, and texture coordinates found in the vertex array.
			Compatible only with vertex format pnct.
			@return The resulting shader.
		 */
		static Shader pnct();

		/*
			@brief Returns a shader for UI elements that colors the mesh the specified color.
			Meant for vertex format P, compatible with all formats.
			@param rgba The color, specified as red, green, blue, and alpha (transparency) values ranging from 0 to 1
			@return The resulting shader.
		 */
		static Shader p_ui_color(onyx::math::Vec4 rgba);

		/*
			@brief Returns a shader for UI elements that textures the mesh with the texture coordinates found in the vertex array.
			Meant for vertex format pt, compatible with any vertex format that provides positions and texture coordinates.
			@return The resulting shader.
		 */
		static Shader pt_ui();

		/*
			@brief Returns a shader for UI text elements.
			Incompatible with any vertex format, only used by `TextRenderable`.
			@return The resulting shader.
		 */
		static Shader ui_text();

		/*
			@brief Returns a shader for 3D text elements.
			Incompatible with any vertex format, only used by `TextRenderable3D`.
			@return The resulting shader.
		 */
		static Shader text();
	};
}
