#include <algorithm>
#include <cctype>
#include <exception>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

#include <glad/glad.h>

#include <onyx/file_utils.hpp>
#include <onyx/shader.hpp>
#include <onyx/builtin_shaders.hpp>
#include "internal.hpp"

using onyx::math::Vec2, onyx::math::Vec3, onyx::math::Vec4, onyx::math::DVec2,
onyx::math::DVec3, onyx::math::DVec4, onyx::math::IVec2, onyx::math::IVec3,
onyx::math::IVec4, onyx::math::UVec2, onyx::math::UVec3, onyx::math::UVec4,
onyx::math::Mat2x2, onyx::math::Mat2x3, onyx::math::Mat2x4, onyx::math::Mat3x2, 
onyx::math::Mat3x3, onyx::math::Mat3x4, onyx::math::Mat4x2,
onyx::math::Mat4x3, onyx::math::Mat4x4, onyx::math::Mat4;

onyx::Shader::Shader()
{
	this->prog = 0;
}

onyx::Shader::Shader(const char* vert_source, const char* frag_source, bool* result)
{
	u32 vert = glCreateShader(GL_VERTEX_SHADER);
	u32 frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vert_source, nullptr);
	glShaderSource(frag, 1, &frag_source, nullptr);

	int gl_result;

	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &gl_result);
	if (!gl_result)
	{
		char info_buffer[ONYX_BUFFER_SIZE];
		glGetShaderInfoLog(vert, ONYX_BUFFER_SIZE, nullptr, info_buffer);
		onyx_err(Error{
				.source_function = "onyx::Shader::Shader(const char* vert_source, const char* frag_source, bool* result)",
				.message = "Failed to compile a vertex shader, shader has been disposed. OpenGL output shown below: \n" + std::string(info_buffer) + "\n"
			}
		);
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		if (result != nullptr) *result = false;
		return;
	}

	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &gl_result);
	if (!gl_result)
	{
		char info_buffer[ONYX_BUFFER_SIZE];
		glGetShaderInfoLog(frag, ONYX_BUFFER_SIZE, nullptr, info_buffer);
		onyx_err(Error{
				.source_function = "onyx::Shader::Shader(const char* vert_source, const char* frag_source, bool* result)",
				.message = "Failed to compile a fragment shader, shader has been disposed. OpenGL output shown below: \n" + std::string(info_buffer) + "\n"
			}
		);
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		if (result != nullptr) *result = false;
		return;
	}

	this->prog = glCreateProgram();
	glAttachShader(this->prog, vert);
	glAttachShader(this->prog, frag);

	glLinkProgram(this->prog);
	glGetProgramiv(this->prog, GL_LINK_STATUS, &gl_result);
	if (!gl_result)
	{
		char info_buffer[ONYX_BUFFER_SIZE];
		glGetProgramInfoLog(this->prog, ONYX_BUFFER_SIZE, nullptr, info_buffer);
		onyx_err(Error{
				.source_function = "onyx::Shader::Shader(const char* vert_source, const char* frag_source, bool* result)",
				.message = "Failed to link a shader program, shader has been disposed. OpenGL output shown below: \n" + std::string(info_buffer) + "\n"
			}
		);
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		if (result != nullptr) *result = false;
		return;
	}

	// Validation depends on the current GL state (e.g. it fails on macOS when no VAO is bound),
	// so a failure here is only reported as a warning; the program linked successfully.
	glValidateProgram(this->prog);
	glGetProgramiv(this->prog, GL_VALIDATE_STATUS, &gl_result);
	if (!gl_result)
	{
		char info_buffer[ONYX_BUFFER_SIZE];
		glGetProgramInfoLog(this->prog, ONYX_BUFFER_SIZE, nullptr, info_buffer);
		onyx_warn(Warning{
				.source_function = "onyx::Shader::Shader(const char* vert_source, const char* frag_source, bool* result)",
				.message = "Shader program validation failed against the current OpenGL state (the program itself linked successfully). OpenGL output shown below: \n" + std::string(info_buffer) + "\n",
				.how_to_fix = "This can usually be ignored if the shader renders correctly; validation depends on the state bound at creation time.",
				.severity = Warning::Severity::Low
			}
		);
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

	if (result != nullptr) *result = true;

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

onyx::Shader::Shader(const Shader& other)
{
	this->prog = other.prog;
}

onyx::Shader onyx::Shader::load_source(const std::string& vert_path, const std::string& frag_path, bool* result)
{
	bool vert_result = false, frag_result = false;
	std::string vert_source = file_utils::read(vert_path, &vert_result);
	std::string frag_source = file_utils::read(frag_path, &frag_result);

	if (!vert_result)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::load_source(const std::string& vert_path, const std::string& frag_path, bool* result)",
				.message = "Failed to read vertex shader source file: \"" + vert_path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
	}

	if (!frag_result)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::load_source(const std::string& vert_path, const std::string& frag_path, bool* result)",
				.message = "Failed to read fragment shader source file: \"" + frag_path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
	}

	if (!frag_result || !vert_result)
	{
		if (result != nullptr) *result = false;
		return Shader();
	}

	return Shader(vert_source.c_str(), frag_source.c_str(), result);
}

