#include "ansi_view.hpp"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace FrogToad {
	AnsiView::AnsiView() {
#ifdef _WIN32
		// UTF-8 strings contain the triangles and box-drawing characters.
		SetConsoleOutputCP(CP_UTF8);
#endif
		std::cout << resetStyles() << background() << clearScreen() << cursorHome() << hideCursor();
	}

	AnsiView::~AnsiView() {
		std::cout << resetStyles() << showCursor() << std::flush;
	}

	void AnsiView::drawBorder(const char* left, const char* separator, const char* right) {
		std::cout << grey() << left;
		for (int i{ 0 }; i < BoardModel::BoardSize; ++i) {
			if (i > 0) std::cout << separator;
			std::cout << "═══";
		}
		std::cout << right << '\n';
	}

	void AnsiView::draw(const BoardModel& m) {
		std::cout << cursorHome() << resetStyles() << background();

		std::cout << brown() << "Toads" << white() << " & " << green() << "Frogs" << eraseAfter() << "\n\n";
		std::cout << grey() << "1.." << m.BoardSize << " = Move & R = Restart\n\n";

		// Display the board row:
		drawBorder("╔", "╦", "╗");
		for (int i{ 0 }; i < m.BoardSize; ++i) {
			std::cout << grey() << "║ ";
			switch (m.cellAt(i)) {
				case BoardModel::Cell::Frog:
					std::cout << green() << "►";
					break;
				case BoardModel::Cell::Toad:
					std::cout << brown() << "◄";
					break;
				case BoardModel::Cell::Empty:
					std::cout << ' ';
					break;
				default:
					std::cout << 'X';
					break;
			}
			std::cout << ' ';
		}
		std::cout << grey() << "║\n";
		drawBorder("╚", "╩", "╝");

		// Display the numeric index row: 
		std::cout << grey();
		for (int i = 1; i <= m.BoardSize; ++i) {
			std::cout << "  " << i << ' ';
		}
		std::cout << "\n\n";

		// Status line
		if (m.isSolved()) {
			std::cout << blue() << "Solved! R to restart.\n";
		}
		else {
			std::cout << white() << "Choose a piece to move.\n\n";
		}

		// If previous frame printed longer lines, clear the rest of the screen area
		std::cout << eraseAfter() << resetStyles() << std::flush;
	}
 }
