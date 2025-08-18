#pragma once

#include "Core/Object.h"
#include <span>

class BufferObject : public Object {
public:
    enum Target : GLenum
    {
        ArrayBuffer = GL_ARRAY_BUFFER,
        ElementArrayBuffer = GL_ELEMENT_ARRAY_BUFFER
    };

    enum Usage : GLenum
    {
        StaticDraw = GL_STATIC_DRAW,    StaticRead = GL_STATIC_READ,    StaticCopy = GL_STATIC_COPY,
        DynamicDraw = GL_DYNAMIC_DRAW,  DynamicRead = GL_DYNAMIC_READ,  DynamicCopy = GL_DYNAMIC_COPY,
        StreamDraw = GL_STREAM_DRAW,    StreamRead = GL_STREAM_READ,    StreamCopy = GL_STREAM_COPY
    };

    BufferObject();
    virtual ~BufferObject();

    using Object::Bind;

    virtual Target GetTarget() const = 0;

    void AllocateData(size_t size, Usage usage);
    void AllocateData(std::span<const std::byte> data, Usage usage);
    
    void UpdateData(std::span<const std::byte> data, size_t offset = 0);

protected:
    void Bind(Target target) const;
    static void Unbind(Target target);
};

// Templated BufferObject derived class based on the Target type
// Implements methods that are common to all targets
template<BufferObject::Target T>
class BufferObjectBase : public BufferObject {
public:
    inline BufferObjectBase() {}

    inline Target GetTarget() const override { return T; }
    inline void Bind() const override { BufferObject::Bind(T); }
    static inline void Unbind() { BufferObject::Unbind(T); }
};