#include "Utils/Application.h"

#include <iostream>

int main() {
    #ifdef ENGINE_BUILD
    std::cout << "Engine build" << std::endl;
    #endif
    #ifdef GAME_BUILD
    std::cout << "Game build." << std::endl;
    #endif

    Application application;
    application.Run();
}
