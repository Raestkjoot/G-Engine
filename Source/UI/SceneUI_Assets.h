# pragma once

#include "SceneUI.h"

#include <set>
#include <filesystem>

class SceneUI_Assets : public SceneUI {
public:
    SceneUI_Assets(Scene* scene) : SceneUI(scene) {}

    void Update() override;

    void RefreshAssets();

private:
    int _selected = -1;
    std::set<std::filesystem::path> _assets;
};