#include "Window.h"

#include "Geometry/VertexArrayObject.h"
#include "Geometry/VertexBufferObject.h"
#include "Geometry/VertexAttribute.h"
#include "Geometry/ElementBufferObject.h"
#include "Shader/Shader.h"
#include "Shader/ShaderProgram.h"
#include "UI/ImGUIFrame.h"
#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"

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
    ImGUIFrame imGUIFrame;
    imGUIFrame.Initialize(*window);

    // Setup game
    Scene scene;

    //_____LOOP_____
    while (!window->ShouldClose()) {
        window->Update();

        // ImGUI new frame
        imGUIFrame.BeginFrame();
        // Menu bar
        ImGui::BeginMainMenuBar();
        if (ImGui::BeginMenu("File")) {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("GameObject")) {
            if (ImGui::MenuItem("Create New GameObject")) {
                scene.CreateGameObject();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
        // Hierarchy
        ImGui::Begin("Hierarchy");
        static int selected = -1;
        auto gameObjects = scene.GetAllGameObjects();
        for (int i = 0; i < gameObjects.size(); ++i) {
            //ImGui::Text(gameObjects[i].Name.c_str());
            ImGui::PushID(i);
            if (ImGui::Selectable(gameObjects[i].Name.c_str(), selected == i)) {
                selected = i;
            }
            ImGui::PopID();
        // if (ImGui::TreeNode("Tree Nodes")) {
        }
        ImGui::End();

        ImGui::ShowDemoWindow();

        // Draw background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw triangle
        glUseProgram(shaderProgram.GetHandle());
        vao.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Draw ImGUI
        imGUIFrame.EndFrame();
    }

    // Cleanup
    imGUIFrame.Cleanup();
}