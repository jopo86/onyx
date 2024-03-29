#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 2) in vec2 texCoord;

out vec2 vertTexCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(pos, 1.0f);
	vertTexCoord = texCoord;
}
