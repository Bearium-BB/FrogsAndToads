#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& model) {
		ClearBackground(RAYWHITE);
		// TODO: Draw the board and game status.
	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}
