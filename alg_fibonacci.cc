#include <iostream>
#include <vector>

int FibonacciRecur(int n) {
  // Fibonacci series by recursion.
  // Time complexity: O(2^n).
  // Space complexity: O(n).
  if (n <= 1)
    return n;

  return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

int FibonacciMemoUtil(int n, std::vector<int>& fib) {
  if (fib[n] > 0)
    return fib[n];

  if (n <= 1)
    return n;

  fib[n] = FibonacciMemoUtil(n - 1, fib) + FibonacciMemoUtil(n - 2, fib);
  return fib[n];
}

int FibonacciMemo(int n) {
  // Fibonacci series by memoization.
  // Time complexity: O(n).
  // Space complexity: O(n).
  std::vector<int> fib(n + 1, 0);
  fib[0] = 0;
  fib[1] = 1;

  return FibonacciMemoUtil(n, fib);
}


int main() {
  int n = 20;

  std::cout << "Recur: " << FibonacciRecur(n) << std::endl;
  std::cout << "Memo: " << FibonacciMemo(n) << std::endl;

  return 0;
}
