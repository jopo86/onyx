#version 410 core

out vec4 o_color;

in vec3 io_normal;
in vec4 io_color;

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

	if (!u_lighting.enabled)
	{
		o_color = io_color;
		return;
	}

	vec3 color = u_lighting.color * io_color.rgb;

	vec3 ambient = color * u_lighting.ambientStrength;
	
	vec3 normal = normalize(io_normal);
	vec3 lightDir = normalize(-u_lighting.direction);
	float diffuseFactor = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = color * diffuseFactor;
	
	o_color = vec4(diffuse + ambient, io_color.a);
}
