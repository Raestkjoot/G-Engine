#include "ShaderProgram.h"

#include "Shader/Shader.h"

#include <cassert>

ShaderProgram::ShaderProgram() : Object(NullHandle)
{
    Handle& handle = GetHandleRef();
    handle = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    if (IsValid())
    {
        Handle& handle = GetHandleRef();
        glDeleteProgram(handle);
        handle = NullHandle;
    }
}

void ShaderProgram::Bind() const
{
    // Bind should not be called for ShaderProgram. Assert if it gets called
    assert(false);
}

bool ShaderProgram::IsLinked() const
{
    assert(IsValid());

    GLint success;
    glGetProgramiv(GetHandle(), GL_LINK_STATUS, &success);
    return success;
}

// Build (Attach and link) all shaders provided for the rasterization pipeline
bool ShaderProgram::Build(const Shader& vertexShader, const Shader& fragmentShader,
    const Shader* tesselationControlShader, const Shader* tesselationEvaluationShader,
    const Shader* geometryShader)
{
    assert(vertexShader.IsType(Shader::VertexShader));
    AttachShader(vertexShader);

    assert(fragmentShader.IsType(Shader::FragmentShader));
    AttachShader(fragmentShader);

    if (tesselationControlShader)
    {
        assert(tesselationEvaluationShader);
        assert(tesselationControlShader->IsType(Shader::TesselationControlShader));
        AttachShader(*tesselationControlShader);
    }

    if (tesselationEvaluationShader)
    {
        assert(tesselationEvaluationShader->IsType(Shader::TesselationEvaluationShader));
        AttachShader(*tesselationEvaluationShader);
    }

    if (geometryShader)
    {
        assert(geometryShader->IsType(Shader::GeometryShader));
        AttachShader(*geometryShader);
    }

    return Link();
}

void ShaderProgram::AttachShader(const Shader& shader)
{
    assert(IsValid());
    assert(!IsLinked());
    assert(shader.IsValid());
    glAttachShader(GetHandle(), shader.GetHandle());
}

bool ShaderProgram::Link()
{
    assert(IsValid());
    glLinkProgram(GetHandle());
    return IsLinked();
}