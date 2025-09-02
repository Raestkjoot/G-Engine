#include "ShaderProgram.h"

#include "Shader.h"

#include <cassert>

ShaderProgram::ShaderProgram() {
    _handle = glCreateProgram();
}

ShaderProgram::~ShaderProgram() {
    if (IsValid()) {
        glDeleteProgram(_handle);
        _handle = NullHandle;
    }
}

void ShaderProgram::Bind() {
    glUseProgram(_handle);
}

bool ShaderProgram::IsLinked() const {
    assert(IsValid());

    GLint success;
    glGetProgramiv(GetHandle(), GL_LINK_STATUS, &success);
    return success;
}

// Build (Attach and link) all shaders provided for the rasterization pipeline
bool ShaderProgram::Build(const Shader& vertexShader, const Shader& fragmentShader,
    const Shader* tesselationControlShader, const Shader* tesselationEvaluationShader,
    const Shader* geometryShader) {

    assert(vertexShader.IsType(Shader::VertexShader));
    AttachShader(vertexShader);

    assert(fragmentShader.IsType(Shader::FragmentShader));
    AttachShader(fragmentShader);

    if (tesselationControlShader) {
        assert(tesselationEvaluationShader);
        assert(tesselationControlShader->IsType(Shader::TesselationControlShader));
        AttachShader(*tesselationControlShader);
    }

    if (tesselationEvaluationShader) {
        assert(tesselationEvaluationShader->IsType(Shader::TesselationEvaluationShader));
        AttachShader(*tesselationEvaluationShader);
    }

    if (geometryShader) {
        assert(geometryShader->IsType(Shader::GeometryShader));
        AttachShader(*geometryShader);
    }

    return Link();
}

void ShaderProgram::AttachShader(const Shader& shader) {
    assert(IsValid());
    assert(!IsLinked());
    assert(shader.IsValid());
    glAttachShader(GetHandle(), shader.GetHandle());
}

bool ShaderProgram::Link() {
    assert(IsValid());
    glLinkProgram(GetHandle());
    return IsLinked();
}