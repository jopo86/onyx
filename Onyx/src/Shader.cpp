#include "Shader.h"

using Onyx::Math::Vec3, Onyx::Math::Mat4;

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

	glCompileShader(vert);
	glCompileShader(frag);

	prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog);

	glDeleteShader(vert);
	glDeleteShader(frag);
}

Onyx::Shader::Shader(const char *vertSource, const char *fragSource, ErrorHandler& errorHandler) : vertSource(vertSource), fragSource(fragSource)
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
		errorHandler.err("failed to compile a vertex shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
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
		errorHandler.err("failed to compile a fragment shader, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
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
		errorHandler.err("failed to link a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
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
		errorHandler.err("failed to validate a shader program, shader has been disposed. OpenGL output shown below.\n\n" + std::string(infoBuffer));
		if (vert) glDeleteShader(vert);
		if (frag) glDeleteShader(frag);
		dispose();
		return;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);
}

void Onyx::Shader::use()
{
	glUseProgram(prog);
}

uint Onyx::Shader::getProgramID()
{
	return prog;
}

const char *Onyx::Shader::getVertSource()
{
	return vertSource;
}

const char *Onyx::Shader::getFragSource()
{
	return fragSource;
}

void Onyx::Shader::uniform(const char *name, float v0, float v1, float v2, float v3)
{
	glUniform4f(glGetUniformLocation(prog, name), v0, v1, v2, v3);
}

void Onyx::Shader::uniform(const char* name, Vec3 vec)
{
	glUniform3f(glGetUniformLocation(prog, name), vec.getX(), vec.getY(), vec.getZ());
}

void Onyx::Shader::uniform(const char *name, Mat4 mat)
{
	glUniformMatrix4fv(glGetUniformLocation(prog, name), 1, GL_FALSE, mat.data());
}

void Onyx::Shader::dispose()
{
	if (prog) glDeleteProgram(prog);
	prog = 0;
	vertSource = fragSource = "";
}
