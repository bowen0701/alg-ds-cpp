// Codewars: Get the Middle Character
// 7 kyu
//
// URL: https://www.codewars.com/kata/56747fd5cb988479af000028/train/cpp
//
// You are going to be given a word. Your job is to return the middle character of the word. 
// If the word's length is odd, return the middle character. If the word's length is even, 
// return the middle 2 characters.
//
// #Examples:
//
// Kata.getMiddle("test") should return "es"
//
// Kata.getMiddle("testing") should return "t"
//
// Kata.getMiddle("middle") should return "dd"
//
// Kata.getMiddle("A") should return "A"

#include <string>
#include <cassert>

std::string get_middle(std::string input) {
  int len = input.length();
  if ((len & 1) == 1) {
    return input.substr(len / 2, 1);
  } else {
    return input.substr(len / 2 - 1, 2);
  }
}

int main() {
  assert(get_middle("test") == "es");
  assert(get_middle("testing") == "t");
  assert(get_middle("middle") == "dd");
  assert(get_middle("A") == "A");

  return 0;
}
