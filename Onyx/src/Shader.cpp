#include "Shader.h"

#include <fstream>
#include <glad/glad.h>

#include "FileUtils.h"

bool onyx_is_ehandler_nullptr();
void onyx_err(const Onyx::Error&);

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::DVec2,
Onyx::Math::DVec3, Onyx::Math::DVec4, Onyx::Math::IVec2, Onyx::Math::IVec3,
Onyx::Math::IVec4, Onyx::Math::UVec2, Onyx::Math::UVec3, Onyx::Math::UVec4,
Onyx::Math::Mat2x2, Onyx::Math::Mat2x3, Onyx::Math::Mat2x4, Onyx::Math::Mat3x2, 
Onyx::Math::Mat3x3, Onyx::Math::Mat3x4, Onyx::Math::Mat4x2,
Onyx::Math::Mat4x3, Onyx::Math::Mat4x4, Onyx::Math::Mat4;


Onyx::Shader::Shader()
{
	m_prog = 0;
}

Onyx::Shader::Shader(const char* vertSource, const char* fragSource)
{
	uint vert = glCreateShader(GL_VERTEX_SHADER);
	uint frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vertSource, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	int result;

	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
	if (!onyx_is_ehandler_nullptr())
	{
		if (!result)
		{
			char infoBuffer[ONYX_BUFFER_SIZE];
			glGetShaderInfoLog(vert, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::Shader(const char *vertSource, const char *fragSource) : vertSource(vertSource), fragSource(fragSource)",
					.message = "Failed to compile a vertex shader, shader has been disposed. OpenGL output shown below: \n" + std::string(infoBuffer) + "\n"
				}
			);
			if (vert) glDeleteShader(vert);
			if (frag) glDeleteShader(frag);
			dispose();
			return;
		}
	}

	glCompileShader(frag);
	if (!onyx_is_ehandler_nullptr())
	{
		glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			char infoBuffer[ONYX_BUFFER_SIZE];
			glGetShaderInfoLog(frag, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::Shader(const char *vertSource, const char *fragSource) : vertSource(vertSource), fragSource(fragSource)",
					.message = "Failed to compile a fragment shader, shader has been disposed. OpenGL output shown below: \n" + std::string(infoBuffer) + "\n"
				}
			);
			if (vert) glDeleteShader(vert);
			if (frag) glDeleteShader(frag);
			dispose();
			return;
		}
	}

	m_prog = glCreateProgram();
	glAttachShader(m_prog, vert);
	glAttachShader(m_prog, frag);

	glLinkProgram(m_prog);
	if (!onyx_is_ehandler_nullptr())
	{
		glGetProgramiv(m_prog, GL_LINK_STATUS, &result);
		if (!result)
		{
			char infoBuffer[ONYX_BUFFER_SIZE];
			glGetProgramInfoLog(m_prog, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::Shader(const char *vertSource, const char *fragSource) : vertSource(vertSource), fragSource(fragSource)",
					.message = "Failed to link a shader program, shader has been disposed. OpenGL output shown below: \n" + std::string(infoBuffer) + "\n"
				}
			);
			if (vert) glDeleteShader(vert);
			if (frag) glDeleteShader(frag);
			dispose();
			return;
		}
	}

	glValidateProgram(m_prog);
	if (!onyx_is_ehandler_nullptr())
	{
		glGetProgramiv(m_prog, GL_VALIDATE_STATUS, &result);
		if (!result)
		{
			char infoBuffer[ONYX_BUFFER_SIZE];
			glGetProgramInfoLog(m_prog, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::Shader(const char *vertSource, const char *fragSource) : vertSource(vertSource), fragSource(fragSource)",
					.message = "Failed to validate a shader program, shader has been disposed. OpenGL output shown below: \n" + std::string(infoBuffer) + "\n"
				}
			);
			if (vert) glDeleteShader(vert);
			if (frag) glDeleteShader(frag);
			dispose();
			return;
		}
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Shader::Shader(const Shader& other)
{
	m_prog = other.m_prog;
}

Onyx::Shader Onyx::Shader::LoadSource(const std::string& vertPath, const std::string& fragPath)
{
	return Shader(
		FileUtils::ReadLiteral(vertPath),
		FileUtils::ReadLiteral(fragPath)
	);
}

Onyx::Shader Onyx::Shader::LoadBinary(const std::string& binPath)
{
	Shader shader;
	shader.m_prog = glCreateProgram();

	std::ifstream file(binPath, std::ios::binary);

	if (!onyx_is_ehandler_nullptr()) if (!file.is_open())
	{
		onyx_err(Error{
			   .sourceFunction = "Onyx::Shader::LoadBinary(const std::string& binPath)",
			   .message = "File not found (or access denied): \"" + binPath + "\"",
			   .howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		shader.dispose();
		return shader;
	}

	std::istreambuf_iterator<char> startIt(file), endIt;
	std::vector<char> buffer(startIt, endIt);
	file.close();

	/*std::string formatStr;
	char cur = 0;
	for (int i = 7; cur != '\n'; i++)
	{
		cur = buffer[i];
		if (cur == '\n') continue;
		formatStr += cur;
	}*/

	uint format = 36385;

	char* data = buffer.data();

	glProgramBinary(shader.m_prog, format, data, buffer.size());

	if (!onyx_is_ehandler_nullptr())
	{
		int result;
		glGetProgramiv(shader.m_prog, GL_LINK_STATUS, &result);
		if (!result)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::LoadBinary(const std::string& binPath)",
					.message = "Failed to link loaded shader program.",
				}
			);
		}
	}

	return shader;
}

