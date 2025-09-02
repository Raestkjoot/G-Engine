#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject() {
    glGenBuffers(1, &_handle);
}

VertexBufferObject::~VertexBufferObject() {
    glDeleteBuffers(1, &_handle);
}

void VertexBufferObject::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, GetHandle());
}

void VertexBufferObject::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, NullHandle);
}