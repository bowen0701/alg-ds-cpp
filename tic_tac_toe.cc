// Tic-Tac-Toe

#include <iostream>
#include <vector>

const int kNRows = 4;
const int kNCols = 4;
const char kCross = 'X';
const char kCircle = 'O';
const char kEmpty = ' ';

class Board {
 public:
  Board {
    // Board's constructor.
    for (int r = 0; r < kNRows; r++) {
      for (int c = 0; c < kNCols; c++) {
        board_[r][c] = kEmpty;
      }
    }
    winner_ = kEmpty;
  }

  int SetNextState(int row, int col, char symbol) {
    // Set board's next state.
    if (board_[row][col] == kEmpty) {
      board_[row][col] = symbol;
      return 0;
    } else {
      std::cout << "The position (" << row << ", " << col << ") 
                    is occupied."
      return -1;
    }
  }

  char JudgeWinner() {
    // Judge winner.
  }

  void ShowBoard() {
    // Show board.
  }
 
 private:
  char CheckRows() {
    int ncrosses = 0;
    int ncircles = 0;
    for (int r = 0; r < kNRows; r++) {
      for (int c = 0; c < kNCols; c++) {
        if (board_[r][c] == kCross) {
          ncrosses++;
        } else if (board_[r][c] == kCircle) {
          ncircles++;
        }
      }

      if (ncrosses == kNCols) {
        winner_ = kCross;
        return kCross;
      }
      if (ncircles == kNCols) {
        winner_ = kCircle;
        return kCircle;
      }
      ncrosses = 0, ncircles = 0;
    }
    return kEmpty;
  }

  char CheckCols() {
    int ncrosses = 0;
    int ncircles = 0;
    for (int c = 0; c < kNCols; c++) {
      for (int r = 0; r < kNRows; r++) {
        if (board_[r][c] == kCross) {
          ncrosses++;
        } else if (board_[r][c] == kCircle) {
          ncircles++;
        }
      }

      if (ncrosses == kNRows) {
        winner_ = kCross;
        return kCross;
      }
      if (ncircles == kNRows) {
        winner_ = kCircle;
        return kCircle;
      }
      ncrosses = 0, ncircles = 0;
    }
    return kEmpty;
  }

  char CheckDiagonals() {
    // Check top-left diagonal.

    // Check top-right diagonal.
  }

  std::vector<char><std::vector<char>> board_(
    kNRows, std::vector<char>(kNCols, kEmpty));
  char winner_;
}
