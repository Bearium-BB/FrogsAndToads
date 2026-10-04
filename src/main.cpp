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
    FrogToad::RaylibController ctrl;

    InitWindow(FrogToad::RaylibView::windowW(), FrogToad::RaylibView::windowH(), "Toads & Frogs - Raylib");
    SetTargetFPS(60);

    {
        // The view's textures must live entirely within the window's lifetime.
        FrogToad::RaylibView view;

        while (!WindowShouldClose()) {
            ctrl.nextMove(model);

            BeginDrawing();
            view.draw(model);
            EndDrawing();
        }
    } // Destroy the view (and unload its textures) before closing the window.

    CloseWindow();
    return 0;
}
#endif
