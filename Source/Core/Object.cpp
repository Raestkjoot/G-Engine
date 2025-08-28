#include "Object.h"

Object::Object(Handle handle) : _handle(handle) {}

Object::~Object() {}

// Object::Object(Object&& object) noexcept : _handle(object._handle) {
//     object._handle = NullHandle;
// }

// Object& Object::operator = (Object&& object) noexcept {
//     this->~Object();
//     _handle = object._handle;
//     object._handle = NullHandle;
//     return *this;
// }