#pragma once
#include "raylib.h"

namespace FrogToad::BoardLayout {
    // inline to stop looping dependency errors
    inline Rectangle GetCellBounds(int index) {
        return {
            (float)((100 * index) + 100),
            75.0f,
            100.0f,
            100.0f
        };
    }

}