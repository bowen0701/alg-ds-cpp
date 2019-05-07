#include <iostream>

int FibonacciRecur(int n) {
  if (n <= 1)
    return n;

  return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

int main() {
  int n = 20;

  std::cout << "Recur: " << FibonacciRecur(n) << std::endl;

  return 0;
}
