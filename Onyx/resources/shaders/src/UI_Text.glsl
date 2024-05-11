#version 410 core

layout (location = 0) in vec4 i_vertex;

out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(i_vertex.xy, 0.0, 1.0);
	io_texCoord = i_vertex.zw;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec4 u_color;

void main()
{
	o_color = u_color * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
}

