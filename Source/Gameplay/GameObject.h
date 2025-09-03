#pragma once

#include "Transform.h"
#include "Sprite.h"

#include <string>

class GameObject {
public:
    GameObject(const std::string& name);
    GameObject(GameObject&& other);
    // non-copyable
    GameObject(const GameObject&) = delete;
    void operator = (const GameObject&) = delete;

    std::string name;
    Transform* transform;
    Sprite* sprite;
};