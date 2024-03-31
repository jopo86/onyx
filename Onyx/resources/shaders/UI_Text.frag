#version 410 core

in vec2 texCoords;
out vec4 color;

uniform sampler2D tex;
uniform vec3 textColor;

void main()
{
	color = vec4(textColor, 1.0f) * vec4(1.0, 1.0, 1.0, texture(tex, texCoords).r);
}
