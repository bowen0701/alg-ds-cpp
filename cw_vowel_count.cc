// Codewars: Vowel Count
// 7 kyu
//
// URL: https://www.codewars.com/kata/54ff3102c1bad923760001f3/
//
// Return the number (count) of vowels in the given string.
// We will consider a, e, i, o, u as vowels for this Kata (but not y).
// The input string will only consist of lower case letters and/or spaces.


#include <string>
#include <unordered_set>

int getCount(const std::string& inputStr) {
  if (inputStr.size() == 0) return 0;
  
  std::unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'}; 
  
  int num_vowels = 0;
  for (auto c : inputStr) {
    if (vowels.find(c) != vowels.end()) num_vowels++;
  }
  return num_vowels;
}

int main() {
  assert(getCount("abracadabra") == 5);
  assert(getCount("bowenli") == 3);

  return 0;
}