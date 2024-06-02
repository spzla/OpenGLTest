#version 430
out vec4 fragColor;

in vec3 ownColor;
in vec2 texCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main()
{
  fragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), mixValue);
}