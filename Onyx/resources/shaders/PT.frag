#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;

void main()
{
	o_color = texture(u_tex, io_texCoord);
}
