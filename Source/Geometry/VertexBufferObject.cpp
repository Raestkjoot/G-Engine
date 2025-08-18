#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject() {}

void VertexBufferObject::AllocateData(size_t size) {
    AllocateData(size, Usage::StaticDraw);
}

void VertexBufferObject::AllocateData(std::span<const std::byte> data) {
    AllocateData(data, Usage::StaticDraw);
}