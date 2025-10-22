#pragma once

#include <iostream>

class Scene;
class Window;

class Application {
public:
    Application();

    void Run();
    void Quit();

private:
    bool IsRunning();

    Window* _window = nullptr;
    Scene* _curScene = nullptr;
};