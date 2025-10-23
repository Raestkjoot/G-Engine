#include "SceneUI_Assets.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "Utils/ServiceLocator.h"
#include "Utils/Application.h"

#include <imgui.h>
#include <vector>
#include <filesystem>
#include <iostream>

void SceneUI_Assets::Update() {
    RefreshAssets();
    ImGui::Begin("Assets");

    int i = 0;
    for (const auto& asset : _assets) {
        ImGui::PushID(i);
        if (ImGui::Selectable(asset.c_str(), _selected == i)) {
            _selected = i;
        }

        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
            if (asset.extension() == ".scene") {
                ServiceLocator::GetApplication()->LoadScene(
                    std::filesystem::current_path() / "Assets" / asset
                );
            }
        }

        ImGui::PopID();
        ++i;
    }
    
    ImGui::End();
}

void SceneUI_Assets::RefreshAssets() {
    std::filesystem::path assetsPath = std::filesystem::current_path() / "Assets";
    
    for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(assetsPath)) {
        // if (std::filesystem::path(dirEntry).extension() == ".meta"
        _assets.insert(std::filesystem::relative(dirEntry.path(), assetsPath));
    }
}