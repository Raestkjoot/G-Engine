#pragma once

#include "glm/glm.hpp"

class Transform {
public:
    inline glm::vec3 GetTranslation() const { return _translation; }
    inline void SetTranslation(const glm::vec3& translation) { _translation = translation; _dirty = true; }

    inline glm::vec3 GetRotation() const { return _rotation; }
    inline void SetRotation(const glm::vec3& rotation) { _rotation = rotation; _dirty = true; }

    inline glm::vec3 GetScale() const { return _scale; }
    inline void SetScale(const glm::vec3& scale) { _scale = scale; _dirty = true; }

    glm::mat4 GetTranslationMatrix() const;
    glm::mat4 GetRotationMatrix() const;
    glm::mat4 GetScaleMatrix() const;

    glm::mat4 GetTransformMatrix() const;

    bool IsDirty() const;

    glm::vec3 position {0.0f, 0.0f, 0.0f};

private:
    glm::vec3 _translation {0.0f, 0.0f, 0.0f};
    glm::vec3 _rotation {0.0f, 0.0f, 0.0f};
    glm::vec3 _scale {1.0f, 1.0f, 1.0f};

    // Cached matrix
    mutable glm::mat4 _matrix {1.0f};
    mutable bool _dirty = false;
};