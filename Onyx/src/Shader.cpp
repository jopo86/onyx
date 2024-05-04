#pragma warning (disable: 4267)

#include "Shader.h"

#include <fstream>
#include <filesystem>

#include <glad/glad.h>

#include "FileUtils.h"

void onyx_err(const Onyx::Error&);
void onyx_warn(const Onyx::Warning&);

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

Onyx::Shader::Shader(const char* vertSource, const char* fragSource, bool* result)
{
	uint vert = glCreateShader(GL_VERTEX_SHADER);
	uint frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vertSource, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	int glResult;

	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &glResult);
	if (!glResult)
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
		if (result != nullptr) *result = false;
		return;
	}

	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &glResult);
	if (!glResult)
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
		if (result != nullptr) *result = false;
		return;
	}

	m_prog = glCreateProgram();
	glAttachShader(m_prog, vert);
	glAttachShader(m_prog, frag);

	glLinkProgram(m_prog);
	glGetProgramiv(m_prog, GL_LINK_STATUS, &glResult);
	if (!glResult)
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
		if (result != nullptr) *result = false;
		return;
	}

	glValidateProgram(m_prog);
	glGetProgramiv(m_prog, GL_VALIDATE_STATUS, &glResult);
	if (!glResult)
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
		if (result != nullptr) *result = false;
		return;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

	if (result != nullptr) *result = true;

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Shader::Shader(const Shader& other)
{
	m_prog = other.m_prog;
}

Onyx::Shader Onyx::Shader::LoadSource(const std::string& vertPath, const std::string& fragPath, bool* result)
{
	bool vertResult, fragResult;
	Shader shader(
		FileUtils::ReadLiteral(vertPath, &vertResult),
		FileUtils::ReadLiteral(fragPath, &fragResult)
	);

	if (!vertResult)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Shader::LoadSource(const std::string& vertPath, const std::string& fragPath)",
				.message = "Failed to read vertex shader source file: \"" + vertPath + "\"",
				.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return shader;
	}

	else if (!fragResult)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Shader::LoadSource(const std::string& vertPath, const std::string& fragPath)",
				.message = "Failed to read fragment shader source file: \"" + fragPath + "\"",
				.howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		if (result != nullptr) *result = false;
		return shader;
	}

	if (!fragResult || !vertResult)
	{
		shader.dispose();
		return shader;
	}

	if (result != nullptr) *result = true;
	return shader;
}

Onyx::Shader Onyx::Shader::LoadBinary(const std::string& binPath, bool* result)
{
	Shader shader;
	shader.m_prog = glCreateProgram();

	std::ifstream file(binPath, std::ios::binary);

	if (!file.is_open())
	{
		onyx_err(Error{
			   .sourceFunction = "Onyx::Shader::LoadBinary(const std::string& binPath)",
			   .message = "File not found (or access denied): \"" + binPath + "\"",
			   .howToFix = "Ensure the file exists, is not locked by another process, and does not explicitly deny access."
			}
		);
		file.close();
		shader.dispose();
		if (result != nullptr) *result = false;
		return shader;
	}

	std::istreambuf_iterator<char> startIt(file), endIt;
	std::vector<char> buffer(startIt, endIt);
	file.close();

	std::string formatStr;
	char cur = 0;
	for (int i = 7; cur != '\n'; i++)
	{
		cur = buffer[i];
		if (cur == '\n') continue;
		formatStr += cur;
	}

	uint format = std::stoi(formatStr);
	uint startIndex = 7 + formatStr.length() + 1;

	char* data = buffer.data() + startIndex * sizeof(char);

	glProgramBinary(shader.m_prog, format, data, buffer.size() - startIndex);

	int glResult;
	glGetProgramiv(shader.m_prog, GL_LINK_STATUS, &glResult);
	if (!glResult)
	{
		onyx_err(Error{
				.sourceFunction = "Onyx::Shader::LoadBinary(const std::string& binPath)",
				.message = "Failed to link loaded shader program.",
			}
		);
		shader.dispose();
		if (result != nullptr) *result = false;
		return shader;
	}

	if (result != nullptr) *result = true;
	return shader;
}

