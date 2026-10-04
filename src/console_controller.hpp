#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	class ConsoleController : public IController {
	public:
		/** @brief Wait for a key; request a numbered move or reset with r/R, ignoring other input. */
		void handleInput(BoardModel& model) override;
	};
}
