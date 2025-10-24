#include "Application.h"

#include "Gameplay/Scene.h"
#include "Gameplay/SceneLoader.h"
#include "Utils/ServiceLocator.h"
#include "Utils/Timer.h"
#include "Window.h"

#include "UI/ImGUIFrame.h"
#include "UI/SceneUI_SceneView.h"
#include "UI/SceneUI_MenuBar.h"
#include "UI/SceneUI_Hierarchy.h"
#include "UI/SceneUI_Inspector.h"
#include "UI/SceneUI_Stats.h"
#include "UI/SceneUI_Assets.h"

#include <glad/glad.h>
#include <nfd.h>
#include <imgui.h>

#include <iostream>
#include <filesystem>

Application::Application() :
    _window(new Window(800, 600, "Hello Window")) {
    
    ServiceLocator::SetApplication(this);
}

void Application::Run() {
    ImGUIFrame imGUIFrame;
    imGUIFrame.Initialize(*_window);

    // TODO: Setup audio

    // Setup game
    std::filesystem::path assetsPath = std::filesystem::current_path() / "Assets";
    std::filesystem::current_path(assetsPath);
    LoadScene("MainScene.scene");
    // Setup Engine UI
    SceneUI_SceneView sceneView;
    SceneUI_MenuBar menuBar;
    SceneUI_Hierarchy hierarchy;
    SceneUI_Inspector inspector(&hierarchy);
    SceneUI_Assets assets;
    SceneUI_Stats stats;

    Timer updateTimer;
    float delta = updateTimer.Tick();

    NFD_Init();

    while (IsRunning()) {
        // TODO: input
        _window->Update();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // UI
        imGUIFrame.BeginFrame();
        //ImGui::ShowDemoWindow();
        assets.Update();
        sceneView.Update();
        menuBar.Update(_curScene);
        hierarchy.Update(_curScene);
        inspector.Update(_curScene);
        stats.AddDeltaTimeSample(delta);
        stats.Update();
        imGUIFrame.EndFrame();

        // Game Scene
        sceneView.BindFrameBuffer();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        delta = updateTimer.Tick();
        _curScene->Update(delta);

        sceneView.UnbindFrameBuffer();
    }

    imGUIFrame.Cleanup();
    NFD_Quit();
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