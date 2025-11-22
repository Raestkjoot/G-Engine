#include "SceneUI_MenuBar.h"

#include "Gameplay/Scene.h"
#include "Gameplay/SceneLoader.h"
#include "Utils/GameBuilder.h"

#include <imgui.h>
#include <nfd.h>

#include <iostream>
#include <fstream>
#include <filesystem>

void SceneUI_MenuBar::Update(Scene* scene) {
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Save scene as...")) {
            SaveScene(scene);
        }
        if (ImGui::MenuItem("Build Project")) {
            std::cout << "Build" << std::endl;
            GameBuilder::BuildGame();
        }
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("GameObject")) {
        if (ImGui::MenuItem("Create New GameObject")) {
            scene->CreateGameObject();
        }
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
}

void SceneUI_MenuBar::SaveScene(Scene* scene) {
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = {{"Scene file", "scene"}};
    nfdsavedialogu8args_t args = {0};
    args.filterList = filters;
    args.filterCount = 1;
    args.defaultName = "NewScene.scene";
    args.defaultPath = (std::filesystem::current_path() / "Assets").c_str();
    nfdresult_t result = NFD_SaveDialogN_With(&outPath, &args);
    if (result == NFD_OKAY) {
        std::ofstream outFile(outPath);
        outFile << SceneLoader::SerializeScene(scene);
        outFile.close();
        NFD_FreePathU8(outPath);
    }
    else if (result == NFD_CANCEL) {
        std::cout << "Cancelled save." << std::endl;
    }
    else {
        std::cout << "Error: " << NFD_GetError() << std::endl;
    }
}
