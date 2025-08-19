#include "Shader.h"

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(Type type) : Object(NullHandle) {
    _handle = glCreateShader(type);
}

Shader::~Shader() {
    if (IsValid()) {
        glDeleteShader(_handle);
        _handle = NullHandle;
    }
}

Shader::Shader(Shader&& shader) noexcept : Object(std::move(shader)) {}

Shader& Shader::operator = (Shader&& shader) noexcept {
    Object::operator=(std::move(shader));
    return *this;
}

Shader Shader::Load(Shader::Type type, const char* shaderPath) {
    Shader shader(type);

    std::string shaderCodeString;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		shaderFile.open(shaderPath);

		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();

		shaderFile.close();
		shaderCodeString = shaderStream.str();
	} catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << type << std::endl;
	}
    const char* shaderCode = shaderCodeString.c_str();

    // Compile shader
	int success;
	char infoLog[512];

	glShaderSource(shader.GetHandle(), 1, &shaderCode, NULL);
	glCompileShader(shader.GetHandle());
	glGetShaderiv(shader.GetHandle(), GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader.GetHandle(), 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED" << type << std::endl;
	}

    return shader;
}

// Bind should not be called for Shader
void Shader::Bind() const {
    // Assert if it gets called
    assert(false);
}

// Get shader type of this shader
Shader::Type Shader::GetType() const {
    assert(IsValid());

    GLint type;
    glGetShaderiv(GetHandle(), GL_SHADER_TYPE, &type);
    return static_cast<Type>(type);
}