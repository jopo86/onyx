#include "Shader.h"

#include <glad/glad.h>

#include "FileUtils.h"

using Onyx::Math::Vec2, Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::DVec2,
Onyx::Math::DVec3, Onyx::Math::DVec4, Onyx::Math::IVec2, Onyx::Math::IVec3,
Onyx::Math::IVec4, Onyx::Math::UVec2, Onyx::Math::UVec3, Onyx::Math::UVec4,
Onyx::Math::Mat2x2, Onyx::Math::Mat2x3, Onyx::Math::Mat2x4, Onyx::Math::Mat3x2, 
Onyx::Math::Mat3x3, Onyx::Math::Mat3x4, Onyx::Math::Mat4x2,
Onyx::Math::Mat4x3, Onyx::Math::Mat4x4, Onyx::Math::Mat4;


Onyx::Shader::Shader() : vertSource(""), fragSource("")
{
	prog = 0;
}

Onyx::Shader::Shader(const char *vertSource, const char *fragSource) : vertSource(vertSource), fragSource(fragSource)
{
	uint vert = glCreateShader(GL_VERTEX_SHADER);
	uint frag = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vert, 1, &vertSource, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	int result;

	glCompileShader(vert);
	glGetShaderiv(vert, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[ONYX_BUFFER_SIZE];
		glGetShaderInfoLog(vert, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
		Err("failed to compile a vertex shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glCompileShader(frag);
	glGetShaderiv(frag, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[ONYX_BUFFER_SIZE];
		glGetShaderInfoLog(frag, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
		Err("failed to compile a fragment shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);

	glLinkProgram(prog);
	glGetProgramiv(prog, GL_LINK_STATUS, &result);
	if (!result)
	{
		char infoBuffer[ONYX_BUFFER_SIZE];
		glGetProgramInfoLog(prog, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
		Err("failed to link a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glValidateProgram(prog);
	glGetProgramiv(prog, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		char infoBuffer[ONYX_BUFFER_SIZE];
		glGetProgramInfoLog(prog, ONYX_BUFFER_SIZE, nullptr, infoBuffer);
		Err("failed to validate a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

#if defined(ONYX_GL_DEBUG_LOW) || defined(ONYX_GL_DEBUG_MED) || defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Shader::Shader(const Shader& other)
{
	prog = other.prog;
	vertSource = other.vertSource;
	fragSource = other.fragSource;
}

Onyx::Shader Onyx::Shader::Load(const std::string& vertPath, const std::string& fragPath)
{
	return Shader(
		FileUtils::ReadLiteral(vertPath),
		FileUtils::ReadLiteral(fragPath)
	);
}

void Onyx::Shader::use() const
{
	glUseProgram(prog);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

uint Onyx::Shader::getProgramID() const
{
	return prog;
}

const char* Onyx::Shader::getVertSource() const
{
	return vertSource;
}

const char* Onyx::Shader::getFragSource() const
{
	return fragSource;
}

void Onyx::Shader::setBool(const char* varName, bool val)
{
	glUniform1i(glGetUniformLocation(prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setInt(const char* varName, int val)
{
	glUniform1i(glGetUniformLocation(prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUint(const char* varName, uint val)
{
	glUniform1ui(glGetUniformLocation(prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setFloat(const char* varName, float val)
{
	glUniform1f(glGetUniformLocation(prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDouble(const char* varName, double val)
{
	glUniform1d(glGetUniformLocation(prog, varName), val);

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec2(const char* varName, const Vec2& val)
{
	glUniform2fv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec3(const char* varName, const Vec3& val)
{
	glUniform3fv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setVec4(const char* varName, const Vec4& val)
{
	glUniform4fv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec2(const char* varName, const DVec2& val)
{
	glUniform2dv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec3(const char* varName, const DVec3& val)
{
	glUniform3dv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setDVec4(const char* varName, const DVec4& val)
{
	glUniform4dv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec2(const char* varName, const IVec2& val)
{
	glUniform2iv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec3(const char* varName, const IVec3& val)
{
	glUniform3iv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setIVec4(const char* varName, const IVec4& val)
{
	glUniform4iv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec2(const char* varName, const UVec2& val)
{
	glUniform2uiv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec3(const char* varName, const UVec3& val)
{
	glUniform3uiv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setUVec4(const char* varName, const UVec4& val)
{
	glUniform4uiv(glGetUniformLocation(prog, varName), 1, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x2(const char* varName, const Mat2x2& val, bool normalize)
{
	glUniformMatrix2fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2(const char* varName, const Mat2x2& val, bool normalize)
{
	glUniformMatrix2fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x3(const char* varName, const Mat2x3& val, bool normalize)
{
	glUniformMatrix2x3fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat2x4(const char* varName, const Mat2x4& val, bool normalize)
{
	glUniformMatrix2x4fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x2(const char* varName, const Mat3x2& val, bool normalize)
{
	glUniformMatrix3x2fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x3(const char* varName, const Mat3x3& val, bool normalize)
{
	glUniformMatrix3fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3(const char* varName, const Mat3x3& val, bool normalize)
{
	glUniformMatrix3fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat3x4(const char* varName, const Mat3x4& val, bool normalize)
{
	glUniformMatrix3x4fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x2(const char* varName, const Mat4x2& val, bool normalize)
{
	glUniformMatrix4x2fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x3(const char* varName, const Mat4x3& val, bool normalize)
{
	glUniformMatrix4x3fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4x4(const char* varName, const Mat4x4& val, bool normalize)
{
	glUniformMatrix4fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

void Onyx::Shader::setMat4(const char* varName, const Mat4x4& val, bool normalize)
{
	glUniformMatrix4fv(glGetUniformLocation(prog, varName), 1, normalize, val.data());

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}

Onyx::Shader Onyx::Shader::P_Color(Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/P_Color.vert"), Onyx::Resources("shaders/P_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::P_XYZtoRGB()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/P_XYZtoRGB.vert"), Onyx::Resources("shaders/P_XYZtoRGB.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PC()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PC.vert"), Onyx::Resources("shaders/PC.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PT.vert"), Onyx::Resources("shaders/PT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PCT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PCT.vert"), Onyx::Resources("shaders/PCT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNC()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PNC.vert"), Onyx::Resources("shaders/PNC.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PN_Color(Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PN_Color.vert"), Onyx::Resources("shaders/PN_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PNT.vert"), Onyx::Resources("shaders/PNT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::PNCT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/PNCT.vert"), Onyx::Resources("shaders/PNCT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Color(Onyx::Math::Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Color.vert"), Onyx::Resources("shaders/UI_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Texture()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Texture.vert"), Onyx::Resources("shaders/UI_Texture.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::Shader::UI_Text()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Text.vert"), Onyx::Resources("shaders/UI_Text.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

void Onyx::Shader::dispose()
{
	if (prog) glDeleteProgram(prog);
	prog = 0;
	vertSource = fragSource = "";

#if defined(ONYX_GL_DEBUG_HIGH)
	glCheckError();
#endif
}
