#version 410 core

layout (location = 0) in vec4 i_vertex;

out vec2 io_texCoord;
out vec3 io_pos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_vertex.xy, 0.0, 1.0);
	io_texCoord = i_vertex.zw;
	io_pos = vec3(u_model * vec4(i_vertex.xy, 0.0, 1.0));
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;
in vec3 io_pos;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec4 u_color;
uniform vec3 u_camPos;

struct Fog
{
	bool enabled;
	vec3 color;
	float start, end;
};

uniform Fog u_fog;

void main()
{
	o_color = u_color * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
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
