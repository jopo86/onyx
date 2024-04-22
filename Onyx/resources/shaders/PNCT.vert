#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;
layout (location = 2) in vec2 i_texCoord;
layout (location = 3) in vec3 i_normal;

out float io_diffuseFactor;
out vec4 io_color;
out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

uniform Lighting u_lighting;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_texCoord = i_texCoord;
	io_color = i_color;

	if (!u_lighting.enabled)
	{
		io_diffuseFactor = 1.0;
		return;
	}

	vec3 normal = normalize(mat3(transpose(u_inverseModel)) * i_normal);
	vec3 lightDir = normalize(-u_lighting.direction);
	io_diffuseFactor = max(dot(normal, lightDir), 0.0);
}
