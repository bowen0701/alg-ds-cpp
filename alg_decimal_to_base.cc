#include <iostream>
#include <vector>

// Convert decimal to base by iteration.
// Time complexity: O(d/b).
// Space complexity: O(d/b).
std::string DecimalToBase(int decimal, int base) {
  const std::string kDigits = "0123456789ABCDEF";

  std::vector<int> rem_stack;
  int rem;

  while (decimal > 0) {
    rem = decimal % base;
    rem_stack.push_back(rem);
    decimal = decimal / base;
  }

  std::string base_num_str = "";

  while (!rem_stack.empty()) {
    int digit_pos = rem_stack[rem_stack.size() - 1];
    base_num_str += kDigits.substr(digit_pos, 1);
    rem_stack.pop_back();
  }

  return base_num_str;
}

int main() {
  // Binary: (37)_10 = (100101)_2
  int dec = 37;
  int base = 2;
  std::cout << "Binary: " << dec << " -> " << DecimalToBase(dec, base);
  std::cout << std::endl;

  // Hexadecimal: (1728)_10 = (6C0)_16
  dec = 1728;
  base = 16;
  std::cout << "Hexadecimal: " << dec << " -> " << DecimalToBase(dec, base);
  std::cout << std::endl;

  return 0;
}
