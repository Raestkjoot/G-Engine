#include "Window.h"

#include "Geometry/VertexArrayObject.h"
#include "Geometry/VertexBufferObject.h"
#include "Geometry/VertexAttribute.h"
#include "Geometry/ElementBufferObject.h"
#include "Shader/Shader.h"

#include <glad/glad.h>
#include <iostream>

int main()
{
    Window* window = new Window(800, 600, "Hello Window");

    // _____SETUP SHADERS_____
    unsigned int shaderProgram;
    {
        // Compile vertex shader
        Shader vertShader = Shader::Load(Shader::Type::VertexShader, "Assets/Default.vert");
        Shader fragShader = Shader::Load(Shader::Type::FragmentShader, "Assets/Default.frag");
        // Link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertShader.GetHandle());
        glAttachShader(shaderProgram, fragShader.GetHandle());
        glLinkProgram(shaderProgram);
        int  success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER_PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
    }

    // _____SETUP VERTICES_____
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = { 
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };
    // setup VBO, EBO and VAO
    VertexBufferObject vbo;
    ElementBufferObject ebo;
    VertexArrayObject vao;

    vbo.Bind();
    vao.Bind();
    ebo.Bind();
    
    vbo.AllocateData(std::span(vertices, sizeof(vertices) / sizeof(float)));
    ebo.AllocateData(std::span(indices, sizeof(indices) / sizeof(unsigned int)));
    VertexAttribute position(Data::Type::Float, 3);
    vao.SetAttribute(0, position, 0);
    
    VertexArrayObject::Unbind();
    ElementBufferObject::Unbind();
    VertexBufferObject::Unbind();

    while (!window->ShouldClose()) {
        window->Update();

        // _____DRAW BACKGROUND______
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // _____DRAW TRIANGLE_____
        glUseProgram(shaderProgram);
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    // _____CLEANUP_____
    glDeleteProgram(shaderProgram);
}