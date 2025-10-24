# pragma once

#include <set>
#include <vector>
#include <filesystem>

class SceneUI_Assets {
public:
    void Update();

private:
    struct AssetNode {
        std::filesystem::path path;
        std::vector<AssetNode> children;
        bool isDir;
    };

    AssetNode BuildAssetTreeRecursive(std::filesystem::path path);
    void DisplayAssetTreeRecursive(AssetNode node);

    int _selected = -1;
    int _assetId;
    std::set<std::filesystem::path> _assets;
};

/* TODO: Notes for optimization:

There are several problems with a naive approach like this. For one, std::filesystem loves throwing exceptions left and right so you'd either wanna try+catch all filesystem calls or use a more sane API entirely.
Creating the entire directory tree up front may work perfectly fine for small folders but will fall apart quickly when for example trying to iterate over an entire drive.
An easy solution is to only populate the node children when the corresponding ImGui::TreeNode is expanded for the first time (and even better if also done on a separate thread entirely).
You may also want to further sort your nodes in some deterministic order (see StrCmpLogicalW for example on windows).
At large scales manual clipping may also become necessary (see ImGuiListClipper, although definitely a lot more tricky with variable sized nodes).
*/