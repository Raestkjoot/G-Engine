#pragma once

#include "SceneUI.h"

class SceneUI_Hierarchy;

class SceneUI_Inspector : public SceneUI {
public:
    SceneUI_Inspector(Scene* scene, SceneUI_Hierarchy* hierarchy) : SceneUI(scene), _hierarchy(hierarchy) {}

    void Update() override;

private:
    SceneUI_Hierarchy* _hierarchy;
};