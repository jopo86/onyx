#version 410 core

in vec3 vertColor;
in vec2 vertTexCoord;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
	fragColor = vec4(vertColor, 1.0f) * texture(tex, vertTexCoord);
}
