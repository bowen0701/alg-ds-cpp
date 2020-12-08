#include <iostream>
#include <vector>
#include "util.h"

// Helper method for MergeSortRecur().
// Merge two sorted vectors by recursion.
std::vector<int> MergeSortedVectorsRecur(
  std::vector<int>& sorted1, 
  std::vector<int>& sorted2) {
  // Base case.
  if (sorted1.size() != 0 && sorted2.size() == 0) {
    return sorted1;
  } else if (sorted1.size() == 0 && sorted2.size() != 0) {
    return sorted2;
  } else if (sorted1.size() == 0 && sorted2.size() == 0) {
    return std::vector<int>();
  }

  // Merge two sorted numbers one by one element.
  // If nums1[0] <= nums2[0]: return nums1[0] + merge(nums1[1:], nums2), 
  // and vice versa.
  std::vector<int> result, result2;
  if (sorted1[0] <= sorted2[0]) {
    result = std::vector<int>(sorted1.begin(), sorted1.begin() + 1);
    std::vector<int> sorted1_right(sorted1.begin() + 1, sorted1.end());
    result2 = MergeSortedVectorsRecur(sorted1_right, sorted2);
  } else {
    result = std::vector<int>(sorted2.begin(), sorted2.begin() + 1);
    std::vector<int> sorted2_right(sorted2.begin() + 1, sorted2.end());
    result2 = MergeSortedVectorsRecur(sorted1, sorted2_right);
  }
  result.insert(result.end(), result2.begin(), result2.end());
  return result;
}

// Merge sort algorithm by recursively merging two sorted numbers.
//
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> MergeSortRecur(std::vector<int>& nums) {
  // Base case.
  if (nums.size() <= 1) return nums;

  // Sort the 1st & 2nd halves respectively and merge them.
  auto mid = nums.size() / 2;
  std::vector<int> left(nums.begin(), nums.begin() + mid);
  std::vector<int> right(nums.begin() + mid, nums.end());
  auto sorted1 = MergeSortRecur(left);
  auto sorted2 = MergeSortRecur(right);
  return MergeSortedVectorsRecur(sorted1, sorted2);
}

// Helper method for MergeSortIter().
// Merge two sorted vectors.
std::vector<int> MergeSortedVectorsIter(
  std::vector<int>& sorted1, 
  std::vector<int>& sorted2) {
  
}

// Merge sort algorithm by iteratively merging two sorted numbers.
//
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> MergeSortIter(std::vector<int>& nums) {
  // Base case.
  if (nums.size() <= 1) return nums;

  // Sort the 1st & 2nd halves respectively and merge them.
  auto mid = nums.size() / 2;
  std::vector<int> left(nums.begin(), nums.begin() + mid);
  std::vector<int> right(nums.begin() + mid, nums.end());
  auto sorted1 = MergeSortIter(left);
  auto sorted2 = MergeSortIter(right);
  return MergeSortedVectorsIter(sorted1, sorted2);
}

int main() {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  std::vector<int> result = MergeSortRecur(nums);
  std::cout << "By MergeSortRecur:" << std::endl;
  PrintVector(result);

  return 0;
}
