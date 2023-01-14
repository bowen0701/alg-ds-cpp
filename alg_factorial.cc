#include <iostream>
#include <vector>

// Factorial by recursion.
// Time complexity: O(n).
// Space complexity: O(n).
int FactorialRecur(int n) {
  if (n <= 1)
    return 1;
  
  return n * FactorialRecur(n - 1);
}

// Helper function for FactorialMemo().
int FactorialMemoUtil(int n, std::vector<int>& T) {
  if (T[n] > 0)
    return T[n];

  if (n <= 1)
    return 1;

  T[n] = n * FactorialMemoUtil(n - 1, T);
  return T[n];
}

// Factorial by top-down recursion w/ memoization.
// Time complexity: O(n).
// Space complexity: O(n).
int FactorialMemo(int n) {
  std::vector<int> T(n + 1, 0);
  T[0] = 1;
  T[1] = 1;

  return FactorialMemoUtil(n, T);
}

// Factorial by bottom-up dynamic programming.
// Time complexity: O(n).
// Space complexity: O(n).
int FactorialDp(int n) {
  std::vector<int> T(n + 1, 0);
  T[0] = 1;
  T[1] = 1;

  for (int i = 2; i <= n; i++)
    T[i] = i * T[i - 1];

  return T[n];
}

// Factorial by bottom-up dynamic programming w/ optimized space.
// Time complexity: O(n).
// Space complexity: O(1).
int FactorialIter(int n) {
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
