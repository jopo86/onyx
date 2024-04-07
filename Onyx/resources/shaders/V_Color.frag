#version 410 core

out vec4 o_color;

uniform vec4 u_color;

void main()
{
	o_color = u_color;
}
