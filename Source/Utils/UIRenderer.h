#pragma once

class Window;

class UIRenderer {
public:
    UIRenderer();
    ~UIRenderer();

    void Initialize(::Window& window);
    void Cleanup();

    void BeginFrame();
    void EndFrame();
};