#include <iostream>
#include <vector>

bool BinarySearchIter(std::vector<int>& sorted_nums, int target) {
  // Binary search by iteration.
  // Time complexity: O(logn).
  // Space complexity: O(1).
  int left = 0;
  int right = sorted_nums.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (sorted_nums[mid] == target)
      return true;
    else if (sorted_nums[mid] < target)
      // Search vector's right part.
      left = mid + 1;
    else
      // Search vector's left part.
      right = mid - 1;
  }

  if (sorted_nums[left] == target)
    return true;
  else
    return false;
}

bool BinarySearchRecur(std::vector<int>& sorted_nums, int target) {
  // Binary search by recursion.
  // Time complexity: O(logn).
  // Space complexity: O(n).
  if (sorted_nums.size() == 0)
    return false;

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

bool BinarySearchRecurFast(std::vector<int>& sorted_nums, 
                           int target, 
                           int left,
                           int right) {
  // Binary search by fast recursion with two pointers method.
  // Time complexity: O(logn).
  // Space complexity: O(1).
  if (left > right)
    return false;

  int mid = left + (right - left) / 2;
  if (sorted_nums[mid] == target) {
    return true;
  }
  else {
    if (sorted_nums[mid] < target)
      return BinarySearchRecurFast(sorted_nums, target, mid + 1, right);
    else
      return BinarySearchRecurFast(sorted_nums, target, left, mid - 1);
  }
}

int main() {
  std::vector<int> sorted_nums = 
    {17, 20, 26, 31, 44, 54, 55, 65, 77, 93, 100};
  int target = 65;

  std::cout << "Iter: " << std::boolalpha <<
    BinarySearchIter(sorted_nums, target) << std::endl;

  std::cout << "Recur: " << std::boolalpha <<
    BinarySearchRecur(sorted_nums, target) << std::endl;

  std::cout << "RecurFast: " << std::boolalpha <<
    BinarySearchRecurFast(
      sorted_nums, target, 0, sorted_nums.size()) 
    << std::endl;

  return 0;
}
