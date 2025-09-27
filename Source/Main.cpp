#include "Window.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"
#include "Utils/Timer.h"

#include "OpenGL/FrameBufferObject.h"
#include "UI/ImGUIFrame.h"
#include "UI/SceneUI.h"
#include "UI/SceneUI_SceneView.h"
#include "UI/SceneUI_MenuBar.h"
#include "UI/SceneUI_Hierarchy.h"
#include "UI/SceneUI_Inspector.h"
#include "UI/SceneUI_Stats.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>

#include <iostream>


int main() {
    Window* window = new Window(800, 600, "Hello Window");

    // Setup Dear ImGui context
    ImGUIFrame imGUIFrame;
    imGUIFrame.Initialize(*window);

    // TODO: Setup audio

    // Setup game
    Scene scene;
    FrameBufferObject sceneBuffer(400.0f, 400.0f);
    // Setup Engine UI
    SceneUI_SceneView sceneView(&scene, &sceneBuffer);
    SceneUI_MenuBar menuBar(&scene);
    SceneUI_Hierarchy hierarchy(&scene);
    SceneUI_Inspector inspector(&scene, &hierarchy);
    SceneUI_Stats stats(&scene);

    Timer updateTimer;
    float delta = updateTimer.Tick();


    //_____LOOP_____
    while (!window->ShouldClose()) {
        // TODO: input
        window->Update();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // UI
        imGUIFrame.BeginFrame();
        // ImGui::ShowDemoWindow();
        sceneView.Update();
        menuBar.Update();
        hierarchy.Update();
        inspector.Update();
        stats.AddDeltaTimeSample(delta);
        stats.Update();
        imGUIFrame.EndFrame();

        // Game Scene
        sceneBuffer.Bind();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        delta = updateTimer.Tick();
        scene.Update(delta);

        sceneBuffer.Unbind();
    }

    // Cleanup
    imGUIFrame.Cleanup();
}