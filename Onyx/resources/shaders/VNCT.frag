#version 410 core

out vec4 o_color;

in float io_diffuseFactor;
in vec4 io_color;
in vec2 io_texCoord;

uniform sampler2D u_tex;

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
	vec4 texColor = texture(u_tex, io_texCoord);

	if (!u_lighting.enabled)
	{
		o_color = io_color * texColor;
		return;
	}

	vec3 color = u_lighting.color * io_color.rgb * texColor.rgb;

	vec3 ambient = color * u_lighting.ambientStrength;
	vec3 diffuse = color * io_diffuseFactor;
	
	o_color = vec4(diffuse + ambient, texColor.a * io_color.a);
}
