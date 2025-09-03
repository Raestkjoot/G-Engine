#pragma once

// https://www.khronos.org/opengl/wiki/OpenGL_Object
// https://www.khronos.org/opengl/wiki/GLSL_Object

// TODO: We might want to delete copy-constructors for these types of objects

#include <glad/glad.h>

class Object {
public:
    using Handle = GLuint;

    // Create object with constructor

    // Delete object with destructor
    virtual ~Object() {}

    // Use / Bind object
    virtual void Bind() = 0;

    inline Handle GetHandle() const { return _handle; }
    inline bool IsValid() const { return _handle != NullHandle; }

protected:
    // OpenGL uses 0 to represent null / default
    static const Handle NullHandle = 0;

    Handle _handle = 0;
};