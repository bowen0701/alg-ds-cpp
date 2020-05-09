#include <iostream>
#include <vector>

int FibonacciRecur(int n) {
  // Fibonacci series by top-down recursion.
  // Time complexity: O(2^n).
  // Space complexity: O(n).
  if (n <= 1)
    return n;

  return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

int FibonacciMemoUtil(int n, std::vector<int>& fib) {
  // Helper function for FibonacciMemo().
  if (fib[n] > 0)
    return fib[n];

  if (n <= 1)
    return n;

  fib[n] = FibonacciMemoUtil(n - 1, fib) + FibonacciMemoUtil(n - 2, fib);
  return fib[n];
}

int FibonacciMemo(int n) {
  // Fibonacci series by top-down memoization.
  // Time complexity: O(n).
  // Space complexity: O(n).
  std::vector<int> fib(n + 1, 0);
  fib[0] = 0;
  fib[1] = 1;

  return FibonacciMemoUtil(n, fib);
}

int FibonacciDp(int n) {
  // Fibonacci series by bottom-up dynamic programming.
  // Time complexity: O(n).
  // Space complexity: O(n).
  std::vector<int> fib(n + 1, 0);
  fib[0] = 0;
  fib[1] = 1;

  if (n <= 1)
    return n;

  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  return fib[n];
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
