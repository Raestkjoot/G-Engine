#include "BufferObject.h"

BufferObject::BufferObject() : Object(NullHandle) {
    glGenBuffers(1, &GetHandleRef());
}

BufferObject::~BufferObject() {
    glDeleteBuffers(1, &GetHandleRef());
}

void BufferObject::Bind(Target target) const {
    glBindBuffer(target, GetHandle());
}

void BufferObject::Unbind(Target target) {
    glBindBuffer(target, NullHandle);
}

void BufferObject::AllocateData(size_t size, Usage usage) {
    glBufferData(GetTarget(), size, nullptr, usage);
}

void BufferObject::AllocateData(std::span<const std::byte> data, Usage usage) {
    glBufferData(GetTarget(), data.size_bytes(), data.data(), usage);
}

void BufferObject::UpdateData(std::span<const std::byte> data, size_t offset) {
    // TODO: Update buffer data
}