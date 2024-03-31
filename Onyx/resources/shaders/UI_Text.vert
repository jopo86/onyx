#version 410 core

layout (location = 0) in vec4 vertex;
out vec2 texCoords;

uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * vec4(vertex.xy, 0.0, 1.0);
	texCoords = vertex.zw;
}
