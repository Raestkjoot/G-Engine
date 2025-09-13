#include "Scene.h"

#include "Gameplay/GameObject.h"

#include <iostream>

void Scene::Start() {
    // TODO: script->start
}

void Scene::Update() {
    // TODO: script->update
    // TODO: physics update
    // TODO: script->late update

    // Render
    for (auto& go : _gameObjects) {
        go.sprite->GetShaderProgram()->SetUniform("position", go.transform->position);
        go.sprite->GetShaderProgram()->SetUniform("rotation", go.transform->rotation);
        go.sprite->GetShaderProgram()->SetUniform("scale", go.transform->scale);
        go.sprite->Draw();
    }
}

void Scene::End() {
    // TODO: script->end
}

void Scene::CreateGameObject(const std::string &name) {
    _gameObjects.emplace_back(name);
}

std::vector<GameObject>& Scene::GetAllGameObjects() {
    return _gameObjects;
}
