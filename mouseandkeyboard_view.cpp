#include "mouseandkeyboard_view.hpp"
#include "raylib.h"
#include <string>
#include <iostream>

#include "board_layout.hpp"

namespace FrogToad {
	void MouseAndKeyboardView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);


		DrawText("Toads & Frogs", 100, 20, 40, BLACK);

		Vector2 mouse = {
			(float)model.mousePosX,
			(float)model.mousePosY
		};

		for (int index = 0; index < BoardModel::BoardSize; ++index) {

			Rectangle bounds = BoardLayout::GetCellBounds(index);

			Color outline = BLACK;

			if (CheckCollisionPointRec(mouse, bounds)) {
				outline = GOLD;
			}

			DrawRectangleLinesEx(bounds, 2.0f, outline);
		}

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			Texture2D texture{};

			switch (model.cellAt(index)) {
			case BoardModel::Cell::Frog:
				texture = frogTexture;
				break;

			case BoardModel::Cell::Toad:
				texture = toadTexture;
				break;

			case BoardModel::Cell::Empty:
			default:
				continue;
			}

			DrawTexturePro(
				texture,
				{ 0, 0, (float)texture.width, (float)texture.height },
				{ (float)(100 * index) + 150, 125, 80, 80 },
				{ 40, 40 },
				0.0f,
				WHITE
			);
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

	int MouseAndKeyboardView::windowW() { return 900; }
	int MouseAndKeyboardView::windowH() { return 300; }

	MouseAndKeyboardView::~MouseAndKeyboardView() {
		UnloadTexture(frogTexture);
		UnloadTexture(toadTexture);
	}

	MouseAndKeyboardView::MouseAndKeyboardView() {
		frogTexture = LoadTexture("resources/frog.png");
		toadTexture = LoadTexture("resources/toad.png");
	}
}
