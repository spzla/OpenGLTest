#version 430
out vec4 fragColor;

in vec2 TexCoord;

uniform sampler2D texture_diffuse1;

void main()
{
  fragColor = texture(texture_diffuse1, TexCoord);
}