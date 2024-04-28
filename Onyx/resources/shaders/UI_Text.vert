#version 410 core

layout (location = 0) in vec4 i_vertex;

out vec2 io_texCoord;

uniform mat4 u_model;
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_model * vec4(i_vertex.xy, 0.0, 1.0);
	io_texCoord = i_vertex.zw;
}
