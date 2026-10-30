#include "board_model.hpp"
#include "ansi_view.hpp"
#include "console_controller.hpp"
#include "raylib_controller.hpp"
#include "raylib_view.hpp"
#include "raylib.h"
#include "..\mouseandkeyboard_controller.hpp"
#include "..\mouseandkeyboard_view.hpp"

namespace FrogToad {
    /** @brief Run the console game with the ANSI View, drawing before each blocking input call. */
    int runConsole() {
        BoardModel model;
        AnsiView view;
        ConsoleController controller;

        while (true) {
            view.draw(model);
            controller.handleInput(model);
        }

        return 0;
    }

    /** @brief Run the graphical game, handling input and drawing each frame. */
    int runRaylib() {
        BoardModel model;
        MouseAndKeyboardController controller;

        InitWindow(MouseAndKeyboardView::windowW(), MouseAndKeyboardView::windowH(), "Toads & Frogs - Raylib");
        SetTargetFPS(60);

        {   // Open a scope to control the lifetime of our RaylibView. 
            // The View's textures must live entirely within the Window's lifetime.
            MouseAndKeyboardView view;

            while (!WindowShouldClose()) {
                controller.handleInput(model);

                BeginDrawing();
                view.draw(model);
                EndDrawing();
            }
        } // Destroy the view (and unload its textures) before closing the window.
        // Clean and ready to close.

        CloseWindow();
        return 0;
    }
}

int main() {
    return FrogToad::runRaylib(); // Change to runRaylib() for Parts 1–3.
}


//The assignment wasn't too bad. The detection system was pretty easy to implement, including checking whether the player could move for the Lost state.

//I think one of the biggest issues with this project, at least for me, was how everything was crammed into giant source and header files. I wish they had already been broken up into their own files or organized into filters,
//as it makes the code become unreadable very quickly.

//I also think one thing that sent me down a bit of a rabbit hole was that I initially thought you wanted controller support, rather than a controller in the MVC sense.
//Maybe renaming it to something else would be a good idea so that someone reading the assignment doesn't confuse it with a game controller. Alternatively, you could make that distinction more obvious in the instructions.
//I think it took me about two hours to complete everything, give or take.

//For the most part, I found the assignment very oddly worded, which made it confusing pretty quickly. Eventually,
// I caught on to what you meant by creating another class to hold the layout and then providing that to the controller and view separately from the model.
// The model could probably store the layout in an object as well, but I think it comes down to which approach you prefer.

//That's one of the reasons I like the MVP approach more. You can send information back to the controller through the view, which helps address some of these issues without creating extra work,
// adding more places to manage things, or having data scattered randomly throughout the project.

//Overall, I think the assignment was fun, just a little messy on the organizational side because there were so many unorganized files.

//One other thing I noticed is that including the Raylib header in the BM seems to make everything freak out and stop working. 
// It's a little bug I ran into while trying to use Raylib's vectors instead of splitting up the mouse position into separate X and Y values. 
// I'm not sure what caused it, but it sounds like something you could figure out as a nerd snipe!

//Anyway, I hope you enjoyed reading this!