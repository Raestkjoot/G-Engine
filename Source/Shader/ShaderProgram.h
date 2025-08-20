#pragma once

#include "Core/Object.h"

class Shader;

class ShaderProgram : public Object {
    public:
    // Declare the type used for uniform locations
    using Location = GLint;

    ShaderProgram();
    virtual ~ShaderProgram();

    // Implements the Bind required by Object. Shaders and shader programs don't use Bind()
    void Bind() const override;

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

private:
    // Build (Attach and link) all shaders provided for the rasterization pipeline
    bool Build(const Shader& vertexShader, const Shader& fragmentShader,
        const Shader* tesselationControlShader, const Shader* tesselationEvaluationShader,
        const Shader* geometryShader);
    
    void AttachShader(const Shader& shader);
    bool Link();
};