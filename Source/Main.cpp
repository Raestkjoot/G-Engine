#include "Window.h"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"

#include "UI/ImGUIFrame.h"
#include "UI/SceneUI.h"
#include "UI/SceneUI_MenuBar.h"
#include "UI/SceneUI_Hierarchy.h"
#include "UI/SceneUI_Inspector.h"

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
    // Setup Engine UI
    SceneUI_MenuBar menuBar(&scene);
    SceneUI_Hierarchy hierarchy(&scene);
    SceneUI_Inspector inspector(&scene, &hierarchy);


    //_____LOOP_____
    while (!window->ShouldClose()) {
        // TODO: input
        window->Update();

        // Draw background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // UI
        // ImGui::ShowDemoWindow();
        imGUIFrame.BeginFrame();
        menuBar.Update();
        hierarchy.Update();
        inspector.Update();
        
        scene.Update();

        // Draw ImGUI
        imGUIFrame.EndFrame();
    }

    // Cleanup
    imGUIFrame.Cleanup();
}