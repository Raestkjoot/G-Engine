#version 330 core

layout (location = 0) in vec3 aPos;

uniform vec3 position;
uniform vec3 rotation;
uniform vec3 scale;

void main()
{
    float zRotSin = sin(rotation.z);
    float zRotCos = cos(rotation.z);
    vec3 rotatedPos = vec3(
        aPos.x * zRotCos + aPos.y * (-zRotSin),
        aPos.x * zRotSin + aPos.y * zRotCos,
        aPos.z
    );
    float xRotSin = sin(rotation.x);
    float xRotCos = cos(rotation.x);
    rotatedPos = vec3(
        rotatedPos.x,
        rotatedPos.y * xRotCos + rotatedPos.z * xRotSin,
        rotatedPos.y * (-xRotSin) + rotatedPos.z * xRotCos
    );
    float yRotSin = sin(rotation.y);
    float yRotCos = cos(rotation.y);
    rotatedPos = vec3(
        rotatedPos.x * yRotCos + rotatedPos.z * (-yRotSin),
        rotatedPos.y,
        rotatedPos.x * yRotSin + rotatedPos.z * yRotCos
    );

    vec3 scaledPos = scale * rotatedPos;
    vec3 worldPos = position + scaledPos;
    gl_Position = vec4(worldPos, 1.0);
}
