#include <iostream>
#include <string>

void PrintAllBinaryUtil(int n_digits, std::string result) {
  // Base case when n_digits = 0.
  if (n_digits == 0) {
    std::cout << result << std::endl;
    return;
  }

  // Recursive case.
  PrintAllBinaryUtil(n_digits - 1, result + "0");
  PrintAllBinaryUtil(n_digits - 1, result + "1");
}

void PrintAllBinary(int n_digits) {
  // Print all binary by exaustive search.
  // Example: PrintAllBinary(2): 00, 01, 10, 11.
  // Time complexity: O(2^n), where n is n_digits.
  // Space complexity: O(2^n).
  std::string result = "";
  PrintAllBinaryUtil(n_digits, result);
}

int main() {
  // Output: ""
  PrintAllBinary(0);

  // Output: "0", "1"
  PrintAllBinary(1);

  // Output: "000", "001", "010", "011", "100", "101", "110", "111"
  PrintAllBinary(3);

  return 0;
}
