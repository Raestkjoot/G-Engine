#include "SceneUI_MenuBar.h"

#include "Gameplay/Scene.h"
#include "Gameplay/SceneLoader.h"

#include <imgui.h>
#include <nfd.h>

#include <iostream>
#include <fstream>

void SceneUI_MenuBar::Update() {
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Save scene as...")) {
            SaveScene();
        }
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

void SceneUI_MenuBar::SaveScene() {
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = {{"Scene file", "scene"}};
    nfdsavedialogu8args_t args = {0};
    args.filterList = filters;
    args.filterCount = 1;
    args.defaultName = "NewScene.scene";
    nfdresult_t result = NFD_SaveDialogN_With(&outPath, &args);
    if (result == NFD_OKAY) {
        std::ofstream outFile(outPath);
        outFile << SceneLoader::SerializeScene(_scene);
        outFile.close();
        NFD_FreePathU8(outPath);
    }
    else if (result == NFD_CANCEL) {
        puts("User pressed cancel");
    }
    else {
        printf("Error: %s\n", NFD_GetError());
    }
}