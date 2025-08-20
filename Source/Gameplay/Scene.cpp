#include "Scene.h"

#include "Gameplay/GameObject.h"

GameObject* Scene::CreateGameObject(const std::string& name) {
    return &_gameObjects.emplace_back(name);
}