#include <iostream>
#include <vector>

// Palindrome: the string is read the same forwards & backwards.
// Palindrome by recursion.
// Time complexity: O(n^2), where n is the length of s.
// Space complexity: O(n).
bool PalindromeRecur(std::string& s) {
  // Base case.
  if (s.length() <= 1) {
      return true;
  }

  // Recursive case.
  std::string s_sub = s.substr(1, s.length() - 2);
  return s[0] == s[s.length() - 1] && PalindromeRecur(s_sub);
}

// Palindrome by iteration.
// Time complexity: O(n), where n is the length of s.
// Space complexity: O(1).
bool PalindromeIter(std::string& s) {
  // Base case.
  if (s.length() <= 1)
    return true;

  int left = 0;
  int right = s.length() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  // Output: true.
  std::string s = "radar";
  std::cout << std::boolalpha << PalindromeRecur(s) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s) << std::endl;

  // Output: false.
  s = "bowen";
  std::cout << std::boolalpha << PalindromeRecur(s) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s) << std::endl;

  // Output: true.
  s = "madam";
  std::cout << std::boolalpha << PalindromeRecur(s) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s) << std::endl;

  return 0;
}
