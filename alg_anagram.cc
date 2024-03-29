// Anagram: Identify two strings are anagram if one is a rearrangement of the other.

#include <iostream>
#include <string>
#include <vector>

// Anagram by iteration.
// Time complexity: O(n^2).
// Space complexity: O(n).
bool AnagramIter(std::string& str1, std::string& str2) {
  int len_str1 = str1.length();
  int len_str2 = str2.length();

  if (len_str1 != len_str2)
    return false;

  // Copy str2 to vector for match memoization.
  std::vector<char> str2_chars(str2.begin(), str2.end());

  int pos1 = 0;
  bool is_match = true;

  while (pos1 < len_str1 && is_match) {
    int pos2 = 0;
    bool is_found = false;

    while (pos2 < len_str2 && !is_found) {
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

// Anagram by sorting.
// Time complexity: O(nlogn).
// Space complexity: O(n).
bool AnagramSort(std::string& str1, std::string& str2) {
  int len_str1 = str1.length();
  int len_str2 = str2.length();

  if (len_str1 != len_str2)
    return false;

  // Copy two strings and sort them for one-by-one char comparison.
  std::string sorted_str1 = str1;
  std::string sorted_str2 = str2;
  std::sort(sorted_str1.begin(), sorted_str1.end());
  std::sort(sorted_str2.begin(), sorted_str2.end());

  int pos = 0;
  bool is_match = true;

  while (pos < len_str1 && is_match) {
    if (sorted_str1[pos] == sorted_str2[pos]) {
      pos++;
    }
    else {
      is_match = false;
      break;
    }
  }

  return is_match;
}

bool AnagramCount(std::string& str1, std::string& str2) {
  // Anagram by counting.
  // Time complexity: O(n).
  // Space complexity: O(1).
  int len_str1 = str1.length();
  int len_str2 = str2.length();

  if (len_str1 != len_str2)
    return false;

  std::vector<int> char_vec1(26, 0);
  std::vector<int> char_vec2(26, 0);

  for (int i = 0; i < len_str1; i++) {
    int pos = abs(str1[i] - 'a');
    ++char_vec1[pos];
  }

  for (int i = 0; i < len_str2; i++) {
    int pos = abs(str2[i] - 'a');
    ++char_vec2[pos];
  }

  int pos = 0;
  bool is_match = true;

  while (pos < 26 && is_match) {
    if (char_vec1[pos] == char_vec2[pos]) {
      ++pos;
    }
    else {
      is_match = false;
      break;
    }
  }

  return is_match;
}

int main() {
  std::string str1 = "abcd";
  std::string str2 = "dcba";  // should be true.
  std::string str3 = "deba";  // should be false.

  std::cout << "By iteration: " << std::boolalpha << 
    AnagramIter(str1, str2) << std::endl;
  std::cout << "By sorting: " << std::boolalpha << 
    AnagramSort(str1, str2) << std::endl;
  std::cout << "By counting: " << std::boolalpha <<
    AnagramCount(str1, str2) << std::endl;

  std::cout << "By iteration: " << std::boolalpha << 
    AnagramIter(str1, str3) << std::endl;
  std::cout << "By sorting: " << std::boolalpha << 
    AnagramSort(str1, str3) << std::endl;
  std::cout << "By counting: " << std::boolalpha <<
    AnagramCount(str1, str3) << std::endl;

  return 0;
}
