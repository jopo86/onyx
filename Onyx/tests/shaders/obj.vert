#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 3) in vec3 normal;

out vec3 vertNormal;
out vec3 fragPos;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(pos, 1.0);
    vertNormal = normal;
    fragPos = vec3(u_model * vec4(pos, 1.0));
}
