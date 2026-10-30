#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    /** @brief Translates non-blocking Raylib input into model requests (student exercise). */
    class MouseAndKeyboardController : public IController {
    public:
        /** @brief Handle available input without waiting for a key. */
        void handleInput(BoardModel& model) override;
    };
}
