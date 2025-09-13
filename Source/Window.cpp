#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string.h>

Window::Window(int width, int height, const char* title) {
    // GLFW: Window Creation
    //_____________________
    // Seems Wayland has some issues resulting in warnings about GTK and Fontconfig.
    // So, we need to force the use of xWayland
    // Based on: https://discourse.glfw.org/t/glfw-not-using-gtk-through-libdecor/2921/2
    if (strcmp(getenv("XDG_SESSION_TYPE"), "wayland") == 0) {
        glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, FramebufferResizeCallback);
    
    SetVSync(true);

    // GLAD: OpenGL Function Loading
    //_____________________________
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

bool Window::ShouldClose() const {
	return glfwWindowShouldClose(_window);
}

void Window::Update() {
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

void Window::Close() {
	glfwSetWindowShouldClose(_window, true);
}

void Window::SetVSync(bool enabled) {
    glfwSwapInterval( enabled );
}

void Window::FramebufferResizeCallback(GLFWwindow* window, int width, int height) {
	// When the window changes dimensions, we make sure to adjust the viewport to match
	glViewport(0, 0, width, height);
}