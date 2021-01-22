#include <iostream>
#include <vector>
#include "util.h"

// Util for SumDices() by DFS with backtracking.
void dfsBacktrack(int n_dices, 
                  int sum,
                  std::vector<int>& temp, 
                  std::vector<std::vector<int>>& result) {
  // Base case.
  if (n_dices == 0) {
    if (sum == 0) result.push_back(temp);
    return;
  }

  // Recursive case: Choose i, explore, and backtrack.
  // Speed up by skipping wasteful explorations.
  if (n_dices * 1 <= sum <= n_dices * 6) {
    for (int i = 1; i <= 6; i++) {
      temp.push_back(i);
      dfsBacktrack(n_dices - 1, sum - i, temp, result);
      temp.pop_back();
    }
  }
}

// List n_dices where their sums equal to sum. 
// For example: n_dices = 2, sum = 3 => {{1, 2}, {2, 1}}.
// Procedure: for each element i
// - choose i
// - explore
// - backtrack by un-choosing i
// Time complexity: O(6^n).
// Space complexity: O(6^n).
std::vector<std::vector<int>> SumDices(int n_dices, int sum) {
  std::vector<int> temp;
  std::vector<std::vector<int>> result;
  dfsBacktrack(n_dices, sum, temp, result);
  return result;
}

int main() {
  int n_dices = 2;
  int sum = 7;
  std::vector<std::vector<int>> result = SumDices(n_dices, sum);
  print2DVector(result);

  n_dices = 4;
  sum = 11;
  result = SumDices(n_dices, sum);
  print2DVector(result);

  return 0;
}
