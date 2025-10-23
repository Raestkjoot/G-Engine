# pragma once

#include <set>
#include <filesystem>

class SceneUI_Assets {
public:
    void Update();

    void RefreshAssets();

private:
    int _selected = -1;
    std::set<std::filesystem::path> _assets;
};