#pragma once

#include "OpenGL/VertexArrayObject.h"
#include "OpenGL/VertexBufferObject.h"
#include "OpenGL/ElementBufferObject.h"
#include "OpenGL/Shader.h"
#include "OpenGL/ShaderProgram.h"

class Sprite {
public:
    Sprite();

     void Draw();

     ShaderProgram* GetShaderProgram() { return &_shaderProgram; }

private:
    ShaderProgram _shaderProgram;
    VertexArrayObject _vao;
};