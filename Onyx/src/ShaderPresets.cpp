#include "ShaderPresets.h"

using Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::Shader Onyx::ShaderPresets::V_Color(Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/V_Color.vert"), Onyx::Resources("shaders/V_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::V_XYZtoRGB()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/V_XYZtoRGB.vert"), Onyx::Resources("shaders/V_XYZtoRGB.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VC()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VC.vert"), Onyx::Resources("shaders/VC.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VT.vert"), Onyx::Resources("shaders/VT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VCT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VCT.vert"), Onyx::Resources("shaders/VCT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNC()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VNC.vert"), Onyx::Resources("shaders/VNC.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VN_Color(Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VN_Color.vert"), Onyx::Resources("shaders/VN_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VNT.vert"), Onyx::Resources("shaders/VNT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNCT()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/VNCT.vert"), Onyx::Resources("shaders/VNCT.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Color(Onyx::Math::Vec4 rgba)
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Color.vert"), Onyx::Resources("shaders/UI_Color.frag"));
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Texture()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Texture.vert"), Onyx::Resources("shaders/UI_Texture.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Text()
{
	Shader shader = Shader::Load(Onyx::Resources("shaders/UI_Text.vert"), Onyx::Resources("shaders/UI_Text.frag"));
	shader.use();
	shader.setMat4("u_model", Mat4::Identity());
	shader.setMat4("u_view", Mat4::Identity());
	shader.setMat4("u_projection", Mat4::Identity());
	return shader;
}
