#include "Shader.h"

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(Type type) {
    _handle = glCreateShader(type);
}

Shader::~Shader() {
    glDeleteShader(_handle);
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

// Get shader type of this shader
Shader::Type Shader::GetType() const {
    GLint type;
    glGetShaderiv(GetHandle(), GL_SHADER_TYPE, &type);
    return static_cast<Type>(type);
}