#include "SceneUI_Assets.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "Utils/ServiceLocator.h"
#include "Utils/Application.h"

#include <imgui.h>
#include <vector>
#include <filesystem>
#include <iostream>
#include <algorithm>

void SceneUI_Assets::Update() {
    std::filesystem::path assetsPath = std::filesystem::current_path() / "Assets";
    AssetNode assetsRoot = BuildAssetTreeRecursive(std::filesystem::current_path());

    ImGui::Begin("Assets");
    _assetId = 0;
    DisplayAssetTreeRecursive(assetsRoot);
    ImGui::End();
}

SceneUI_Assets::AssetNode SceneUI_Assets::BuildAssetTreeRecursive(std::filesystem::path path) {
    AssetNode node;
    node.path = path;
    node.isDir = true;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(entry)) {
            node.children.push_back(BuildAssetTreeRecursive(entry));
        }
        else {
            AssetNode asset;
            asset.path = entry.path();
            asset.isDir = false;
            node.children.push_back(asset);
        }
	}
    
    auto moveDirectoriesToFront = [](const AssetNode& a, const AssetNode& b) {
        return (a.isDir > b.isDir); 
    };
    std::sort(node.children.begin(), node.children.end(), moveDirectoriesToFront);

    return node;
}

void SceneUI_Assets::DisplayAssetTreeRecursive(AssetNode node) {
    for (const auto& asset : node.children) {
        if (asset.isDir) {
            if (ImGui::TreeNode(asset.path.stem().c_str())) {
                DisplayAssetTreeRecursive(asset);
                ImGui::TreePop();
            }
        }
        else {
            ImGui::PushID(_assetId++);
            if (ImGui::Selectable(asset.path.filename().c_str(), _selected == _assetId)) {
                _selected = _assetId;
            }

            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                if (asset.path.extension() == ".scene") {
                    ServiceLocator::GetApplication()->LoadScene(asset.path);
                }
            }
            ImGui::PopID();
        }
    }
}