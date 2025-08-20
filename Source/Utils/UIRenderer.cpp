#include "UIRenderer.h"

#include "Window.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

UIRenderer::UIRenderer() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
}

UIRenderer::~UIRenderer() {
    ImGui::DestroyContext();
}

void UIRenderer::Initialize(Window& window) {
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window.GetInternalWindow(), true);
    ImGui_ImplOpenGL3_Init();
}

void UIRenderer::Cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
}

void UIRenderer::BeginFrame() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
}

void UIRenderer::EndFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
