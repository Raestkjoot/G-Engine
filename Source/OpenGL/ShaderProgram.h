#pragma once

#include "Object.h"

#include <glm/glm.hpp>

#include <string>

class Shader;

class ShaderProgram : public Object {
public:
    ShaderProgram();
    virtual ~ShaderProgram();

    virtual void Bind() override;

    // Build (Attach and link) a shader program with vertex and fragment shaders
    inline bool Build(const Shader& vertexShader, const Shader& fragmentShader) {
        return Build(vertexShader, fragmentShader, nullptr, nullptr, nullptr);
    }

    // Build (Attach and link) a shader program with vertex and fragment shaders + geometry shader
    inline bool Build(const Shader& vertexShader, const Shader& fragmentShader, const Shader& geometryShader) {
        return Build(vertexShader, fragmentShader, nullptr, nullptr, &geometryShader);
    }

    // Build (Attach and link) a shader program with vertex and fragment shaders + tesselation shaders
    inline bool Build(const Shader& vertexShader, const Shader& fragmentShader,
        const Shader* tesselationControlShader, const Shader& tesselationEvaluationShader) {
        return Build(vertexShader, fragmentShader, tesselationControlShader, &tesselationEvaluationShader, nullptr);
    }

    // Build (Attach and link) a shader program with vertex and fragment shaders + tesselation shaders + geometry shader
    inline bool Build(const Shader& vertexShader, const Shader& fragmentShader,
        const Shader* tesselationControlShader, const Shader& tesselationEvaluationShader,
        const Shader& geometryShader) {
        return Build(vertexShader, fragmentShader, tesselationControlShader, &tesselationEvaluationShader, &geometryShader);
    }

    // Check if shaders have been linked to create a valid program
    bool IsLinked() const;

    int GetUniformLocation(const std::string& name);

    template<typename T>
    void SetUniform(const std::string& name, T value) {
        SetUniform(GetUniformLocation(name), value);
    }

    // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glUniform.xhtml
    // float
    void SetUniform(int location, float value);
    void SetUniform(int location, glm::vec2 value);
    void SetUniform(int location, glm::vec3 value);
    // integer
    void SetUniform(int location, int value);
    void SetUniform(int location, glm::ivec2 value);
    void SetUniform(int location, glm::ivec3 value);
    // unsigned int
    void SetUniform(int location, unsigned int value);
    void SetUniform(int location, glm::uvec2 value);
    void SetUniform(int location, glm::uvec3 value);
    // matrix
    void SetUniform(int location, glm::mat2x2 value);
    void SetUniform(int location, glm::mat3x3 value);
    void SetUniform(int location, glm::mat4x4 value);

private:
    // Build (Attach and link) all shaders provided for the rasterization pipeline
    bool Build(const Shader& vertexShader, const Shader& fragmentShader,
        const Shader* tesselationControlShader, const Shader* tesselationEvaluationShader,
        const Shader* geometryShader);
    
    void AttachShader(const Shader& shader);
    bool Link();
};