onyx::Shader onyx::Shader::load_source(const std::string& combined_path, bool* result)
{
	bool parse_result;
	auto [vert_source, frag_source] = parse_combined(combined_path, &parse_result);

	if (!parse_result)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::load_source(const std::string& combined_path, bool* result)",
				.message = "Failed to parse combined shader source file: \"" + combined_path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return Shader();
	}

	return Shader(vert_source.c_str(), frag_source.c_str(), result);
}

onyx::Shader onyx::Shader::from_source(const std::string& combined_source, bool* result)
{
	bool parse_result;
	auto [vert_source, frag_source] = split_combined_source(combined_source, "(in-memory source)", &parse_result);

	if (!parse_result)
	{
		if (result != nullptr) *result = false;
		return Shader();
	}

	return Shader(vert_source.c_str(), frag_source.c_str(), result);
}

onyx::Shader onyx::Shader::load_binary(const std::string& bin_path, bool* result)
{
	Shader shader;

	auto fail = [&](const std::string& message, const std::string& how_to_fix) -> Shader
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::load_binary(const std::string& bin_path, bool* result)",
				.message = message,
				.how_to_fix = how_to_fix
			}
		);
		shader.dispose();
		if (result != nullptr) *result = false;
		return shader;
	};

	std::ifstream file(bin_path, std::ios::binary);

	if (!file.is_open())
	{
		return fail("File not found (or access denied): \"" + bin_path + "\"", "Ensure the file exists, is not locked by another process, and does not explicitly deny access.");
	}

	std::istreambuf_iterator<char> start_it(file), end_it;
	std::vector<char> buffer(start_it, end_it);
	bool read_failed = file.bad();
	file.close();

	if (read_failed)
	{
		return fail("Failed to read shader binary file: \"" + bin_path + "\"", "Ensure the file is not locked by another process.");
	}

	// Expected layout: "format:<GLenum>\n" followed by the raw program binary
	const std::string prefix = "format:";
	std::size_t newline_index = std::find(buffer.begin(), buffer.end(), '\n') - buffer.begin();
	if (buffer.size() < prefix.length() || std::string(buffer.data(), prefix.length()) != prefix || newline_index >= buffer.size())
	{
		return fail("Invalid shader binary file (missing \"format:\" header): \"" + bin_path + "\"", "Only load binaries saved with Shader::save_binary().");
	}

	std::string format_str(buffer.data() + prefix.length(), newline_index - prefix.length());
	u32 format = 0;
	try
	{
		format = (u32)std::stoul(format_str);
	}
	catch (const std::exception&)
	{
		return fail("Invalid shader binary format value \"" + format_str + "\" in file: \"" + bin_path + "\"", "Only load binaries saved with Shader::save_binary().");
	}

	std::size_t start_index = newline_index + 1;
	if (start_index >= buffer.size())
	{
		return fail("Shader binary file contains no program data: \"" + bin_path + "\"", "Only load binaries saved with Shader::save_binary().");
	}

	shader.prog = glCreateProgram();
	glProgramBinary(shader.prog, format, buffer.data() + start_index, (GLsizei)(buffer.size() - start_index));

	int gl_result;
	glGetProgramiv(shader.prog, GL_LINK_STATUS, &gl_result);
	if (!gl_result)
	{
		return fail("Failed to link loaded shader program.", "The binary may have been saved by a different driver or GPU; recompile the shader from source and save it again.");
	}

	if (result != nullptr) *result = true;
	return shader;
}

