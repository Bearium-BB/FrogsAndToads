#include <array>
#include <string>
#include "board_model.hpp"

// #define RAYLIB_BUILD 

#ifdef RAYLIB_BUILD
	#include "raylib.h"
    #include "raylib_controller.hpp"
	#include "raylib_view.hpp"
#else
	#include <iostream>
	#include "console_controller.hpp"
	#include "console_view.hpp"
	#include "ansi_view.hpp"
#endif

#ifndef RAYLIB_BUILD
int main() {
    FrogToad::BoardModel model;
    FrogToad::AnsiView view;
    FrogToad::ConsoleController controller;

    std::cout << "Toads & Frogs - Console\n\n";

    while (true) {
        view.draw(model);
        controller.nextMove(model);
        std::cout << "\n";
    }

    return 0;
}
#else
int main() {
    FrogToad::BoardModel model;
    FrogToad::RaylibView view;
    FrogToad::RaylibController ctrl;

    InitWindow(view.windowW(), view.windowH(), "Toads & Frogs - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ctrl.nextMove(model);

        BeginDrawing();
        view.draw(model);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#endif
