// https://www.codingwiththomas.com/blog/rendering-an-opengl-framebuffer-into-a-dear-imgui-window

#pragma once

#include "SceneUI.h"

class FrameBufferObject;

class SceneUI_SceneView : public SceneUI {
public:
    SceneUI_SceneView(Scene* scene, FrameBufferObject* fbo) : SceneUI(scene), _fbo(fbo) {}

    void Update() override;

private:
    FrameBufferObject* _fbo;
};