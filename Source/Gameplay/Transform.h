#pragma once

#include "glm/glm.hpp"

class Transform {
public:
    glm::vec3 position {0.0f, 0.0f, 0.0f};
    glm::vec3 rotation {0.0f, 0.0f, 0.0f};
    glm::vec3 scale {0.0f, 0.0f, 0.0f};
};