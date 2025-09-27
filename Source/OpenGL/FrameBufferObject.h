// https://learnopengl.com/Advanced-OpenGL/Framebuffers

#pragma once

#include "BufferObject.h"

#include <vector>

class FrameBufferObject : public BufferObject {
public:
    FrameBufferObject(float width, float height);
    virtual ~FrameBufferObject();

    virtual void Bind() override;
    static void Unbind();

	unsigned int GetFrameTexture();
    void RescaleFrameBuffer(float width, float height);

private:
	unsigned int _texture;
	unsigned int _rbo;
};