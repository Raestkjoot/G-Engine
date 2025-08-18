#include "VertexAttribute.h"

VertexAttribute::VertexAttribute(Data::Type type, int components, bool normalized)
    : _type(type)
    , _components(components)
    , _normalized(normalized)
{}