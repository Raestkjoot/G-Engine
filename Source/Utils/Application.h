#pragma once

#include <string>

class Scene;
class Window;

class Application {
public:
    Application();

    void Run();
    void LoadScene(const std::string& scenePath);
    void Quit();

private:
    bool IsRunning();

    Window* _window = nullptr;
    Scene* _curScene = nullptr;
};
