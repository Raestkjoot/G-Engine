#pragma once

#include "Transform.h"

#include <string>

class GameObject
{
public:
    GameObject(const std::string& name);

    std::string name;
    Transform transform;
};