# pragma once

#include "SceneUI.h"

class SceneUI_MenuBar : public SceneUI {
public:
    SceneUI_MenuBar(Scene* scene) : SceneUI(scene) {}

    void Update() override;
};