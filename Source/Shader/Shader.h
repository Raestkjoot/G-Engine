#pragma once

#include "Core/Object.h"

#include <span>

// Shader is an OpenGL Object that represents a program that runs on the GPU
// There are different types, with different requirements. See Lecture 2: Shaders for more information
class Shader : public Object {
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
    Shader(Shader&& shader) noexcept;
    Shader& operator = (Shader&& shader) noexcept;
    
    static Shader Load(Shader::Type type, const char* shaderPath);

    Type GetType() const;
    inline bool IsType(Type type) const { return GetType() == type; }

private:
    Shader(Type type);

    // Implements the Bind required by Object. Shaders and shader programs don't use Bind()
    void Bind() const override;
};