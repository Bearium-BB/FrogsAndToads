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

	void ConsoleView::draw(const BoardModel& model) {
		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			std::cout << cellSymbol(model.cellAt(index));
		}
		std::cout << "\n";

		for (int index{ 0 }; index < BoardModel::BoardSize; ++index) {
			std::cout << (index + 1);
		}
		std::cout << "   (1.." << BoardModel::BoardSize << " move; R restart)\n";

		if (model.isSolved()) {
			std::cout << "Solved! Press R to restart.\n";
		}
	}
}
