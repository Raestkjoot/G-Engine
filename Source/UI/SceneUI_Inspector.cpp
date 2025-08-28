#include "SceneUI_Inspector.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "UI/SceneUI_Hierarchy.h"

#include <imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h> // For InputText with std::string
#include <vector>

void SceneUI_Inspector::Update() {
        ImGui::Begin("Inspector");
        
        if (_hierarchy->GetCurSelected() != -1) {
            auto& gameObject = _scene->GetAllGameObjects()[_hierarchy->GetCurSelected()];

            ImGui::InputText("Name", &gameObject.name);
            ImGui::DragFloat3("Position", &gameObject.transform.position[0], 0.1f);
        }

        ImGui::End();
}