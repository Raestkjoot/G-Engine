#include "Hierarchy.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"

#include <imgui.h>
#include <vector>

void Hierarchy::Update() {
    ImGui::Begin("Hierarchy");
    static int selected = -1;
    auto gameObjects = _scene->GetAllGameObjects();
    for (int i = 0; i < gameObjects.size(); ++i) {
        //ImGui::Text(gameObjects[i].Name.c_str());
        ImGui::PushID(i);
        if (ImGui::Selectable(gameObjects[i].Name.c_str(), selected == i)) {
            selected = i;
        }
        ImGui::PopID();
    // if (ImGui::TreeNode("Tree Nodes")) {
    }
    ImGui::End();
}

void Hierarchy::SetCurScene(Scene* scene) {
    _scene = scene;
}