#include "board_model.hpp"

namespace FrogToad {
    // --- Public API ---

    void BoardModel::reset() {
        board = StartingBoard;
    }

    bool BoardModel::isSolved() const { 
        return board == GoalBoard;
    }

    BoardModel::GameState BoardModel::state() const {
        if (isSolved()) return GameState::Solved;

        // TODO (student): Use canMove() to detect when no legal moves remain.
        // Check for a solution first: the solved board also has no legal moves.
        return GameState::Playing;
    }

    bool BoardModel::canMove(int i) const {
        return moveDestination(i) != -1;
    }

    BoardModel::Cell BoardModel::cellAt(int i) const {
        return isIndexValid(i) ? board[i] : Cell::Empty;
    }

    char BoardModel::toChar(Cell c) {
        switch (c) {
            case Cell::Empty: return '.';
            case Cell::Frog: return 'F';
            case Cell::Toad: return 'T';
            default: return 'X'; // Invalid! There are only three states to the enum.
        }
    }

    bool BoardModel::tryMove(int i) {
        const int destination{ moveDestination(i) };
        if (destination == -1) return false;

        board[destination] = board[i];
        board[i] = Cell::Empty;
        return true;
    }

    // --- Private Static Constexpr Helpers ---

    constexpr bool BoardModel::isIndexValid(int i) { 
        return i >= 0 && i < BoardSize; 
    }
    
    constexpr int BoardModel::moveDirection(Cell c) { 
        return (c == Cell::Frog) ? +1 : -1; 
    }

    // --- Private Instance Helpers ---

    bool BoardModel::isCellEmpty(int i) const { 
        return board[i] == Cell::Empty;
    }

    int BoardModel::moveDestination(int i) const {
        if (!isIndexValid(i) || isCellEmpty(i)) return -1;

        const int direction{ moveDirection(board[i]) };
        const int slideMove{ i + direction };
        const int jumpMove{ i + 2 * direction };

        if (isIndexValid(slideMove) && isCellEmpty(slideMove)) {
            return slideMove;
        }
        if (isIndexValid(slideMove) && !isCellEmpty(slideMove) && isIndexValid(jumpMove) && isCellEmpty(jumpMove)) {
            return jumpMove;
        }
        return -1;
    }

} // namespace FrogToad
