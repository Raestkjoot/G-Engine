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

    // TODO: Maybe a template version? template<typename T> void SetUniform(const std::string& name, T value) 
    void SetUniform(const std::string& name, glm::vec3 value);

private:
    // Build (Attach and link) all shaders provided for the rasterization pipeline
    bool Build(const Shader& vertexShader, const Shader& fragmentShader,
        const Shader* tesselationControlShader, const Shader* tesselationEvaluationShader,
        const Shader* geometryShader);
    
    void AttachShader(const Shader& shader);
    bool Link();
};