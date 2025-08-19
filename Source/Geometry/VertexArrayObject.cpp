#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() : Object(NullHandle) {
    glGenVertexArrays(1, &GetHandleRef());
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &GetHandleRef());
}

void VertexArrayObject::Bind() const {
    glBindVertexArray(GetHandle());
}

void VertexArrayObject::Unbind() {
    glBindVertexArray(NullHandle);
}

void VertexArrayObject::SetAttribute(GLuint location, const VertexAttribute& attribute, GLint offset, GLsizei stride) {
    // Get the attribute properties in OpenGL expected format
    GLint components = attribute.GetComponents();
    GLenum type = static_cast<GLenum>(attribute.GetType());
    GLboolean normalized = attribute.IsNormalized() ? GL_TRUE : GL_FALSE;

    // Compute the attribute pointer
    const unsigned char* pointer = nullptr; // Actual base pointer is in VBO
    pointer += offset;

    // Set the VertexAttribute pointer in this location
    glVertexAttribPointer(location, components, type, normalized, stride, pointer);

    // Finally, we enable the VertexAttribute in this location
    glEnableVertexAttribArray(location);
}