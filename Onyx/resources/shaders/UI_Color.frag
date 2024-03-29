#version 410 core

in vec4 vertColor;

out vec4 fragColor;

void main() {
	fragColor = vec4(vertColor, 1.0f);
}
