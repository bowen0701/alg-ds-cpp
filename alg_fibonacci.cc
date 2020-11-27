#include <iostream>
#include <vector>

// Fibonacci series by top-down recursion.
//
// Time complexity: O(2^n).
// Space complexity: O(n).
int FibonacciRecur(int n) {
  if (n <= 1)
    return n;

  return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

// Helper function for FibonacciMemo().
int FibonacciMemoUtil(int n, std::vector<int>& T) {
  if (T[n] > 0)
    return T[n];

  if (n <= 1)
    return n;

  T[n] = FibonacciMemoUtil(n - 1, T) + FibonacciMemoUtil(n - 2, T);
  return T[n];
}

// Fibonacci series by top-down memoization.
//
// Time complexity: O(n).
// Space complexity: O(n).
int FibonacciMemo(int n) {
  std::vector<int> T(n + 1, 0);
  T[0] = 0;
  T[1] = 1;

  return FibonacciMemoUtil(n, T);
}

// Fibonacci series by bottom-up dynamic programming.
//
// Time complexity: O(n).
// Space complexity: O(n).
int FibonacciDp(int n) {
  std::vector<int> T(n + 1, 0);
  T[0] = 0;
  T[1] = 1;

  if (n <= 1)
    return n;

  for (int i = 2; i <= n; i++) {
    T[i] = T[i - 1] + T[i - 2];
  }

  return T[n];
}

int FibonacciIter(int n) {
  // Fibonacci series by bottom-up iteration w/ optimizaed space.
  // Time complexity: O(n).
  // Space complexity: O(1).
  if (n <= 1)
    return n;

  int a = 0;
  int b = 1;
  for (int i = 2; i <= n; i++) {
    b = a + b;
    a = b - a;
  }
  return b;
}

int main() {
  int n = 20;

  std::cout << "Recur: " << FibonacciRecur(n) << std::endl;
  std::cout << "Memo: " << FibonacciMemo(n) << std::endl;
  std::cout << "DP: " << FibonacciDp(n) << std::endl;
  std::cout << "Iter: " << FibonacciIter(n) << std::endl;

  return 0;
}
