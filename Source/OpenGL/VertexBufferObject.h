#pragma once

// https://www.khronos.org/opengl/wiki/Vertex_Specification#Vertex_Buffer_Object

#include "Object.h"

#include <vector>

class VertexBufferObject : public Object {
public:
    enum Usage : GLenum
    {
        StaticDraw = GL_STATIC_DRAW,    StaticRead = GL_STATIC_READ,    StaticCopy = GL_STATIC_COPY,
        DynamicDraw = GL_DYNAMIC_DRAW,  DynamicRead = GL_DYNAMIC_READ,  DynamicCopy = GL_DYNAMIC_COPY,
        StreamDraw = GL_STREAM_DRAW,    StreamRead = GL_STREAM_READ,    StreamCopy = GL_STREAM_COPY
    };

    VertexBufferObject();
    virtual ~VertexBufferObject();

    virtual void Bind() override;
    static void Unbind();

    template<typename T>
    void AllocateData(const std::vector<T>& data, Usage usage = Usage::StaticDraw) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(T) * data.size(), data.data(), usage);
    }
};