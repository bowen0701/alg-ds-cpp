#include <iostream>
#include <string>

void PrintAllDecimalUtil(int digits, std::string output) {
  // Base case when digits = 0.
  if (digits == 0) {
    std::cout << output << std::endl;
    return;
  }

  // Recursive case.
  for (int i = 0; i < 10; i++) {
    PrintAllDecimalUtil(digits - 1, output + std::to_string(i));
  }
}

void PrintAllDecimal(int digits) {
  // Print all decimal by exaustive search.
  // Example: PrintAllBinary(): 00, 01, 02,..., 99.
  // Time complexity: O(10^n), where n is digits.
  // Space complexity: O(10^n).
  std::string output = "";
  PrintAllDecimalUtil(digits, output);
}

int main() {
  // Output: ""
  PrintAllDecimal(0);

  // Output: "0", "1"
  PrintAllDecimal(1);

  // Output: "000", "001", "010",...
  PrintAllDecimal(3);

  return 0;
}
