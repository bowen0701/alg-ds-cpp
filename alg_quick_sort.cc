#include <iostream>
#include <vector>
#include "util.h"

// Quick sort algortihm by recursion.
//
// Procedure:
// - Pick a pivot which ideally is a median pf the list.
// - Arrange half elements which are smaller than pivot to left,
//   and the other half ones that are bigger than pivot to right.
// - Then to each half, recursively apply quicksort().
//
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> QuickSort(std::vector<int>& nums) {
  auto n = nums.size();

  // Base case.
  if (n <= 1)
    return nums;

  // Use middle num as pivot to collect small, middle & large numbers.
  auto pivot = nums[n / 2];
  std::vector<int> smalls;
  std::vector<int> middles;
  std::vector<int> larges;
  for (auto x : nums) {
    if (x < pivot) {
      smalls.push_back(x);
    } else if (x == pivot) {
      middles.push_back(x);
    } else {
      larges.push_back(x);
    }
  }

  // Concate small, middle & large numbers.
  std::vector<int> sorted_smalls = QuickSort(smalls);
  std::vector<int> sorted_larges = QuickSort(larges);
  sorted_smalls.insert(
    sorted_smalls.end(), middles.begin(), middles.end());
  sorted_smalls.insert(
    sorted_smalls.end(), sorted_larges.begin(), sorted_larges.end());
  return sorted_smalls;
}

int main() {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  std::vector<int> result = QuickSort(nums);
  PrintVector(result);

  return 0;
}
