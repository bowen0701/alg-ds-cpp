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
  }

  void SetNextState(int row, int col, char symbol) {
    // Set board's next state.
  }

  char JudgeWinner() {
    // Judge winner.
  }

  void ShowBoard() {
    // Show board.
  }
 
 private:
  std::vector<char><std::vector<char>> board(
    kNRows, std::vector<char>(kNCols, kEmpty));
  char winner;
}
