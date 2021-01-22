#include <iostream>
#include <vector>

// Fibonacci series by top-down recursion.
// Time complexity: O(2^n).
// Space complexity: O(n).
int fibonacciRecur(int n) {
  if (n <= 1)
    return n;

  return fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
}

// Helper function for FibonacciMemo().
int fibonacciMemoUtil(int n, std::vector<int>& T) {
  if (T[n] > 0)
    return T[n];

  if (n <= 1)
    return n;

  T[n] = fibonacciMemoUtil(n - 1, T) + fibonacciMemoUtil(n - 2, T);
  return T[n];
}

// Fibonacci series by top-down memoization.
// Time complexity: O(n).
// Space complexity: O(n).
int fibonacciMemo(int n) {
  std::vector<int> T(n + 1, 0);
  T[0] = 0;
  T[1] = 1;

  return fibonacciMemoUtil(n, T);
}

// Fibonacci series by bottom-up dynamic programming.
// Time complexity: O(n).
// Space complexity: O(n).
int fibonacciDp(int n) {
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

// Fibonacci series by bottom-up iteration w/ optimizaed space.
// Time complexity: O(n).
// Space complexity: O(1).
int fibonacciIter(int n) {
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

  std::cout << "Recur: " << fibonacciRecur(n) << std::endl;
  std::cout << "Memo: " << fibonacciMemo(n) << std::endl;
  std::cout << "DP: " << fibonacciDp(n) << std::endl;
  std::cout << "Iter: " << fibonacciIter(n) << std::endl;

  return 0;
}
