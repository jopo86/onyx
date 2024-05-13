#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;

out vec3 io_pos;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_pos = vec3(u_model * vec4(i_pos, 1.0));
	io_color = i_color;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec3 io_pos;
in vec4 io_color;

out vec4 o_color;

uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog fog;

void main() {
	o_color = io_color;

	if (!u_fog.enabled) return;

	float camDist = distance(u_camPos, io_pos);

	if (camDist > u_fog.start)
	{
		float fogFactor = (camDist - u_fog.start) / (u_fog.end - u_fog.start);
		fogFactor = clamp(fogFactor, 0.0, 1.0);
		float a = o_color.a;
		o_color = mix(o_color, vec4(u_fog.color, 1.0), fogFactor);
		o_color.a = a;
	}
}

