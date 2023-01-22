#include <iostream>
#include <string>

void PrintAllDecimalUtil(int n_digits, std::string result) {
  // Base case when n_digits = 0.
  if (n_digits == 0) {
    std::cout << result << std::endl;
    return;
  }

  // Recursive case.
  for (int i = 0; i < 10; i++) {
    PrintAllDecimalUtil(n_digits - 1, result + std::to_string(i));
  }
}

// Print all decimal by exaustive search.
// Example: printAllDecimal(): 00, 01, 02,..., 99.
// Time complexity: O(10^n), where n is n_digits.
// Space complexity: O(10^n).
void PrintAllDecimal(int n_digits) {
  std::string result = "";
  PrintAllDecimalUtil(n_digits, result);
}

int main() {
  // Output: ""
  PrintAllDecimal(0);

  // Output: "0", "1", ..., "9"
  PrintAllDecimal(1);

  // Output: "000", "001", "002", ..., "999"
  PrintAllDecimal(3);

  return 0;
}
