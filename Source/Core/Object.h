#pragma once

#include <glad/glad.h>

class Object {
public:
    using Handle = GLuint;

    Object(Handle handle);
    virtual ~Object();
    // move semantics
    // Object(Object&& object) noexcept;
    // Object& operator = (Object&& object) noexcept;

    inline Handle GetHandle() const { return _handle; }
    inline bool IsValid() const { return _handle != NullHandle; }

    virtual void Bind() const = 0;

protected:
    // OpenGL uses 0 to represent null handles
    static const Handle NullHandle = 0;

    Handle _handle;
};