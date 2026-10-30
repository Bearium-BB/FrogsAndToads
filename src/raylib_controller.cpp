#include "raylib_controller.hpp"
#include "raylib.h"
#include <iostream>

namespace FrogToad {
	void RaylibController::handleInput(BoardModel& model) {
		static_assert(BoardModel::BoardSize <= 9,
			"Single-character commands support at most nine board cells.");

		int key = GetKeyPressed();

		if (key == KEY_R) {
			model.reset();
			return;
		}

		if (key < KEY_ONE || key >= KEY_ONE + BoardModel::BoardSize) {
			return;
		}

		model.tryMove(key - KEY_ONE);
	}
}
