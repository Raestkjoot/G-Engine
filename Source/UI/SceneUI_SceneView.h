// https://www.codingwiththomas.com/blog/rendering-an-opengl-framebuffer-into-a-dear-imgui-window

#pragma once

#include "OpenGL/FrameBufferObject.h"

#include <glm/vec2.hpp>

class SceneUI_SceneView {
public:
    void Update();

    void BindFrameBuffer();
    void UnbindFrameBuffer();

private:
    FrameBufferObject _fbo {400.0f, 400.0f};
    glm::vec2 _size{400.0f, 400.0f};
};