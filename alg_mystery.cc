#include <iostream>

int Mystery(int n) {
  if (n < 10) {
    return (10 * n) + n;
  }

  int a = Mystery(n / 10);
  int b = Mystery(n % 10);
  return (100 * a) + b;
}

int main() {
  // Output: 334488.
  int n = 348;
  std::cout << Mystery(n) << std::endl;

  return 0;
}
