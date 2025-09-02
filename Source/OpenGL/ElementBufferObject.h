#pragma once

#include "Object.h"

#include <vector>

class ElementBufferObject : public Object {
public:
    enum Usage : GLenum
    {
        StaticDraw = GL_STATIC_DRAW,    StaticRead = GL_STATIC_READ,    StaticCopy = GL_STATIC_COPY,
        DynamicDraw = GL_DYNAMIC_DRAW,  DynamicRead = GL_DYNAMIC_READ,  DynamicCopy = GL_DYNAMIC_COPY,
        StreamDraw = GL_STREAM_DRAW,    StreamRead = GL_STREAM_READ,    StreamCopy = GL_STREAM_COPY
    };

    ElementBufferObject();
    virtual ~ElementBufferObject();

    virtual void Bind() override;
    static void Unbind();

    template<typename T>
    void AllocateData(const std::vector<T>& data, Usage usage = Usage::StaticDraw) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(T) * data.size(), data.data(), usage);
    }
};