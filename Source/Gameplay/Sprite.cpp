#include "Sprite.h"

Sprite::Sprite() {
    // Shader
    Shader vertShader = Shader::Load(Shader::Type::VertexShader, "Assets/Default.vert");
    Shader fragShader = Shader::Load(Shader::Type::FragmentShader, "Assets/Default.frag");
    _shaderProgram.Build(vertShader, fragShader);

    // Vertices
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
    vbo.Bind();
    _vao.Bind();
    ebo.Bind();
    
    vbo.AllocateData(std::span(vertices, sizeof(vertices) / sizeof(float)));
    ebo.AllocateData(std::span(indices, sizeof(indices) / sizeof(unsigned int)));
    VertexAttribute position(Data::Type::Float, 3);
    _vao.SetAttribute(0, position, 0);
    
    VertexArrayObject::Unbind();
    ElementBufferObject::Unbind();
    VertexBufferObject::Unbind();
}

void Sprite::Draw() {
        glUseProgram(_shaderProgram.GetHandle());
        _vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
