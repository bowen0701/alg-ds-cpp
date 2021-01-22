#include <iostream>
#include <string>

void printAllBinaryUtil(int n_digits, std::string result) {
  // Base case when n_digits = 0.
  if (n_digits == 0) {
    std::cout << result << std::endl;
    return;
  }

  // Recursive case.
  printAllBinaryUtil(n_digits - 1, result + "0");
  printAllBinaryUtil(n_digits - 1, result + "1");
}

// Print all binary by exaustive search.
// Example: printAllBinary(2): 00, 01, 10, 11.
// Time complexity: O(2^n), where n is n_digits.
// Space complexity: O(2^n).
void printAllBinary(int n_digits) {
  std::string result = "";
  printAllBinaryUtil(n_digits, result);
}

int main() {
  // Output: ""
  printAllBinary(0);

  // Output: "0", "1"
  printAllBinary(1);

  // Output: "000", "001", "010", "011", "100", "101", "110", "111"
  printAllBinary(3);

  return 0;
}
