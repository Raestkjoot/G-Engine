# pragma once

#include "UIElement.h"

class Scene;

class MenuBar : public UIElement {
public:
    void Update() override;

    // TODO: Might add global access to current scene, hence MenuBar should access it on its own.
    // Maybe an observer for when current scene changes
    void SetCurScene(Scene* scene);

private:
    Scene* _scene;
};