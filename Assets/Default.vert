#version 330 core

layout (location = 0) in vec3 aPos;

uniform vec3 position;

void main()
{
    vec3 worldPos = position + aPos;
    gl_Position = vec4(worldPos, 1.0);
}
