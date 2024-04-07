#version 410 core

out vec4 o_color;

in vec3 io_normal;
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
		o_color = texColor;
		return;
	}

	vec3 color = u_lighting.color * texColor.rgb;

	vec3 ambient = color * u_lighting.ambientStrength;
	
	vec3 normal = normalize(io_normal);
	vec3 lightDir = normalize(-u_lighting.direction);
	float diffuseFactor = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = color * diffuseFactor;
	
	o_color = vec4(diffuse + ambient, texColor.a);

}
