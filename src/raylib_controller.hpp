#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    class RaylibController : public IController {
    public:
        void handleInput(BoardModel& model) override;
    };
}
