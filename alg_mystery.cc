#include <iostream>

int mystery(int n) {
  if (n < 10) {
    return (10 * n) + n;
  }

  int a = mystery(n / 10);
  int b = mystery(n % 10);
  return (100 * a) + b;
}

int main() {
  // Output: 334488.
  int n = 348;
  std::cout << mystery(n) << std::endl;

  return 0;
}
