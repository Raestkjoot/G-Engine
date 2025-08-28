#include "SceneUI_MenuBar.h"

#include "Gameplay/Scene.h"

#include <imgui.h>

void SceneUI_MenuBar::Update() {
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File")) {
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("GameObject")) {
        if (ImGui::MenuItem("Create New GameObject")) {
            _scene->CreateGameObject();
        }
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
}