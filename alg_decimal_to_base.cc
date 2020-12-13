#include <iostream>
#include <vector>

const std::string kDigits = "0123456789ABCDEF";

// Convert decimal to base by iteration.
// Time complexity: O(d/b).
// Space complexity: O(d/b).
std::string DecimalToBaseIter(int decimal, int base) {
  std::vector<int> rem_stack;
  int rem;

  while (decimal > 0) {
    rem = decimal % base;
    rem_stack.push_back(rem);
    decimal = decimal / base;
  }

  std::string base_num = "";

  while (!rem_stack.empty()) {
    int digit_pos = rem_stack[rem_stack.size() - 1];
    base_num += kDigits.substr(digit_pos, 1);
    rem_stack.pop_back();
  }

  return base_num;
}

int main() {
  // Binary: (37)_10 = (100101)_2
  int dec = 37;
  int base = 2;
  std::cout << "Iter: " << dec << " -> " << DecimalToBaseIter(dec, base);
  std::cout << std::endl;

  // Hexadecimal: (1728)_10 = (6C0)_16
  dec = 1728;
  base = 16;
  std::cout << "Iter: " << dec << " -> " << DecimalToBaseIter(dec, base);
  std::cout << std::endl;

  return 0;
}
