#include "ShaderPresets.h"

using Onyx::Math::Vec3, Onyx::Math::Mat4;

Onyx::Shader Onyx::ShaderPresets::V_Color(Vec3 rgb)
{
	Shader shader(
		File(Onyx::Resources("shaders/V_Color.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/V_Color.frag")).readLiteral()
	);
	glUseProgram(shader.getProgramID());
	shader.uniform("u_color", rgb.getX(), rgb.getY(), rgb.getZ(), 1.0f);
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	glUseProgram(0);
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::V_XYZtoRGB()
{
	Shader shader(
		File(Onyx::Resources("shaders/V_XYZtoRGB.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/V_XYZtoRGB.frag")).readLiteral()
	);
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	glUseProgram(0);
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VC()
{
	Shader shader(
		File(Onyx::Resources("shaders/VC.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VC.frag")).readLiteral()
	);
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	glUseProgram(0);
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VT()
{
	Shader shader(
		File(Onyx::Resources("shaders/VT.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VT.frag")).readLiteral()
	);
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	glUseProgram(0);
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VCT()
{
	Shader shader(
		File(Onyx::Resources("shaders/VCT.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VCT.frag")).readLiteral()
	);
	glUseProgram(shader.getProgramID());
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	glUseProgram(0);
	return shader;
}
