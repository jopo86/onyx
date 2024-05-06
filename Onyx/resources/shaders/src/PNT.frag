#version 410 core

out vec4 o_color;

in vec3 io_pos;
in float io_diffuseFactor;
in vec2 io_texCoord;

uniform vec3 u_camPos;
uniform sampler2D u_tex;

struct Lighting
{
	bool enabled;
	vec3 color;
	float ambientStrength;
	vec3 direction;
};

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Lighting u_lighting;
uniform Fog u_fog;

void main()
{
	vec4 texColor = texture(u_tex, io_texCoord);

	if (!u_lighting.enabled)
	{
		o_color = texColor;
		if (!u_fog.enabled) return;

		float camDist = distance(u_camPos, io_pos);

		if (camDist > u_fog.start)
		{
			float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
			fogFactor = clamp(fogFactor, 0.0, 1.0);
			o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		}
	}

	vec3 color = u_lighting.color * texColor.rgb;
	vec3 ambient = color * u_lighting.ambientStrength;
	vec3 diffuse = color * io_diffuseFactor;
	o_color = vec4(diffuse + ambient, texColor.a);

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
	}
}
