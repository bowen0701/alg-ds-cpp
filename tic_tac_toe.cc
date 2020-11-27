// Tic-Tac-Toe

#include <iostream>
#include <string>
#include <vector>

const int kDim = 3;
const int kNRows = kDim;
const int kNCols = kDim;
const char kCross = 'X';
const char kCircle = 'O';
const char kEmpty = ' ';

class Board {
 public:
  // Board's constructor.
  Board() {
    for (int r = 0; r < kNRows; r++) {
      for (int c = 0; c < kNCols; c++) {
        board_[r][c] = kEmpty;
      }
    }
    winner_ = kEmpty;
  }

  // Get winner.
  char winner() {
    return winner_;
  }

  // Check (row, col) is out of boundary.
  int SetNextState(int& row, int& col, char symbol) {
    if (row < 0 || row >= kNRows || col < 0 || col >= kNCols) {
      std::cout << "The position (" << row << ", " << col 
        << ") is out of boundary. ";
      return -1;
    }

    // Set board's next state.
    if (board_[row][col] == kEmpty) {
      board_[row][col] = symbol;
      return 0;
    } else {
      std::cout << "The position (" << row << ", " << col
        << ") is occupied. ";
      return -1;
    }
  }

  // Judge winner by checking rows, columns, and diagonals.
  int JudgeWinner() {
    if (CheckRows() != kEmpty or
        CheckCols() != kEmpty or
        CheckDiags() != kEmpty) {
      return 0;
    }
    return 0;
  }

  // Show board.
  void ShowBoard() {
    std::cout << "Board:" << std::endl;
    std::string cap = " -";
    std::string col_ids = "  ";
    for (int c = 0; c < kNCols; c++) {
      col_ids += '0' + c, col_ids += ' ';
      cap += "--";
    }
    std::cout << col_ids << std::endl;
    std::cout << cap << std::endl;

    for (int r = 0; r < kNRows; r++) {
      std::cout << r << "|";
      for (int c = 0; c < kNCols; c++) {
        std::cout << board_[r][c] << "|";
      }
      std::cout << std::endl;
    }
  }
 
 private:
  std::vector<std::vector<char>> board_{
    kNRows, std::vector<char>(kNCols)};
  char winner_;

  // Check rows for winner.
  char CheckRows() {
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
        break;
      }
      if (n_circles == kDim) {
        winner_ = kCircle;
        break;
      }
      n_crosses = 0, n_circles = 0;
    }
    return winner_;
  }

  // Check columns for winner.
  char CheckCols() {
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
        break;
      }
      if (n_circles == kDim) {
        winner_ = kCircle;
        break;
      }
      n_crosses = 0, n_circles = 0;
    }
    return winner_;
  }

  // Check diagonals for winner.
  char CheckDiags() {
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
    }
    if (n_circles_diag1 == kDim || n_circles_diag2 == kDim) {
      winner_ = kCircle;
    }
    return winner_;
  }
};

// Get user names.
void GetUserNames(std::string& user1, std::string& user2) {
  std::cout << "Input user1's name: ";
  std::cin >> user1;
  std::cout << "Input user2's name: ";
  std::cin >> user2;
}

// Get user's play position.
void GetUserPlay(std::string& user, int& row, int& col) {
  std::cout << "User " << user << ", please select a position:" 
    << std::endl;
  std::cout << "- Enter an integer between 0 and " << kNRows - 1 
    << " for row index:" << std::endl;
  std::cin >> row;
  std::cout << "- Enter an integer between 0 and " << kNCols - 1 
    << " for col index" << std::endl;
  std::cin >> col;
}

int main() {
  Board board;
  std::string user, user1, user2;
  char winner;
  char symbol = kEmpty;
  int n_plays = 0;

  // Get two user names.
  GetUserNames(user1, user2);

  // Show initial board.
  board.ShowBoard();
  std::cout << std::endl;
  
  while (n_plays < kDim * kDim) {
    // Interchangeably let user play.
    int row, col;

    if (n_plays % 2 == 0) {
      user = user1;
      symbol = kCross;
    } else {
      user = user2;
      symbol = kCircle;
    }

    // Put user's play.
    do {
      GetUserPlay(user, row, col);
    } while (board.SetNextState(row, col, symbol) == -1);
    board.ShowBoard();
    board.JudgeWinner();
    if (board.winner() != kEmpty) {
      std::cout << "Congrats " << user << ", you win!" << std::endl;
      break;
    }
    std::cout << std::endl;

    n_plays++;
  }

  // Check final tie game.
  if (board.winner() == kEmpty) {
      std::cout << "Tie game." << std::endl;
  } 

  return 0;
}
