#include "MenuBar.h"

#include "Gameplay/Scene.h"

#include <imgui.h>

void MenuBar::Update() {
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

void MenuBar::SetCurScene(Scene* scene) {
    _scene = scene;
}