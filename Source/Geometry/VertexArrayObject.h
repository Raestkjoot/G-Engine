#pragma once

#include "Core/Object.h"
#include "Geometry/VertexAttribute.h"

class VertexArrayObject : public Object {
public:
    VertexArrayObject();
    virtual ~VertexArrayObject();

    void Bind() const override;
    static void Unbind();

    // Sets what VertexAttribute is assigned to location, and how to access the data:
    // offset: where to start looking in the buffer
    // stride: how far each element is from the previous one. Default value 0 will use the attribute size
    void SetAttribute(GLuint location, const VertexAttribute& attribute, GLint offset, GLsizei stride = 0);
};