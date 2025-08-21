#include "Scene.h"

#include "Gameplay/GameObject.h"

GameObject* Scene::CreateGameObject(const std::string& name) {
    return &_gameObjects.emplace_back(name);
}

std::vector<GameObject> Scene::GetAllGameObjects() const {
    return _gameObjects;
}
