#include <iostream>
#include <vector>

void PrintSumDicesUtil(int n_dices, int sum, std::vector<int>& output) {
  // Base case.
  if (n_dices == 0) {
    if (sum == 0) {
      for (auto i : output) std::cout << i << " ";
      std::cout << std::endl;
    }
    return;
  }

  // Recursive case: speed up by skipping wasteful explorations.
  if (n_dices * 1 <= sum <= n_dices * 6) {
    for (int i = 1; i <= 6; i++) {
      // Choose i.
      output.push_back(i);

      // Explore what will follow that.
      PrintSumDicesUtil(n_dices - 1, sum - i, output);

      // Backtracking: un-choose i.
      output.pop_back();
    }
  }
}

void PrintSumDices(int n_dices, int sum) {
  // List n_dices where their sums equal to sum. 
  // For example: n_dices = 2, sum = 3 => {{1, 2}, {2, 1}}.
  // Procedure: 
  //   - choose i
  //   - explore
  //   - backtrack by un-choosing i
  // Time complexity: O(6^n).
  // Space complexity: O(6^n).
  std::vector<int> output;
  PrintSumDicesUtil(n_dices, sum, output);
}

int main() {
  int n_dices1 = 2;
  int sum1 = 7;
  PrintSumDices(n_dices1, sum1);

  int n_dices2 = 4;
  int sum2 = 11;
  PrintSumDices(n_dices2, sum2);

  return 0;
}