void Onyx::Shader::use() const
{
	glUseProgram(m_prog);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::saveBinary(const std::string& dir, const std::string& filename) const
{
	if (!onyx_is_ehandler_nullptr())
	{
		int nFormats = 0;
		glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &nFormats);

		if (nFormats < 1)
		{
			onyx_err(Error{
					.sourceFunction = "Onyx::Shader::saveBinary(const std::string& dir, const std::string& filename)",
					.message = "Graphics driver does not support any shader binary formats.",
					.howToFix = "Ensure your graphics drivers are up to date."
				}
			);
		}
	}

	int len = 0;
	glGetProgramiv(m_prog, GL_PROGRAM_BINARY_LENGTH, &len);

	ubyte* buffer = new ubyte[len];
	uint format = 0;
	glGetProgramBinary(m_prog, len, nullptr, &format, buffer);

	std::string path = dir.substr(0, dir[dir.length() - 1] == '/' || dir[dir.length() - 1] == '\\' ? dir.length() - 1 : dir.length()) + "/" + filename.substr(0, filename.find_last_of(".") != -1 ? filename.find_last_of(".") : filename.length()) + ".bin";

	std::string line1 = "format:" + std::to_string(format) + "\n";

	std::ofstream file(path, std::ios::binary);
	//file.write(line1.c_str(), line1.length());
	file.write(reinterpret_cast<char*>(buffer), len);
	file.close();

	delete[] buffer;
}

uint Onyx::Shader::getProgramID() const
{
	return m_prog;
}

void Onyx::Shader::setBool(const char* varName, bool val)
{
	glUniform1i(glGetUniformLocation(m_prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setInt(const char* varName, int val)
{
	glUniform1i(glGetUniformLocation(m_prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUint(const char* varName, uint val)
{
	glUniform1ui(glGetUniformLocation(m_prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setFloat(const char* varName, float val)
{
	glUniform1f(glGetUniformLocation(m_prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDouble(const char* varName, double val)
{
	glUniform1d(glGetUniformLocation(m_prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec2(const char* varName, const Vec2& val)
{
	glUniform2fv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec3(const char* varName, const Vec3& val)
{
	glUniform3fv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec4(const char* varName, const Vec4& val)
{
	glUniform4fv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec2(const char* varName, const DVec2& val)
{
	glUniform2dv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec3(const char* varName, const DVec3& val)
{
	glUniform3dv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec4(const char* varName, const DVec4& val)
{
	glUniform4dv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec2(const char* varName, const IVec2& val)
{
	glUniform2iv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec3(const char* varName, const IVec3& val)
{
	glUniform3iv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec4(const char* varName, const IVec4& val)
{
	glUniform4iv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec2(const char* varName, const UVec2& val)
{
	glUniform2uiv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec3(const char* varName, const UVec3& val)
{
	glUniform3uiv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec4(const char* varName, const UVec4& val)
{
	glUniform4uiv(glGetUniformLocation(m_prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x2(const char* varName, const Mat2x2& val, bool normalize)
{
	glUniformMatrix2fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2(const char* varName, const Mat2x2& val, bool normalize)
{
	glUniformMatrix2fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x3(const char* varName, const Mat2x3& val, bool normalize)
{
	glUniformMatrix2x3fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x4(const char* varName, const Mat2x4& val, bool normalize)
{
	glUniformMatrix2x4fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x2(const char* varName, const Mat3x2& val, bool normalize)
{
	glUniformMatrix3x2fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x3(const char* varName, const Mat3x3& val, bool normalize)
{
	glUniformMatrix3fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3(const char* varName, const Mat3x3& val, bool normalize)
{
	glUniformMatrix3fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x4(const char* varName, const Mat3x4& val, bool normalize)
{
	glUniformMatrix3x4fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x2(const char* varName, const Mat4x2& val, bool normalize)
{
	glUniformMatrix4x2fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x3(const char* varName, const Mat4x3& val, bool normalize)
{
	glUniformMatrix4x3fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x4(const char* varName, const Mat4x4& val, bool normalize)
{
	glUniformMatrix4fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4(const char* varName, const Mat4x4& val, bool normalize)
{
	glUniformMatrix4fv(glGetUniformLocation(m_prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Shader Onyx::Shader::P_Color(Vec4 rgba)
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/P_Color.bin"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::P_XYZtoRGB()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/P_XYZtoRGB.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PC()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PC.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PT()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PT.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PCT()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PCT.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNC()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PNC.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PN_Color(Vec4 rgba)
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PN_Color.bin"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNT()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PNT.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNCT()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/PNCT.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Color(Onyx::Math::Vec4 rgba)
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/UI_Color.bin"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Texture()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/UI_Texture.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Text()
{
	Shader shader = Shader::LoadBinary(Onyx::Resources("shaders/bin/UI_Text.bin"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

void Onyx::Shader::dispose()
{
	if (m_prog) glDeleteProgram(m_prog);
	m_prog = 0;

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
