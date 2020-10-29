#include <iostream>
#include <string>

void PrintAllBinaryUtil(int digits, std::string output) {
  // Base case when digits = 0.
  if (digits == 0) {
    std::cout << output << std::endl;
    return;
  }

  // Recursive case.
  PrintAllBinaryUtil(digits - 1, output + "0");
  PrintAllBinaryUtil(digits - 1, output + "1");
}

void PrintAllBinary(int digits) {
  // Print all binary by backtracking.
  // Example: PrintAllBinary(2): 00, 01, 10, 11.
  std::string output = "";
  PrintAllBinaryUtil(digits, output);
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
