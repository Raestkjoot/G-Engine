#pragma once

#include <string>

class Scene;
class Window;

class Application {
public:
    Application();

    virtual void Run();
    void LoadScene(const std::string& scenePath);
    void Quit();

protected:
    bool IsRunning();

    Window* _window = nullptr;
    Scene* _curScene = nullptr;
};
