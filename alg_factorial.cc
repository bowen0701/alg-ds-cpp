#include <iostream>
#include <vector>

int FactorialRecur(int n) {
  // Factorial by recursion.
  // Time complexity: O(n).
  // Space complexity: O(n).
  if (n <= 1)
    return 1;
  
  return n * FactorialRecur(n - 1);
}

int FactorialMemoUtil(int n, int fact[]) {
// int FactorialMemoUtil(int n, int fact[]) {
  // Helper function for FactorialMemo().
  if (fact[n] > 0)
    return fact[n];

  if (n <= 1)
    return 1;

  fact[n] = n * FactorialMemoUtil(n - 1, fact);
  return fact[n];
}

int FactorialMemo(int n) {
  // Factorial by top-down recursion w/ memoization.
  // Time complexity: O(n).
  // Space complexity: O(n).
  int fact[n + 1];
  for (int i = 0; i <= n; i++)
    fact[i] = 0;
  fact[0] = 1;
  fact[1] = 1;

  return FactorialMemoUtil(n, fact);
}

int FactorialDp(int n) {
  // Factorial by bottom-up dynamic programming.
  // Time complexity: O(n).
  // Space complexity: O(n).
  std::vector<int> fact(n + 1, 0);
  fact[0] = 1;
  fact[1] = 1;

  for (int i = 2; i <= n; i++)
    fact[i] = i * fact[i - 1];

  return fact[n];
}

int FactorialIter(int n) {
  // Factorial by bottom-up dynamic programming w/ optimized space.
  // Time complexity: O(n).
  // Space complexity: O(1).
  int fact = 1;

  if (n <= 1)
    return fact;
  else
    for (int i = 2; i <= n; i++)
      fact = i * fact;

  return fact;
}

int main() {
  int n = 5;
  
  std::cout << "Recur: " << FactorialRecur(n) << std::endl;
  std::cout << "Memo: " << FactorialMemo(n) << std::endl;
  std::cout << "DP: " << FactorialDp(n) << std::endl;
  std::cout << "Iter: " << FactorialIter(n) << std::endl;

  return 0;
}
