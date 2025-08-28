#pragma once

class Scene;

class SceneUI {
public:
    SceneUI(Scene* scene);

    virtual void Update() = 0;

    // TODO: Might add global access to current scene, hence sceneUIElements should access it on their own.
    // Maybe an observer for when current scene changes
    void SetCurScene(Scene* scene);

protected:
    Scene* _scene;
};