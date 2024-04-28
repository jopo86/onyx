#version 410 core

in vec4 io_color;
in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;

void main()
{
	o_color = io_color * texture(u_tex, io_texCoord);
}
