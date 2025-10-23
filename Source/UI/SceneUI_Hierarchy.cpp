#include "SceneUI_Hierarchy.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"

#include <imgui.h>
#include <vector>

void SceneUI_Hierarchy::Update(Scene* scene) {
    ImGui::Begin("Hierarchy");
    auto& gameObjects = scene->GetAllGameObjects();
    for (int i = 0; i < gameObjects.size(); ++i) {
        ImGui::PushID(i);
        if (ImGui::Selectable(gameObjects[i].name.c_str(), _selected == i)) {
            _selected = i;
        }
        ImGui::PopID();
    // TODO: Add foreach child if (ImGui::TreeNode("Tree Nodes")) {
    }
    ImGui::End();
}

int SceneUI_Hierarchy::GetCurSelected() const
{
    return _selected;
}

void SceneUI_Hierarchy::Unselect() {
    _selected = -1;
}