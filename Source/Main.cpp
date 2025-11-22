#include "Utils/Application.h"
#include "Utils/EngineApplication.h"

#include <iostream>

int main() {
    #ifdef ENGINE_BUILD
    EngineApplication engine;
    engine.Run();
    #endif

    #ifdef GAME_BUILD
    Application game;
    game.Run();
    #endif
}
