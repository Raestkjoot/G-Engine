#include "Window.h"

int main()
{
    Window* window = new Window(800, 600, "Hello Window");

    while (!window->ShouldClose()) {
        window->Update();
    }
}