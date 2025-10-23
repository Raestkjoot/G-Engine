# pragma once

class Scene;

class SceneUI_Hierarchy {
public:
    void Update(Scene* scene);

    int GetCurSelected() const;
    void Unselect();

private:
    int _selected = -1;
};