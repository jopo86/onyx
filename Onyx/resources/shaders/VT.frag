#version 410 core

in vec2 vertTexCoord;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
	fragColor = texture(tex, vertTexCoord);
}
