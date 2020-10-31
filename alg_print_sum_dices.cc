#include <iostream>
#include <vector>

void PrintSumDicesUtil(int dices, int sum, std::vector<int>& output) {
  // Base case.
  if (dices == 0) {
    if (sum == 0) {
      for (auto i : output) std::cout << i << " ";
      std::cout << std::endl;
    }
    return;
  }

  // Recursive cases.
  // Speed up by skipping impossible explorations.
  if (dices * 1 <= sum <= dices * 6) {
    for (int i = 1; i <= 6; i++) {
      // Choose i.
      output.push_back(i);

      // Explore what will follow that.
      PrintSumDicesUtil(dices - 1, sum - i, output);

      // Backtracking: un-choose i.
      output.pop_back();
    }
  }
}

void PrintSumDices(int dices, int sum) {
  // List dices where their sums equal to sum. 
  // For example: dices = 2, sum = 3 => {{1, 2}, {2, 1}}.
  // Procedure: 
  // - choose i, 
  // - explore, and 
  // - backtrack by un-choosing i.
  // Time complexity: O(6^n).
  // Space complexity: O(6^n).
  std::vector<int> output;
  PrintSumDicesUtil(dices, sum, output);
}

int main() {
  int dices1 = 2;
  int sum1 = 7;
  PrintSumDices(dices1, sum1);

  int dices2 = 4;
  int sum2 = 11;
  PrintSumDices(dices2, sum2);

  return 0;
}
