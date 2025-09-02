#pragma once

#include "BufferObject.h"

#include <vector>

class ElementBufferObject : public BufferObject {
public:
    ElementBufferObject();
    virtual ~ElementBufferObject();

    virtual void Bind() override;
    static void Unbind();

    template<typename T>
    void AllocateData(const std::vector<T>& data, Usage usage = Usage::StaticDraw) {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(T) * data.size(), data.data(), usage);
    }
};