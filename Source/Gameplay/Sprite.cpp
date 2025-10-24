#include "Sprite.h"

#include <vector>

Sprite::Sprite() {
    // Shader
    Shader vertShader = Shader::Load(Shader::Type::VertexShader, "Default.vert");
    Shader fragShader = Shader::Load(Shader::Type::FragmentShader, "Default.frag");
    _shaderProgram.Build(vertShader, fragShader);

    // Vertices
    std::vector<float> vertices = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    std::vector<unsigned int> indices = { 
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    // setup VBO, EBO and VAO
    VertexBufferObject vbo;
    ElementBufferObject ebo;
    vbo.Bind();
    _vao.Bind();
    ebo.Bind();

    vbo.AllocateData(vertices);
    ebo.AllocateData(indices);
    _vao.SetAttribute(VertexArrayObject::Type::Float, 3, 0, 0);
    
    VertexArrayObject::Unbind();
    ElementBufferObject::Unbind();
    VertexBufferObject::Unbind();
}

void Sprite::Draw() {
    // TODO: lower level of abstraction compared to the rest. These gl functions should probably be abstracted away.
    glUseProgram(_shaderProgram.GetHandle());
    _vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
