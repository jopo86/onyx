#version 410 core

in vec2 io_texCoord;

out vec4 o_color;

uniform sampler2D u_tex;
uniform vec3 u_textColor;

void main()
{
	o_color = vec4(u_textColor, 1.0f) * vec4(1.0, 1.0, 1.0, texture(u_tex, io_texCoord).r);
}
