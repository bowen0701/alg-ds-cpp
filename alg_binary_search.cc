#include <iostream>
#include <vector>

bool BinarySearchIter(std::vector<int>& sorted_nums, int target) {
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
  return true;
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

  // std::cout << "Recur: " << std::boolalpha <<
  //     BinarySearchRecur(sorted_nums, target) << std::endl;

  return 0;
}
