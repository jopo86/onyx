#version 410 core

layout (location = 0) in vec3 i_pos;

uniform mat4 u_model;
uniform mat4 u_projection;

void main() {
	gl_Position = u_projection * u_model * vec4(i_pos, 1.0);
}

// ------------------------------------------------------------------------
#switch

#version 410 core

uniform vec4 u_color;

out vec4 o_color;

void main() {
	o_color = u_color;
}
