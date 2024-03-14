#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;

out vec3 vertColor;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
	gl_Position = u_projection * u_view * u_model * vec4(pos, 1.0f);
	vertColor = color;
}
