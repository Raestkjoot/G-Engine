#include "Window.h"

#include "Geometry/VertexArrayObject.h"
#include "Geometry/VertexBufferObject.h"
#include "Geometry/VertexAttribute.h"
#include "Geometry/ElementBufferObject.h"
#include "Shader/Shader.h"
#include "Shader/ShaderProgram.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <iostream>

int main()
{
    Window* window = new Window(800, 600, "Hello Window");

    // _____SETUP_____
    ShaderProgram shaderProgram;
    VertexArrayObject vao;
    {
        // Shaders
        Shader vertShader = Shader::Load(Shader::Type::VertexShader, "Assets/Default.vert");
        Shader fragShader = Shader::Load(Shader::Type::FragmentShader, "Assets/Default.frag");
        shaderProgram.Build(vertShader, fragShader);

        // Vertices
        float vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left 
        };
        unsigned int indices[] = { 
            0, 1, 3,   // first triangle
            1, 2, 3    // second triangle
        };
        // setup VBO, EBO and VAO
        VertexBufferObject vbo;
        ElementBufferObject ebo;

        vbo.Bind();
        vao.Bind();
        ebo.Bind();
        
        vbo.AllocateData(std::span(vertices, sizeof(vertices) / sizeof(float)));
        ebo.AllocateData(std::span(indices, sizeof(indices) / sizeof(unsigned int)));
        VertexAttribute position(Data::Type::Float, 3);
        vao.SetAttribute(0, position, 0);
        
        VertexArrayObject::Unbind();
        ElementBufferObject::Unbind();
        VertexBufferObject::Unbind();
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window->GetInternalWindow(), true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    //_____RENDER LOOP_____
    while (!window->ShouldClose()) {
        window->Update();

        // ImGUI new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        // Draw background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw triangle
        glUseProgram(shaderProgram.GetHandle());
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Draw ImGUI
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}