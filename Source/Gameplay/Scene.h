#pragma once

#include "GameObject.h"

#include <vector>
#include <string>

class Scene {
public:
    Scene() {}
    // non-copyable
    Scene(const Scene&) = delete;
    void operator = (const Scene&) = delete;

    void Draw();

    void CreateGameObject(const std::string& name = "NewGameObject");

    std::vector<GameObject>& GetAllGameObjects();

private:
    std::vector<GameObject> _gameObjects;
};