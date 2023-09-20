// Codewars: Convert a Boolean to a String
// 8 kyu
//
// URL: https://www.codewars.com/kata/551b4501ac0447318f0009cd/train/cpp
//
// Implement a function which convert the given boolean value into its string representation.
//
// Note: Only valid inputs will be given.

#include <string>

std::string boolean_to_string(bool b){
  return b ? "true" : "false";
}

int main() {
  assert(boolean_to_string(true) == "true");
  assert(boolean_to_string(false) == "false");

  return 0;
}

