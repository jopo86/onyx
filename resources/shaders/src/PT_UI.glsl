#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 2) in vec2 i_texCoord;

out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(i_pos, 1.0f);
	io_texCoord = i_texCoord;
}

// ------------------------------------------------------------------------
#switch

#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;

void main()
{
	o_color = texture(u_tex, io_texCoord);
}

