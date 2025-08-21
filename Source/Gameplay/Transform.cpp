#include "Transform.h"

#include <glm/ext/matrix_transform.hpp>

glm::mat4 Transform::GetTranslationMatrix() const {
    return glm::translate(glm::identity<glm::mat4>(), _translation);
}

glm::mat4 Transform::GetRotationMatrix() const {
    glm::mat4 matrix = glm::identity<glm::mat4>();
    matrix = glm::rotate(matrix, _rotation.y, glm::vec3(0, 1, 0));
    matrix = glm::rotate(matrix, _rotation.x, glm::vec3(1, 0, 0));
    matrix = glm::rotate(matrix, _rotation.z, glm::vec3(0, 0, 1));
    return matrix;
}

glm::mat4 Transform::GetScaleMatrix() const {
    return glm::scale(glm::identity<glm::mat4>(), _scale);
}

glm::mat4 Transform::GetTransformMatrix() const {
    if (IsDirty()) {
        _matrix = GetTranslationMatrix() * GetRotationMatrix() * GetScaleMatrix();
        // TODO: Get transform from parents
        _dirty = false;
    }
    return _matrix;
}

bool Transform::IsDirty() const {
    return _dirty; // TODO || (_parent && _parent->IsDirty());
}