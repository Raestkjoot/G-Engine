#include "Window.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "Utils/Timer.h"

#include "UI/ImGUIFrame.h"
#include "UI/SceneUI.h"
#include "UI/SceneUI_MenuBar.h"
#include "UI/SceneUI_Hierarchy.h"
#include "UI/SceneUI_Inspector.h"
#include "UI/SceneUI_Stats.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>

#include <iostream>
#include <chrono>
#include <thread>


int main() {
    Window* window = new Window(800, 600, "Hello Window");

    // Setup Dear ImGui context
    ImGUIFrame imGUIFrame;
    imGUIFrame.Initialize(*window);

    // TODO: Setup audio

    // Setup game
    Scene scene;
    // Setup Engine UI
    SceneUI_MenuBar menuBar(&scene);
    SceneUI_Hierarchy hierarchy(&scene);
    SceneUI_Inspector inspector(&scene, &hierarchy);
    SceneUI_Stats stats(&scene);

    Timer updateTimer;

    //_____LOOP_____
    while (!window->ShouldClose()) {
        // TODO: input
        window->Update();

        // Draw background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        float delta = updateTimer.Tick();

        if (false) { // if we want to cap our framerate
            float targetFrameRate = 30.0f;

            float extraDelta = (1.0f / targetFrameRate) - delta;
            if (extraDelta > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds((int)(extraDelta * 1000.0f)));
                delta += updateTimer.Tick(); // Because sleep is inaccurate
            }
        }

        scene.Update(delta);

        // UI
        // ImGui::ShowDemoWindow();
        imGUIFrame.BeginFrame();
        menuBar.Update();
        hierarchy.Update();
        inspector.Update();
        stats.AddDeltaTimeSample(delta);
        stats.Update();

        // Draw ImGUI
        imGUIFrame.EndFrame();
    }

    // Cleanup
    imGUIFrame.Cleanup();
}