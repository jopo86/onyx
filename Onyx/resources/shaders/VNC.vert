#version 410 core

layout (location = 0) in vec3 i_pos;
layout (location = 1) in vec4 i_color;
layout (location = 3) in vec3 i_normal;

out vec3 io_normal;
out vec4 io_color;

uniform mat4 u_model;
uniform mat4 u_inverseModel;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(i_pos, 1.0);
	io_color = i_color;
	io_normal = mat3(transpose(u_inverseModel)) * i_normal;
}
