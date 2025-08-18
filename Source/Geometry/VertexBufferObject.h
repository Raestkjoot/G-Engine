#pragma once

#include "Core/BufferObject.h"
#include "Core/Data.h"

class VertexBufferObject : public BufferObjectBase<BufferObject::ArrayBuffer> {
public:
    VertexBufferObject();

    using BufferObject::AllocateData;
    void AllocateData(size_t size);
    void AllocateData(std::span<const std::byte> data);
    template<typename T>
    void AllocateData(std::span<const T> data, Usage usage = Usage::StaticDraw);
    template<typename T>
    void AllocateData(std::span<T> data, Usage usage = Usage::StaticDraw) { AllocateData(std::span<const T>(data), usage); }

    using BufferObject::UpdateData;
    template<typename T>
    void UpdateData(std::span<const T> data, size_t offsetBytes = 0);
    template<typename T>
    inline void UpdateData(std::span<T> data, size_t offsetBytes = 0) { UpdateData(std::span<const T>(data), offsetBytes); }
};

// Call the base implementation with the span converted to bytes
template<typename T>
void VertexBufferObject::AllocateData(std::span<const T> data, Usage usage) {
    AllocateData(Data::GetBytes(data), usage);
}

// Call the base implementation with the span converted to bytes
template<typename T>
void VertexBufferObject::UpdateData(std::span<const T> data, size_t offsetBytes) {
    UpdateData(Data::GetBytes(data), offsetBytes);
}