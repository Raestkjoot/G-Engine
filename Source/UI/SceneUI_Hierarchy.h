# pragma once

#include "SceneUI.h"

class SceneUI_Hierarchy : public SceneUI {
public:
    SceneUI_Hierarchy(Scene* scene) : SceneUI(scene) {}

    void Update() override;

    int GetCurSelected() const;

private:
    int _selected = -1;
};