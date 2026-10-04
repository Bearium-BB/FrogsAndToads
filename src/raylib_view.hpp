#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
    // Construct after InitWindow() and destroy before CloseWindow().
    // Student texture implementations should load once in the constructor
    // and unload in the destructor; draw() only renders those resources.
    class RaylibView : public IView {
    public:
        void draw(const BoardModel& m) override;

        // Presentation configuration is available before constructing the view.
        static int windowW();
        static int windowH();
    };
}