void onyx::Shader::use() const
{
	glUseProgram(this->prog);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::save_binary(const std::string& dir, const std::string& filename, bool* result) const
{
	int n_formats = 0;
	glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &n_formats);

	if (n_formats < 1)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::save_binary(const std::string& dir, const std::string& filename, bool* result)",
				.message = "Graphics driver does not support any shader binary formats.",
				.how_to_fix = "Ensure your graphics drivers are up to date."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	int len = 0;
	glGetProgramiv(this->prog, GL_PROGRAM_BINARY_LENGTH, &len);

	if (len <= 0)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::save_binary(const std::string& dir, const std::string& filename, bool* result)",
				.message = "Failed to get the shader program binary (the program may be invalid or disposed).",
				.how_to_fix = "Ensure the shader compiled and linked successfully before saving it."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	std::vector<u8> buffer((std::size_t)len);
	u32 format = 0;
	glGetProgramBinary(this->prog, len, nullptr, &format, buffer.data());

	std::string dir_trimmed = dir;
	if (!dir_trimmed.empty() && (dir_trimmed.back() == '/' || dir_trimmed.back() == '\\')) dir_trimmed.pop_back();

	std::size_t ext_index = filename.find_last_of('.');
	std::string path = (dir_trimmed.empty() ? "" : dir_trimmed + "/") + filename.substr(0, ext_index != std::string::npos ? ext_index : filename.length()) + ".bin";

	std::string line1 = "format:" + std::to_string(format) + "\n";

	std::error_code ec;
	if (!dir_trimmed.empty() && !std::filesystem::exists(dir_trimmed, ec)) std::filesystem::create_directories(dir_trimmed, ec);

	std::ofstream file(path, std::ios::binary);
	if (!file.is_open())
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::save_binary(const std::string& dir, const std::string& filename, bool* result)",
				.message = "Failed to open file for writing: \"" + path + "\"",
				.how_to_fix = "Ensure the directory exists or can be created, and that the file is not locked by another process."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	file.write(line1.c_str(), (std::streamsize)line1.length());
	file.write(reinterpret_cast<const char*>(buffer.data()), len);
	file.close();

	if (file.fail())
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::save_binary(const std::string& dir, const std::string& filename, bool* result)",
				.message = "Failed to write shader binary file: \"" + path + "\"",
				.how_to_fix = "Ensure there is enough disk space and the file is not locked by another process."
			}
		);
		if (result != nullptr) *result = false;
		return;
	}

	if (result != nullptr) *result = true;
}

u32 onyx::Shader::get_program_id() const
{
	return this->prog;
}

