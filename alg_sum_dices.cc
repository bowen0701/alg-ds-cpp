#include <iostream>
#include <vector>
#include "util.h"

void dfsBacktrack(int n_dices, 
                  int sum,
                  std::vector<int>& temp, 
                  std::vector<std::vector<int>>& result) {
  // Util for SumDices() by DFS with backtracking.

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

std::vector<std::vector<int>> SumDices(int n_dices, int sum) {
  // List n_dices where their sums equal to sum. 
  // For example: n_dices = 2, sum = 3 => {{1, 2}, {2, 1}}.
  // Procedure: for each element i
  // - choose i
  // - explore
  // - backtrack by un-choosing i
  // Time complexity: O(6^n).
  // Space complexity: O(6^n).
  std::vector<int> temp;
  std::vector<std::vector<int>> result;
  dfsBacktrack(n_dices, sum, temp, result);
  return result;
}

int main() {
  int n_dices1 = 2;
  int sum1 = 7;
  std::vector<std::vector<int>> result1 = SumDices(n_dices1, sum1);
  Print2DVector(result1);

  int n_dices2 = 4;
  int sum2 = 11;
  std::vector<std::vector<int>> result2 = SumDices(n_dices2, sum2);
  Print2DVector(result2);

  return 0;
}
