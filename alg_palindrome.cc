// Palindrome: the string is read the same forwards & backwards.

#include <iostream>
#include <vector>

bool PalindromeRecur(std::string& s) {
  // Palindrome by recursion.
  // Time complexity: O(n^2), where n is the length of s.
  // Space complexity: O(n).

  // Base case.
  if (s.length() <= 1) {
      return true;
  }

  // Recursive case.
  std::string s_sub = s.substr(1, s.length() - 2);
  return s[0] == s[s.length() - 1] && PalindromeRecur(s_sub);
}

bool PalindromeIter(std::string& s) {
  // Palindrome by iteration.
  // Time complexity: O(n), where n is the length of s.
  // Space complexity: O(1).

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
  std::string s1 = "radar";
  std::cout << std::boolalpha << PalindromeRecur(s1) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s1) << std::endl;

  // Output: false.
  std::string s2 = "bowen";
  std::cout << std::boolalpha << PalindromeRecur(s2) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s2) << std::endl;

  // Output: true.
  std::string s3 = "madam";
  std::cout << std::boolalpha << PalindromeRecur(s3) << std::endl;
  std::cout << std::boolalpha << PalindromeIter(s3) << std::endl;

  return 0;
}