void onyx::Shader::set_bool(const char* var_name, bool val)
{
	glUniform1i(glGetUniformLocation(this->prog, var_name), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_int(const char* var_name, int val)
{
	glUniform1i(glGetUniformLocation(this->prog, var_name), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_uint(const char* var_name, u32 val)
{
	glUniform1ui(glGetUniformLocation(this->prog, var_name), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_float(const char* var_name, float val)
{
	glUniform1f(glGetUniformLocation(this->prog, var_name), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_double(const char* var_name, double val)
{
	glUniform1d(glGetUniformLocation(this->prog, var_name), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_vec2(const char* var_name, const Vec2& val)
{
	glUniform2fv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_vec3(const char* var_name, const Vec3& val)
{
	glUniform3fv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_vec4(const char* var_name, const Vec4& val)
{
	glUniform4fv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_dvec2(const char* var_name, const DVec2& val)
{
	glUniform2dv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_dvec3(const char* var_name, const DVec3& val)
{
	glUniform3dv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_dvec4(const char* var_name, const DVec4& val)
{
	glUniform4dv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_ivec2(const char* var_name, const IVec2& val)
{
	glUniform2iv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_ivec3(const char* var_name, const IVec3& val)
{
	glUniform3iv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_ivec4(const char* var_name, const IVec4& val)
{
	glUniform4iv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_uvec2(const char* var_name, const UVec2& val)
{
	glUniform2uiv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_uvec3(const char* var_name, const UVec3& val)
{
	glUniform3uiv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_uvec4(const char* var_name, const UVec4& val)
{
	glUniform4uiv(glGetUniformLocation(this->prog, var_name), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat2x2(const char* var_name, const Mat2x2& val, bool transpose)
{
	glUniformMatrix2fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat2(const char* var_name, const Mat2x2& val, bool transpose)
{
	glUniformMatrix2fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat2x3(const char* var_name, const Mat2x3& val, bool transpose)
{
	glUniformMatrix2x3fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat2x4(const char* var_name, const Mat2x4& val, bool transpose)
{
	glUniformMatrix2x4fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat3x2(const char* var_name, const Mat3x2& val, bool transpose)
{
	glUniformMatrix3x2fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat3x3(const char* var_name, const Mat3x3& val, bool transpose)
{
	glUniformMatrix3fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat3(const char* var_name, const Mat3x3& val, bool transpose)
{
	glUniformMatrix3fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat3x4(const char* var_name, const Mat3x4& val, bool transpose)
{
	glUniformMatrix3x4fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat4x2(const char* var_name, const Mat4x2& val, bool transpose)
{
	glUniformMatrix4x2fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat4x3(const char* var_name, const Mat4x3& val, bool transpose)
{
	glUniformMatrix4x3fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat4x4(const char* var_name, const Mat4x4& val, bool transpose)
{
	glUniformMatrix4fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

void onyx::Shader::set_mat4(const char* var_name, const Mat4x4& val, bool transpose)
{
	glUniformMatrix4fv(glGetUniformLocation(this->prog, var_name), 1, transpose, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

static std::string trim_and_to_lower(const std::string& str)
{
	std::size_t start = str.find_first_not_of(' ');
	if (start == std::string::npos) return "";
	std::size_t end = str.find_last_not_of(' ') + 1;

	std::string trimmed = str.substr(start, end - start);
	for (char& c : trimmed)
	{
		c = (char)std::tolower((unsigned char)c);
	}

	return trimmed;
}

void onyx::Shader::dispose()
{
	if (this->disposed) return;
	if (this->prog) glDeleteProgram(this->prog);
	this->prog = 0;
	this->disposed = true;

#if defined(ONYX_GL_DEBUG_HIGH)
	GL_CHECK_ERROR();
#endif
}

std::pair<std::string, std::string> onyx::Shader::parse_combined(const std::string& combined_path, bool* result)
{
	bool file_result;
	std::vector<std::string> lines = file_utils::read_lines(combined_path, &file_result);

	if (!file_result)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::parse_combined(const std::string& combined_path, bool* result)",
				.message = "Failed to read combined shader source file: \"" + combined_path + "\"",
				.how_to_fix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return { "", "" };
	}

	std::string source;
	for (const std::string& line : lines) source += line + "\n";

	return split_combined_source(source, "\"" + combined_path + "\"", result);
}

std::pair<std::string, std::string> onyx::Shader::split_combined_source(const std::string& source, const std::string& origin, bool* result)
{
	std::string vert_source, frag_source;
	bool vert = true;
	bool switched = false;

	std::istringstream stream(source);
	std::string line;

	while (std::getline(stream, line))
	{
		if (!line.empty() && line.back() == '\r') line.pop_back();

		if (trim_and_to_lower(line) == "#switch")
		{
			vert = false;
			switched = true;
			continue;
		}

		if (vert) vert_source += line + "\n";
		else frag_source += line + "\n";
	}

	if (!switched)
	{
		onyx_err(Error{
				.source_function = "onyx::Shader::split_combined_source(const std::string& source, const std::string& origin, bool* result)",
				.message = "Failed to parse combined shader source: " + origin,
				.how_to_fix = "No #switch statement found. Make sure you put #switch between the vertex and fragment code."
			}
		);
		if (result != nullptr) *result = false;
		return { "", "" };
	}

	if (result != nullptr) *result = true;
	return { vert_source, frag_source };
}

// Loads one of the library's built-in shaders.
//
// The GLSL is compiled into the binary (see builtin_shaders.hpp), so this never depends on
// the resource path or on any file shipped next to the library.
//
// These are compiled fresh every run rather than cached to disk. Only the shaders a program
// actually asks for are ever compiled, and each is small enough that the cost is negligible --
// not worth a cache that would have to be invalidated whenever the embedded GLSL changes.
// Shader::save_binary()/load_binary() remain available for callers who want to cache their own
// shaders explicitly, where the caller controls invalidation.
static onyx::Shader load_builtin_shader(const char* source)
{
	return onyx::Shader::from_source(source);
}

onyx::Shader onyx::Shader::p_color(Vec4 rgba)
{
	Shader shader = load_builtin_shader(builtin_shaders::p_color);
	shader.use();
	shader.set_vec4("u_color", rgba);
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::p_xyz_to_rgb()
{
	Shader shader = load_builtin_shader(builtin_shaders::p_xyz_to_rgb);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pc()
{
	Shader shader = load_builtin_shader(builtin_shaders::pc);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pt()
{
	Shader shader = load_builtin_shader(builtin_shaders::pt);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pct()
{
	Shader shader = load_builtin_shader(builtin_shaders::pct);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pnc()
{
	Shader shader = load_builtin_shader(builtin_shaders::pnc);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pn_color(Vec4 rgba)
{
	Shader shader = load_builtin_shader(builtin_shaders::pn_color);
	shader.use();
	shader.set_vec4("u_color", rgba);
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pn_xyz_to_rgb()
{
	Shader shader = load_builtin_shader(builtin_shaders::pn_xyz_to_rgb);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pnt()
{
	Shader shader = load_builtin_shader(builtin_shaders::pnt);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pnct()
{
	Shader shader = load_builtin_shader(builtin_shaders::pnct);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::p_ui_color(Vec4 rgba)
{
	Shader shader = load_builtin_shader(builtin_shaders::p_ui_color);
	shader.use();
	shader.set_vec4("u_color", rgba);
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::pt_ui()
{
	Shader shader = load_builtin_shader(builtin_shaders::pt_ui);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::ui_text()
{
	Shader shader = load_builtin_shader(builtin_shaders::ui_text);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}

onyx::Shader onyx::Shader::text()
{
	Shader shader = load_builtin_shader(builtin_shaders::text);
	shader.use();
	shader.set_mat4("u_model", Mat4::identity());
	shader.set_mat4("u_view", Mat4::identity());
	shader.set_mat4("u_projection", Mat4::identity());
	return shader;
}
