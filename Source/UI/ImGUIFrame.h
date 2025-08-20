#pragma once

class Window;

class ImGUIFrame {
public:
    ImGUIFrame();
    ~ImGUIFrame();

    void Initialize(::Window& window);
    void Cleanup();

    void BeginFrame();
    void EndFrame();
};