#pragma once

#include "Object.h"

class Shader {
public:
    enum Type : GLenum
    {
        ComputeShader = GL_COMPUTE_SHADER,
        VertexShader = GL_VERTEX_SHADER,
        TesselationControlShader = GL_TESS_CONTROL_SHADER,
        TesselationEvaluationShader = GL_TESS_EVALUATION_SHADER,
        GeometryShader = GL_GEOMETRY_SHADER,
        FragmentShader = GL_FRAGMENT_SHADER
    };

    virtual ~Shader();

    static Shader Load(Shader::Type type, const char* shaderPath);

    inline Object::Handle GetHandle() const { return _handle; }
    Type GetType() const;
    inline bool IsType(Type type) const { return GetType() == type; }
    inline bool IsValid() const { return _handle != 0; }

private:
    Shader(Type type);
    Object::Handle _handle;
};