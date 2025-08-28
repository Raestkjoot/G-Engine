#include "SceneUI.h"

SceneUI::SceneUI(Scene *scene) {
    _scene = scene;
}

void SceneUI::SetCurScene(Scene *scene)
{
    _scene = scene;
}