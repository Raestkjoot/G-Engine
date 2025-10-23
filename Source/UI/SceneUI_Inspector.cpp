#include "SceneUI_Inspector.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "UI/SceneUI_Hierarchy.h"

#include <imgui.h>
#include <imgui/misc/cpp/imgui_stdlib.h> // For InputText with std::string
#include <vector>

void SceneUI_Inspector::Update(Scene* scene) {
        ImGui::Begin("Inspector");
        
        if (_hierarchy->GetCurSelected() != -1 && _hierarchy->GetCurSelected() < scene->GetAllGameObjects().size()) {
            auto& gameObject = scene->GetAllGameObjects()[_hierarchy->GetCurSelected()];   

            ImGui::InputText("Name", &gameObject.name);
            ImGui::DragFloat3("Position", &gameObject.transform->position[0], 0.1f);
            ImGui::DragFloat3("Rotation", &gameObject.transform->rotation[0], 0.1f);
            ImGui::DragFloat3("Scale", &gameObject.transform->scale[0], 0.1f); 
        }
        else {
            _hierarchy->Unselect();
        }

        ImGui::End();
}