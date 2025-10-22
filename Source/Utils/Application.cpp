#include "Application.h"

#include "Gameplay/Scene.h"
#include "Gameplay/SceneLoader.h"
#include "Utils/ServiceLocator.h"
#include "Utils/Timer.h"
#include "Window.h"

#include "UI/ImGUIFrame.h"
#include "UI/SceneUI.h"
#include "UI/SceneUI_SceneView.h"
#include "UI/SceneUI_MenuBar.h"
#include "UI/SceneUI_Hierarchy.h"
#include "UI/SceneUI_Inspector.h"
#include "UI/SceneUI_Stats.h"
#include "UI/SceneUI_Assets.h"

#include <glad/glad.h>
#include <nfd.h>

#include <iostream>

Application::Application() :
    _window(new Window(800, 600, "Hello Window")) {
    
    ServiceLocator::SetApplication(this);
}

void Application::Run() {
    ImGUIFrame imGUIFrame;
    imGUIFrame.Initialize(*_window);

    // TODO: Setup audio

    // Setup game
    Scene* scene = SceneLoader::LoadScene("Assets/MainScene.scene");
    // Setup Engine UI
    SceneUI_SceneView sceneView(scene);
    SceneUI_MenuBar menuBar(scene);
    SceneUI_Hierarchy hierarchy(scene);
    SceneUI_Inspector inspector(scene, &hierarchy);
    SceneUI_Assets assets(scene);
    SceneUI_Stats stats(scene);

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
        // ImGui::ShowDemoWindow();
        sceneView.Update();
        menuBar.Update();
        hierarchy.Update();
        inspector.Update();
        assets.Update();
        stats.AddDeltaTimeSample(delta);
        stats.Update();
        imGUIFrame.EndFrame();

        // Game Scene
        sceneView.BindFrameBuffer();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        delta = updateTimer.Tick();
        scene->Update(delta);

        sceneView.UnbindFrameBuffer();
    }
}

void Application::Quit() {
    _window->Close();
}

bool Application::IsRunning() {
    return !_window->ShouldClose();
}