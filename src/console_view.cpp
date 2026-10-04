#include "console_view.hpp"
#include <iostream>

namespace FrogToad {
	namespace {
		char cellSymbol(BoardModel::Cell cell) {
			switch (cell) {
				case BoardModel::Cell::Frog: return 'F';
				case BoardModel::Cell::Toad: return 'T';
				case BoardModel::Cell::Empty: return '.';
				default: return 'X';
			}
		}
	}

	void ConsoleView::draw(const BoardModel& m) {
		for (int i{ 0 }; i < m.BoardSize; ++i) {
			std::cout << cellSymbol(m.cellAt(i));
		}
		std::cout << "\n";

		for (int i{ 0 }; i < m.BoardSize; ++i) {
			std::cout << (i + 1);
		}
		std::cout << "   (1.." << m.BoardSize << " move; R restart)\n";

		if (m.isSolved()) {
			std::cout << "Solved! Press R to restart.\n";
		}
	}
}
