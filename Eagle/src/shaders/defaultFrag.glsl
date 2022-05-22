#version 430 core
out vec4 FragColor;

uniform float rColor;

void main()
{
    FragColor = vec4(rColor, 0.5f, 0.2f, 1.0f);
} 