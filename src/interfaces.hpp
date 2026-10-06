#pragma once
#include "board_model.hpp"

namespace FrogToad {
    /** @brief Presents game state without changing the model. */
    class IView {
    public:
        virtual ~IView() = default;

        /**
         * @brief Render the current model.
         * @param model Read-only reference of @c BoardModel to render.
         */
        virtual void draw(const BoardModel& model) = 0;
    };

    /** @brief Translates input into model requests; the model validates moves. */
    class IController {
    public:
        virtual ~IController() = default;

        /**
         * @brief Handle input; a call may apply a move or reset the model.
         * No input, ignored input, and rejected moves leave the model unchanged.
         * @param model Current game model; move requests can be rejected.
         */
        virtual void handleInput(BoardModel& model) = 0;
    };
}
