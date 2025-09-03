#include "Scene.h"

#include "Gameplay/GameObject.h"

#include <iostream>

void Scene::Draw() {
    for (auto& go : _gameObjects) {
        go.sprite->GetShaderProgram()->SetUniform("position", go.transform->position);
        go.sprite->Draw();
    }
}

void Scene::CreateGameObject(const std::string &name) {
    _gameObjects.emplace_back(name);
}

std::vector<GameObject>& Scene::GetAllGameObjects() {
    return _gameObjects;
}
