#include "Application.h"

#include "Gameplay/Scene.h"
#include "Gameplay/SceneLoader.h"
#include "Utils/ServiceLocator.h"
#include "Utils/Timer.h"
#include "Window.h"

#include <glad/glad.h>
#include <nfd.h>
#include <imgui.h>

#include <filesystem>

Application::Application() :
    _window(new Window(800, 600, "Hello Window")) {
    
    ServiceLocator::SetApplication(this);
}

void Application::Run() {
    // Setup game
    std::filesystem::path assetsPath = std::filesystem::current_path() / "Assets";
    std::filesystem::current_path(assetsPath);
    LoadScene("MainScene.scene");

    Timer updateTimer;
    float delta = updateTimer.Tick();

    while (IsRunning()) {
        // TODO: input
        _window->Update();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Game Scene
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        delta = updateTimer.Tick();
        _curScene->Update(delta);

    }
}

void Application::LoadScene(const std::string& scenePath) {
    delete _curScene;
    _curScene = SceneLoader::LoadScene(scenePath);
}

void Application::Quit() {
    _window->Close();
}

bool Application::IsRunning() {
    return !_window->ShouldClose();
}