void Onyx::Shader::use() const
{
	glUseProgram(m_prog);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::saveBinary(const std::string& dir, const std::string& filename, bool* result) const
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
		if (result != nullptr) *result = false;
		return;
	}

	int len = 0;
	glGetProgramiv(m_prog, GL_PROGRAM_BINARY_LENGTH, &len);

	ubyte* buffer = new ubyte[len];
	uint format = 0;
	glGetProgramBinary(m_prog, len, nullptr, &format, buffer);

	std::string path = dir.substr(0, dir[dir.length() - 1] == '/' || dir[dir.length() - 1] == '\\' ? dir.length() - 1 : dir.length()) + "/" + filename.substr(0, filename.find_last_of(".") != -1 ? filename.find_last_of(".") : filename.length()) + ".bin";

	std::string line1 = "format:" + std::to_string(format) + "\n";

	if (!std::filesystem::exists(dir)) std::filesystem::create_directories(dir);

	std::ofstream file(path, std::ios::binary);
	file.write(line1.c_str(), line1.length());
	file.write(reinterpret_cast<char*>(buffer), len);
	file.close();

	delete[] buffer;

	if (result != nullptr) *result = true;
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
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/P_Color.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/P_Color.vert"), Resources("shaders/src/P_Color.frag"));
		shader.saveBinary(Resources("shaders/bin"), "P_Color");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/P_Color.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::P_Color()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/P_Color.vert"), Resources("shaders/src/P_Color.frag"));
			shader.saveBinary(Resources("shaders/bin"), "P_Color");
		}
	}
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::P_XYZtoRGB()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/P_XYZtoRGB.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/P_XYZtoRGB.vert"), Resources("shaders/src/P_XYZtoRGB.frag"));
		shader.saveBinary(Resources("shaders/bin"), "P_XYZtoRGB");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/P_XYZtoRGB.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::P_XYZtoRGB()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/P_XYZtoRGB.vert"), Resources("shaders/src/P_XYZtoRGB.frag"));
			shader.saveBinary(Resources("shaders/bin"), "P_XYZtoRGB");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PC()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PC.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PC.vert"), Resources("shaders/src/PC.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PC");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PC.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PC()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PC.vert"), Resources("shaders/src/PC.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PC");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PT()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PT.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PT.vert"), Resources("shaders/src/PT.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PT");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PT.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PT()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PT.vert"), Resources("shaders/src/PT.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PT");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PCT()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PCT.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PCT.vert"), Resources("shaders/src/PCT.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PCT");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PCT.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PCT()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PCT.vert"), Resources("shaders/src/PCT.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PCT");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNC()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PNC.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PNC.vert"), Resources("shaders/src/PNC.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PNC");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PNC.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PNC()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PNC.vert"), Resources("shaders/src/PNC.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PNC");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PN_Color(Vec4 rgba)
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PN_Color.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PN_Color.vert"), Resources("shaders/src/PN_Color.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PN_Color");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PN_Color.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PN_Color()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PN_Color.vert"), Resources("shaders/src/PN_Color.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PN_Color");
		}
	}
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNT()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PNT.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PNT.vert"), Resources("shaders/src/PNT.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PNT");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PNT.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PNT()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PNT.vert"), Resources("shaders/src/PNT.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PNT");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNCT()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PNCT.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PNCT.vert"), Resources("shaders/src/PNCT.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PNCT");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PNCT.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PNCT()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PNCT.vert"), Resources("shaders/src/PNCT.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PNCT");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::P_UI_Color(Onyx::Math::Vec4 rgba)
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/P_UI_Color.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/P_UI_Color.vert"), Resources("shaders/src/P_UI_Color.frag"));
		shader.saveBinary(Resources("shaders/bin"), "P_UI_Color");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/P_UI_Color.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::P_UI_Color()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/P_UI_Color.vert"), Resources("shaders/src/P_UI_Color.frag"));
			shader.saveBinary(Resources("shaders/bin"), "P_UI_Color");
		}
	}
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PT_UI()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/PT_UI.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/PT_UI.vert"), Resources("shaders/src/PT_UI.frag"));
		shader.saveBinary(Resources("shaders/bin"), "PT_UI");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/PT_UI.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::PT_UI()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/PT_UI.vert"), Resources("shaders/src/PT_UI.frag"));
			shader.saveBinary(Resources("shaders/bin"), "PT_UI");
		}
	}
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Text()
{
	Shader shader;
	if (!FileUtils::FileExists(Resources("shaders/bin/UI_Text.bin")))
	{
		shader = Shader::LoadSource(Resources("shaders/src/UI_Text.vert"), Resources("shaders/src/UI_Text.frag"));
		shader.saveBinary(Resources("shaders/bin"), "UI_Text");
	}
	else
	{
		bool result;
		shader = Shader::LoadBinary(Resources("shaders/bin/UI_Text.bin"), &result);
		if (!result)
		{
			onyx_warn(Warning{
					.sourceFunction = "Onyx::Shader::UI_Text()",
					.message = "Failed to load binary shader, recompiling source files instead.",
					.severity = Warning::Severity::Low
				}
			);
			shader.dispose();
			shader = Shader::LoadSource(Resources("shaders/src/UI_Text.vert"), Resources("shaders/src/UI_Text.frag"));
			shader.saveBinary(Resources("shaders/bin"), "UI_Text");
		}
	}
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
