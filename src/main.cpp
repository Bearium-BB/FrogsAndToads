#include "board_model.hpp"
#include "ansi_view.hpp"
#include "console_controller.hpp"
#include "raylib_controller.hpp"
#include "raylib_view.hpp"
#include "raylib.h"

namespace FrogToad {
    int runConsole() {
        BoardModel model;
        AnsiView view;
        ConsoleController controller;

        while (true) {
            view.draw(model);
            controller.nextMove(model);
        }

        return 0;
    }

    int runRaylib() {
        BoardModel model;
        RaylibController controller;

        InitWindow(RaylibView::windowW(), RaylibView::windowH(), "Toads & Frogs - Raylib");
        SetTargetFPS(60);

        {
            // The view's textures must live entirely within the window's lifetime.
            RaylibView view;

            while (!WindowShouldClose()) {
                controller.nextMove(model);

                BeginDrawing();
                view.draw(model);
                EndDrawing();
            }
        } // Destroy the view (and unload its textures) before closing the window.

        CloseWindow();
        return 0;
    }
}

int main() {
    return FrogToad::runConsole(); // Change to runRaylib() for Parts 1–4.
}
