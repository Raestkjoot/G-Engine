#pragma once

#include "Geometry/VertexArrayObject.h"
#include "Geometry/VertexBufferObject.h"
#include "Geometry/VertexAttribute.h"
#include "Geometry/ElementBufferObject.h"
#include "Shader/Shader.h"
#include "Shader/ShaderProgram.h"

 class Sprite {
public:
    Sprite();

     void Draw();

private:
    ShaderProgram _shaderProgram;
    VertexArrayObject _vao;
};