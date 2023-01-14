#include <iostream>

// Build a function to duplicate each digit in a number.
// Example: 123 => 112233.
// Time complexity: O(n), where n is the size of deque.
// Space complexity: O(n).
int DuplicateDigits(int n) {
  if (n < 10) {
    return (10 * n) + n;
  }

  int a = DuplicateDigits(n / 10);
  int b = DuplicateDigits(n % 10);
  return (100 * a) + b;
}

int main() {
  // Output: 334488.
  int n = 348;
  std::cout << DuplicateDigits(n) << std::endl;

  return 0;
}
