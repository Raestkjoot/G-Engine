#pragma once

// https://www.khronos.org/opengl/wiki/Buffer_Object

#include "Object.h"

#include <vector>

class BufferObject : public Object {
public:
    enum Usage : GLenum
    {
        StaticDraw = GL_STATIC_DRAW,    StaticRead = GL_STATIC_READ,    StaticCopy = GL_STATIC_COPY,
        DynamicDraw = GL_DYNAMIC_DRAW,  DynamicRead = GL_DYNAMIC_READ,  DynamicCopy = GL_DYNAMIC_COPY,
        StreamDraw = GL_STREAM_DRAW,    StreamRead = GL_STREAM_READ,    StreamCopy = GL_STREAM_COPY
    };
    enum Target : GLenum
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER,
    };

    // template<typename T>
    // void AllocateData(const std::vector<T>& data, Usage usage = Usage::StaticDraw)
};