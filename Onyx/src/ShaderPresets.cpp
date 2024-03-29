#include "ShaderPresets.h"

using Onyx::Math::Vec3, Onyx::Math::Vec4, Onyx::Math::Mat4;

Onyx::Shader Onyx::ShaderPresets::V_Color(Vec4 rgba)
{
	Shader shader(
		File(Onyx::Resources("shaders/V_Color.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/V_Color.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_color", rgba);
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::V_XYZtoRGB()
{
	Shader shader(
		File(Onyx::Resources("shaders/V_XYZtoRGB.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/V_XYZtoRGB.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VC()
{
	Shader shader(
		File(Onyx::Resources("shaders/VC.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VC.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VT()
{
	Shader shader(
		File(Onyx::Resources("shaders/VT.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VT.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::VCT()
{
	Shader shader(
		File(Onyx::Resources("shaders/VCT.vert")).readLiteral(), 
		File(Onyx::Resources("shaders/VCT.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Color()
{
	Shader shader(
		File(Onyx::Resources("shaders/UI_Color.vert")).readLiteral(),
		File(Onyx::Resources("shaders/UI_Color.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Texture()
{
	Shader shader(
		File(Onyx::Resources("shaders/UI_Texture.vert")).readLiteral(),
		File(Onyx::Resources("shaders/UI_Texture.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}

Onyx::Shader Onyx::ShaderPresets::UI_Text()
{
	Shader shader(
		File(Onyx::Resources("shaders/UI_Text.vert")).readLiteral(),
		File(Onyx::Resources("shaders/UI_Text.frag")).readLiteral()
	);
	shader.use();
	shader.uniform("u_model", Mat4(1.0f));
	shader.uniform("u_view", Mat4(1.0f));
	shader.uniform("u_projection", Mat4(1.0f));
	return shader;
}
