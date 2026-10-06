#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    /** @brief Presents the board as plain text using F, T, and . symbols. */
    class ConsoleView : public IView {
    public:
        /** @brief Print the board, numbered positions, and solved status. */
        void draw(const BoardModel& model) override;
    };
}
