#include "console_controller.hpp"
#include <conio.h>

namespace FrogToad{
	void ConsoleController::nextMove(BoardModel& m) {
		int ch{ _getch() };

		// Arrow and function keys produce two codes: a 0 or 0xE0 prefix, then a scan code.
		// Read and discard the scan code so it cannot become the next command.
		if (ch == 0 || ch == 0xE0) {
			_getch();
			return;
		}

		applyCommand(m, ch);
	}
}
