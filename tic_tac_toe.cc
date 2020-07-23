// Tic-Tac-Toe

#include <iostream>
#include <string>
#include <vector>

const int kDim = 4
const int kNRows = kDim;
const int kNCols = kDim;
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

  char winner() {
    return winner_;
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
    // Judge winner by checking rows, columns, and diagonals.
    if (CheckRows() != kEmpty or
        CheckCols() != kEmpty or
        CheckDiags() != kEmpty) {
      return winner_;
    }
    return winner_;
  }

  void ShowBoard() {
    // Show board.
    for (int r = 0; r < kNRows; r++) {
      for (int c = 0; c < kNCols; c++) {
        std::cout << board_[r][c];
      }
      std::endl;
    }
  }
 
 private:
  void CheckRows() {
    // Check rows.
    int n_crosses = 0;
    int n_circles = 0;

    for (int r = 0; r < kNRows; r++) {
      for (int c = 0; c < kNCols; c++) {
        if (board_[r][c] == kCross) {
          n_crosses++;
        } else if (board_[r][c] == kCircle) {
          n_circles++;
        }
      }

      if (n_crosses == kDim) {
        winner_ = kCross;
      }
      if (n_circles == kDim) {
        winner_ = kCircle;
      }
      n_crosses = 0, n_circles = 0;
    }
  }

  void CheckCols() {
    // Check columns.
    int n_crosses = 0;
    int n_circles = 0;

    for (int c = 0; c < kNCols; c++) {
      for (int r = 0; r < kNRows; r++) {
        if (board_[r][c] == kCross) {
          n_crosses++;
        } else if (board_[r][c] == kCircle) {
          n_circles++;
        }
      }

      if (n_crosses == kDim) {
        winner_ = kCross;
      }
      if (n_circles == kDim) {
        winner_ = kCircle;
      }
      n_crosses = 0, n_circles = 0;
    }
  }

  void CheckDiags() {
    // Check diagonals.
    int n_crosses_diag1 = 0, n_crosses_diag2 = 0;
    int n_circles_diag1 = 0, n_circles_diag2 = 0;

    for (int r = 0; r < kNRows; r++) {
      if (board_[r][r] == kCross) {
        n_crosses_diag1++;
      } else if (board_[r][r] == kCircle) {
        n_circles_diag1++;
      }
      if (board_[r][kNCols - r - 1] == kCross) {
        n_crosses_diag2++;
      } else if (board_[r][kNCols - r - 1] == kCircle) {
        n_circles_diag2++;
      }
    }

    if (n_crosses_diag1 == kDim || n_crosses_diag2 == kDim) {
      winner_ = kCross;
      return kCross;
    }
    if (n_circles_diag1 == kDim || n_circles_diag2 == kDim) {
      winner_ = kCircle;
      return kCircle;
    }
    return kEmpty;
  }

  std::vector<char><std::vector<char>> board_(
    kNRows, std::vector<char>(kNCols, kEmpty));
  char winner_;
}

void GetUserNames(std::string user1, std::string user2) {
  // Get user names.
  std::cout << "Input user1's name: ";
  std::cin >> user1;

  std::cout << "Input user2's name: ";
  std::cin >> user2;
}

void GetUserPlay(std::string user, int row, int col) {
  // Get user's play.
}

int main() {
  Board board;
  std::string user, user1, user2;
  char winner;
  int n_plays;

  // Get two user names.
  GetUserName(user1, user2);

  // Show initial board.
  board.ShowBoard();
  std::cout << std::endl;
  
  while (n_plays < kDim * kDim) {
    int row, col;

    if (n_plays % 2 == 0) {
      user = user1;
    } else {
      user = user2;
    }

    // Put user's play.
    do {
      GetUserPlay(user, row, col);
    } while (SetNextState(row, col, kCross) == -1);

    winner = JudgeWinner();
    if (winner != kEmpty) {
      std::cout << "Congrats " << user << ", you won!" << std::endl;
      break;
    }

    n_plays++;
  }

  // Check final tie game.
  if (board.winner() == kEmpty) {
      std::cout << "Tie game." << std::endl;
  } 

  return 0;
}