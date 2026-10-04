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
     * @brief Abstract controller interface plus a model helper.
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
        virtual void nextMove(BoardModel&) = 0;

        /**
         * @brief Translate an ASCII key code into a model command.
         *
         * @param m Reference to the model.
         * @param key Integer key code; accepts a board-position digit or 'r'/'R'.
         * @return True if a move was applied or a reset was performed; otherwise false.
         *
         * @details
         * - 'r' or 'R' resets the model via BoardModel::reset().
         * - Valid board-position digits are mapped to zero-based indices by subtracting the
         *   character '1' from the pressed key (e.g., '1'→0, '2'→1, '3'→2),
         *   and passed to BoardModel::tryMove().
         * - Invalid input and recognized but illegal moves return false.
         *   This result is not a quit/continue status.
         * - Single-character commands support at most nine board cells.
         *
         * @note The digit-to-index conversion relies on ASCII ordering:
         *       '1' - '1' = 0, '2' - '1' = 1, '3' - '1' = 2, etc.
         */
        static bool applyCommand(BoardModel& m, int key) {
            static_assert(BoardModel::BoardSize <= 9,
                "Single-character commands support at most nine board cells.");

            if (key == 'r' || key == 'R') { m.reset(); return true; }
            if (key < '1' || key > '9' || key > '0' + BoardModel::BoardSize) {
                return false;
            }
            return m.tryMove(key - '1');
        }
    };
}
