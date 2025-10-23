# pragma once

class Scene;

class SceneUI_MenuBar {
public:
    void Update(Scene* scene);

private:
    void SaveScene(Scene* scene);
};