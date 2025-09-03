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

int ShaderProgram::GetUniformLocation(const std::string& name) {
    return glGetUniformLocation(GetHandle(), name.c_str());
}

#pragma region setting uniforms

// float
void ShaderProgram::SetUniform(int location, float value) {
    glUniform1f(location, value);
}

void ShaderProgram::SetUniform(int location, glm::vec2 value) {
    glUniform2fv(location, 1, &value[0]);
}

void ShaderProgram::SetUniform(int location, glm::vec3 value) {
    glUniform3fv(location, 1, &value[0]);
}
// integer
void ShaderProgram::SetUniform(int location, int value) {
    glUniform1i(location, value);
}

void ShaderProgram::SetUniform(int location, glm::ivec2 value) {
    glUniform2iv(location, 1, &value[0]);
}

void ShaderProgram::SetUniform(int location, glm::ivec3 value) {
    glUniform3iv(location, 1, &value[0]);
}

// unsigned int
void ShaderProgram::SetUniform(int location, unsigned int value) {
    glUniform1ui(location, value);
}

void ShaderProgram::SetUniform(int location, glm::uvec2 value) {
    glUniform2uiv(location, 1, &value[0]);
}

void ShaderProgram::SetUniform(int location, glm::uvec3 value) {
    glUniform3uiv(location, 1, &value[0]);
}

// matrix
void ShaderProgram::SetUniform(int location, glm::mat2x2 value) {
    glUniformMatrix2fv(location, 1, false, &value[0][0]);
}

void ShaderProgram::SetUniform(int location, glm::mat3x3 value) {
    glUniformMatrix3fv(location, 1, false, &value[0][0]);
}

void ShaderProgram::SetUniform(int location, glm::mat4x4 value) {
    glUniformMatrix4fv(location, 1, false, &value[0][0]);
}
#pragma endregion