#pragma once

#include <vector>
#include <string>

class GameObject;

class Scene {
public:
    GameObject* CreateGameObject(const std::string& name = "NewGameObject");

    std::vector<GameObject>& GetAllGameObjects();

private:
    std::vector<GameObject> _gameObjects;
};