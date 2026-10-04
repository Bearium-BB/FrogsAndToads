#pragma once
#include "board_model.hpp"

namespace FrogToad {
    /**
     * @brief Abstract view interface for rendering our game.
     *
     * Views must implement a single draw operation that receives a read-only
     * reference to the current model.
     */
    class IView {
    public:
        virtual ~IView() = default;

        /**
         * @brief Render the provided board state.
         *
         * Accepts a const reference to the current @c BoardModel. The
         * parameter is intentionally unnamed; implementers should fetch all
         * data needed to draw without mutating the model.
         */
        virtual void draw(const BoardModel&) = 0;
    };

    /**
     * @brief Abstract controller interface for handling input.
     *
     * Controllers handle player or AI input and translate it into model
     * requests. 
     */
    class IController {
    public:
        virtual ~IController() = default;

        /**
         * @brief Handle input for the current model.
         *
         * Depending on the controller, a call may apply a move, reset the
         * model, ignore input, or find no input. The model can reject a move.
         */
        virtual void handleInput(BoardModel&) = 0;
    };
}
