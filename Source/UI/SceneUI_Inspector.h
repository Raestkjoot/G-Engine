#pragma once

class Scene;
class SceneUI_Hierarchy;

class SceneUI_Inspector {
public:
    SceneUI_Inspector(SceneUI_Hierarchy* hierarchy) : _hierarchy(hierarchy) {}

    void Update(Scene* scene);

private:
    SceneUI_Hierarchy* _hierarchy;
};