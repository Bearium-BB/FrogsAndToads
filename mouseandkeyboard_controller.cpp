#include "mouseandkeyboard_controller.hpp"
#include <string>
#include "raylib.h"
#include "board_layout.hpp"

namespace FrogToad {
	void MouseAndKeyboardController::handleInput(BoardModel& model) {
		static_assert(BoardModel::BoardSize <= 9,
			"Single-character commands support at most nine board cells.");

		model.mousePosX = GetMousePosition().x;
		model.mousePosY = GetMousePosition().y;


		int hoveredCell = -1;

		int key = GetKeyPressed();

		Vector2 mouse = GetMousePosition();

		for (int index = 0; index < BoardModel::BoardSize; ++index) {

			if (CheckCollisionPointRec(
				mouse,
				BoardLayout::GetCellBounds(index)
			)) {
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					model.tryMove(index);
				}
				break;
			}
		}

		model.hoveredCell = hoveredCell;

		if (key == KEY_R) {
			model.reset();
			return;
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (model.hoveredCell != -1) {
				model.tryMove(hoveredCell);
			}
		}


		model.tryMove(key - KEY_ONE);


	}
}


