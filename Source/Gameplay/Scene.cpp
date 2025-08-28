#include "Scene.h"

#include "Gameplay/GameObject.h"

void Scene::Draw() {
    for (auto& go : _gameObjects) {
        go.sprite.Draw();
    }
}

void Scene::CreateGameObject(const std::string &name)
{
    _gameObjects.emplace_back(name);
}

std::vector<GameObject>& Scene::GetAllGameObjects() {
    return _gameObjects;
}
