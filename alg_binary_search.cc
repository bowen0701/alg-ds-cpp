#include <iostream>
#include <vector>

// Binary search by iteration.
// Time complexity: O(logn).
// Space complexity: O(1).
bool binarySearchIter(std::vector<int>& sorted_nums, int target) {
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

// Binary search by recursion.
// Time complexity: O(logn).
// Space complexity: O(n).
bool binarySearchRecur(std::vector<int>& sorted_nums, int target) {
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
      return binarySearchRecur(sorted_nums_right, target);
    } else {
      // Slice vector's left part.
      std::vector<int> sorted_nums_left = std::vector<int>(
          sorted_nums.begin(), sorted_nums.begin() + mid);
      return binarySearchRecur(sorted_nums_left, target);
    }
  }
}

// Binary search by fast recursion with two pointers method.
// Time complexity: O(logn).
// Space complexity: O(1).
bool binarySearchRecurFast(std::vector<int>& sorted_nums, 
                           int target, 
                           int left,
                           int right) {
  if (left > right)
    return false;

  int mid = left + (right - left) / 2;
  if (sorted_nums[mid] == target) {
    return true;
  }
  else {
    if (sorted_nums[mid] < target)
      return binarySearchRecurFast(sorted_nums, target, mid + 1, right);
    else
      return binarySearchRecurFast(sorted_nums, target, left, mid - 1);
  }
}

int main() {
  std::vector<int> sorted_nums = 
    {17, 20, 26, 31, 44, 54, 55, 65, 77, 93, 100};

  // Output: true.
  int target = 65;
  std::cout << "Iter: " << std::boolalpha <<
    binarySearchIter(sorted_nums, target) << std::endl;
  std::cout << "Recur: " << std::boolalpha <<
    binarySearchRecur(sorted_nums, target) << std::endl;
  std::cout << "RecurFast: " << std::boolalpha <<
    binarySearchRecurFast(
      sorted_nums, target, 0, sorted_nums.size()) 
    << std::endl;

  // Output: false.
  target = 47;
  std::cout << "Iter: " << std::boolalpha <<
    binarySearchIter(sorted_nums, target) << std::endl;
  std::cout << "Recur: " << std::boolalpha <<
    binarySearchRecur(sorted_nums, target) << std::endl;
  std::cout << "RecurFast: " << std::boolalpha <<
    binarySearchRecurFast(
      sorted_nums, target, 0, sorted_nums.size()) 
    << std::endl;

  return 0;
}
