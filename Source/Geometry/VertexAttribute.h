#pragma once

#include "Core/Data.h"

// Represent an attribute stored in a vertex buffer
// This attributes can be used for things like: position, color, normal, etc.
class VertexAttribute {
public:
    VertexAttribute(Data::Type type, int components, bool normalized = false);

    inline Data::Type GetType() const { return _type; }
    inline int GetComponents() const { return _components; }
    inline bool IsNormalized() const { return _normalized; }

    inline int GetSize() const { return Data::GetTypeSize(_type) * _components; }

private:
    // Data type of the attribute. Usually an integer or floating point type
    Data::Type _type : 16;
    // How many components does the attribute have. It can be 1 for scalars or 2, 3 or 4 for vectors
    unsigned int _components : 3;
    // If an integer value is normalized, it is converted to a [0, 1] floating point on the GPU
    bool _normalized : 1;
};