#include "raylib_view.hpp"
#include <string>

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);


		DrawText("Toads & Frogs", 100, 20, 40, BLACK);

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			DrawRectangleLines( (100*index)+100, 75, 100, 100, BLACK);
			DrawText(std::to_string(index + 1).c_str(), (100 * index) + 150, 185, 20, BLACK);
		}

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			switch (model.cellAt(index)) {
			case BoardModel::Cell::Frog:
				DrawCircle( (100*index)+150, 125, 25, GREEN);
				break;
			case BoardModel::Cell::Toad:
				DrawCircle( (100*index)+150, 125, 25, BROWN);
				break;
			case BoardModel::Cell::Empty:
				break;
			default:
				break;
			}
		}

		DrawText("1..9 = Move & R = Restart", 100, 220, 20, BLACK);

		switch (model.state()) {
		case BoardModel::GameState::Solved:
			DrawText("Solved! Press R to restart.", 100, 270, 20, BLUE);
			break;

		case BoardModel::GameState::Lost:
			DrawText("No more moves! Press R to restart.", 100, 270, 20, RED);
			break;

		case BoardModel::GameState::Playing:
			DrawText("Choose a piece to move.", 100, 270, 20, BLACK);
			break;
		}
	}

	int RaylibView::windowW() { return 900; }
	int RaylibView::windowH() { return 300; }
}


