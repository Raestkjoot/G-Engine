#pragma once

// https://www.khronos.org/opengl/wiki/Vertex_Specification#Vertex_Buffer_Object

#include "BufferObject.h"

#include <vector>

class VertexBufferObject : public BufferObject {
public:
    VertexBufferObject();
    virtual ~VertexBufferObject();

    virtual void Bind() override;
    static void Unbind();

    template<typename T>
    void AllocateData(const std::vector<T>& data, Usage usage = Usage::StaticDraw) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(T) * data.size(), data.data(), usage);
    }
};