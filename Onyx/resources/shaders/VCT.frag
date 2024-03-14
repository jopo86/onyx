#version 410 core

in vec3 vertColor;
in vec2 vertTexCoord;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
	fragColor = fragColor * texture(tex, vertTexCoord);
}
