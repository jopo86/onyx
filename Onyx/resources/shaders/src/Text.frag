#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec4 u_color;

void main()
{
	o_color = u_color * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
}
