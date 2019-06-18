#include <iostream>
#include <vector>

bool BinarySearchIter(std::vector<int>& sorted_nums, int target) {
  // Binary search by iteration.
  // Time complexity: O(logn).
  // Space complexity: O(1).
  int first = 0;
  int last = sorted_nums.size() - 1;
  bool is_found = false;

  while (first <= last && !is_found) {
    int mid = first + (last - first) / 2;
    if (sorted_nums[mid] == target)
      is_found = true;
    else
      if (sorted_nums[mid] < target)
        first = mid + 1;
      else
        last = mid - 1;
  }
  return is_found;
}

bool BinarySearchRecur(std::vector<int>& sorted_nums, int target) {
  // Binary search by recursion.
  // Time complexity: O(logn).
  // Space complexity: O(n).
  if (sorted_nums.size() == 0)
    return false;
  else {
    int mid = sorted_nums.size() / 2;
    if (sorted_nums[mid] == target)
      return true;
    else {
      if (sorted_nums[mid] < target) {
        // Slice vector's right part.
        std::vector<int> sorted_nums_right = std::vector<int>(
            sorted_nums.begin() + mid + 1, sorted_nums.end());
        return BinarySearchRecur(sorted_nums_right, target);
      } else {
        // Slice vector's left part.
        std::vector<int> sorted_nums_left = std::vector<int>(
            sorted_nums.begin(), sorted_nums.begin() + mid);
        return BinarySearchRecur(sorted_nums_left, target);
      }
    }
  }
}

bool BinarySearchRecurFast(std::vector<int>& sorted_nums, int target) {
  return true;
}

int main() {
  std::vector<int> sorted_nums = 
      {17, 20, 26, 31, 44, 54, 55, 65, 77, 93, 100};
  int target = 65;

  std::cout << "Iter: " << std::boolalpha <<
      BinarySearchIter(sorted_nums, target) << std::endl;

  std::cout << "Recur: " << std::boolalpha <<
      BinarySearchRecur(sorted_nums, target) << std::endl;

  return 0;
}
