#include "ShaderPresets.h"

using Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::Shader Onyx::ShaderPresets::V_Color(Vec4 rgba)
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/V_Color.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/V_Color.frag"))
	);
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::V_XYZtoRGB()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/V_XYZtoRGB.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/V_XYZtoRGB.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VC()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VC.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VC.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VT()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VT.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VT.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VCT()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VCT.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VCT.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNC()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNC.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNC.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNT()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNT.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNT.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VNCT()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNCT.vert")), 
		FileUtils::ReadLiteral(Onyx::Resources("shaders/VNCT.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Color(Onyx::Math::Vec4 rgba)
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Color.vert")),
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Color.frag"))
	);
	shader.use();
	shader.setVec4("u_color", rgba);
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Texture()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Texture.vert")),
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Texture.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Text()
{
	Shader shader(
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Text.vert")),
		FileUtils::ReadLiteral(Onyx::Resources("shaders/UI_Text.frag"))
	);
	shader.use();
	shader.setMat4("u_model", Mat4(1.0f));
	shader.setMat4("u_view", Mat4(1.0f));
	shader.setMat4("u_projection", Mat4(1.0f));
	return shader;
}
