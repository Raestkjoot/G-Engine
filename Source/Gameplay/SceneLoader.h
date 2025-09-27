#pragma once

#include <string>

class Scene;

class SceneLoader {
public:
    static Scene* LoadScene(const std::string& filename);
    static std::string SerializeScene(Scene* scene);
};