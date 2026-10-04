#pragma once
#include "interfaces.hpp"
#include <string>

namespace FrogToad {
    /**
     * @brief ANSI terminal implementation of FrogToad::IView.
     *
     * Renders the board using ANSI escape sequences on a text console.
     */
    class AnsiView : public IView {
    public:

	    AnsiView();
	    ~AnsiView();

        /**
        * @brief Draw the current board state to the terminal.
        * @param m Read-only reference to the current model to render.
        */
	    void draw(const BoardModel& m) override;

    private:

        /** @brief Draw a board border with one segment per cell. */
        static void drawBorder(const char* left, const char* separator, const char* right);

        // ANSI Escape Code Helpers
        static const std::string resetStyles() { return "\x1b[0m"; } 
        static const std::string clearScreen() { return "\x1b[2J"; };
        static const std::string hideCursor()  { return "\x1b[?25l"; }
        static const std::string showCursor()  { return "\x1b[?25h"; }
        static const std::string eraseAfter()  { return "\x1b[0J"; }
        static const std::string cursorHome()  { return "\x1b[H";  }
        // Fixed 256-colour palette entries keep text readable on the black background.
        static const std::string background()  { return "\x1b[48;5;16m"; }
        static const std::string white()       { return "\x1b[38;5;255m"; }
        static const std::string grey()        { return "\x1b[38;5;250m"; }
        static const std::string brown()       { return "\x1b[38;5;180m"; }
        static const std::string green()       { return "\x1b[38;5;82m"; }
        static const std::string red()         { return "\x1b[38;5;196m"; }
        static const std::string blue()        { return "\x1b[38;5;33m"; }
    };
}

