#include <iostream>
#include <string>

void printAllDecimalUtil(int n_digits, std::string result) {
  // Base case when n_digits = 0.
  if (n_digits == 0) {
    std::cout << result << std::endl;
    return;
  }

  // Recursive case.
  for (int i = 0; i < 10; i++) {
    printAllDecimalUtil(n_digits - 1, result + std::to_string(i));
  }
}

// Print all decimal by exaustive search.
// Example: PrintAllBinary(): 00, 01, 02,..., 99.
// Time complexity: O(10^n), where n is n_digits.
// Space complexity: O(10^n).
void printAllDecimal(int n_digits) {
  std::string result = "";
  printAllDecimalUtil(n_digits, result);
}

int main() {
  // Output: ""
  printAllDecimal(0);

  // Output: "0", "1"
  printAllDecimal(1);

  // Output: "000", "001", "010",...
  printAllDecimal(3);

  return 0;
}
