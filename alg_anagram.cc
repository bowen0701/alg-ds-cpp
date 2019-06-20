#include <iostream>
#include <string>
#include <vector>

// Anagram: Two strings are anagram if one is a rearrangement of the other.

bool AnagramIter(std::string& str1, std::string& str2) {
  // Anagram by iteration.
  // Time complexity: O(n^2).
  // Space complexity: O(n).
  int len_str1 = str1.length();
  int len_str2 = str2.length();

  // Copy str2 to char array for match memoization.
  char str2_chars[len_str2];
  str2.copy(str2_chars, len_str2, 0);

  int pos1 = 0;
  bool is_match = true;

  while (pos1 < len_str1 && is_match) {
    int pos2 = 0;
    bool is_found = false;

    while (pos2 < len_str2 && not is_found) {
      if (str1[pos1] == str2[pos2]) {
        is_found = true;
      } else {
        pos2++;
      }
    }

    if (is_found) {
      str2_chars[pos2] = ' ';
    } else {
      is_match = false;
      break;
    }

    pos1++;
  }

  return is_match;
}

bool AnagramSort(std::string& str1, std::string& str2) {
  // Anagram by sorting.
  return true;
}

bool AnagramCount(std::string& str1, std::string& str2) {
  // Anagram by counting.
  return true;
}

int main() {
  std::string str1 = "abcd";
  std::string str2 = "dcba";

  std::cout << "Iter: " << std::boolalpha << 
      AnagramIter(str1, str2) << std::endl;

  return 0;
}
