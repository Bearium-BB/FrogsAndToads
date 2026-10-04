#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& m) {
		ClearBackground(RAYWHITE);
	}

	int RaylibView::windowW() { return 600; }
	int RaylibView::windowH() { return 300; }
}
