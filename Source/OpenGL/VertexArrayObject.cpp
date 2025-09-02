#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() {
    glCreateVertexArrays(1, &_handle);
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &_handle);
}

void VertexArrayObject::Bind() {
    glBindVertexArray(_handle);
}

void VertexArrayObject::Unbind() {
    glBindVertexArray(NullHandle);
}

void VertexArrayObject::SetAttribute(Type type, int amount, int offset, int stride, bool normalized) {
    const unsigned char* pointer = nullptr;
    glVertexAttribPointer(_attribIndex, amount, type, normalized, stride, pointer + offset);
    glEnableVertexAttribArray(_attribIndex++);
}