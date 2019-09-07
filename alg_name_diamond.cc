#include <iostream>

// Print name diamond on console.
// For name = BOWENLI,
// output:
// B
// BO
// BOW
// BOWE
// BOWEN
// BOWENL
// BOWENLI
//  OWENLI
//   WENLI
//    ENLI
//     NLI
//      LI
//       I

void NameDiamond(std::string& name) {
  // Name diamond.
  //
  // Time complexity: O(n^2), where n is the length of name.
  // Space complexity: O(1).

  // Print the 1st half.
  for (int i = 0; i < name.length(); i++) {
    std::cout << name.substr(0, i + 1) << std::endl;
  }

  // Print the 2nd half.
  for (int i = 0; i < name.length(); i++) {
    // Print spaces first.
    for (int j = 0; j < i + 1; j++) {
      std::cout << " ";
    }
    
    // Print the remaining name chars.
    std::cout << name.substr(i + 1, name.length() - i) << std::endl;
  }
}

int main() {
  std::string name = "BOWENLI";
  NameDiamond(name);
  
  return 0;
}
