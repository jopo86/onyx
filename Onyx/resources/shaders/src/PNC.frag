#version 410 core

out vec4 o_color;

in vec3 io_pos;
in vec4 io_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog fog;

void main()
{
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
	}
}
