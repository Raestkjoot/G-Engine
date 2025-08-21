#pragma once

class Window;

// Class for creating ImGUIFrames. Call BeginFrame at the start of the rendering loop
// and EndFrame at the end of the rendering loop.
class ImGUIFrame {
public:
    ImGUIFrame();
    ~ImGUIFrame();

    void Initialize(::Window& window);
    void Cleanup();

    void BeginFrame();
    void EndFrame();
};