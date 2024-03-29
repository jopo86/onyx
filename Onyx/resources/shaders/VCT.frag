#version 410 core

in vec4 vertColor;
in vec2 vertTexCoord;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
	fragColor = vertColor * texture(tex, vertTexCoord);
}
