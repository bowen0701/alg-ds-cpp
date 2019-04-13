#include <iostream>

using namespace std;

int gcd(int m, int n) {
  // Greatest common divisor (GCD) by Euclid's algorithm.
  //
  // Time complexity: O(m%n).
  // Space complexity: O(1).
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
  cout << "gcd of " << m << ", " << n << ": " << gcd(m, n) << endl;
  return 0;
}
