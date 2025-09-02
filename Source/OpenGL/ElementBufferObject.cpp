#include "ElementBufferObject.h"

ElementBufferObject::ElementBufferObject() {
    glGenBuffers(1, &_handle);
}

ElementBufferObject::~ElementBufferObject() {
    glDeleteBuffers(1, &_handle);
}

void ElementBufferObject::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GetHandle());
}

void ElementBufferObject::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NullHandle);
}