#pragma once

// https://www.khronos.org/opengl/wiki/Vertex_Specification#Vertex_Array_Object

#include "Object.h"

class VertexArrayObject : public Object {
public:
    enum Type : GLenum {
        None = GL_NONE,
        Float = GL_FLOAT,
        Fixed = GL_FIXED,
        Half = GL_HALF_FLOAT,
        Double = GL_DOUBLE,
        Byte = GL_BYTE,
        UByte = GL_UNSIGNED_BYTE,
        Short = GL_SHORT,
        UShort = GL_UNSIGNED_SHORT,
        Int = GL_INT,
        UInt = GL_UNSIGNED_INT
    };

    VertexArrayObject();
    virtual ~VertexArrayObject();

    virtual void Bind() override;
    static void Unbind();

    void SetAttribute(Type type, int amount, int offset, int stride, bool normalized = false);

private:
    unsigned int _attribIndex = 0;
};