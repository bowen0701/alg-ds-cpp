#include <iostream>

// Greatest common divisor (GCD) by Euclid's algorithm.
//
// Time complexity: O(m%n).
// Space complexity: O(1).
int GCD(int m, int n) {
  int r;
  while (n != 0) {
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}

int main() {
  int m = 10;
  int n = 4;
  std::cout << "gcd of " << m << ", " << n << ": " << GCD(m, n) << std::endl;

  return 0;
}
