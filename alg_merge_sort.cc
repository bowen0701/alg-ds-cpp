#include <iostream>
#include <vector>
#include "util.h"

// Helper method for MergeSortRecur().
// Merge two sorted vectors.
std::vector<int> MergeSortedVectorsRecur(
  std::vector<int>& sorted_nums1, 
  std::vector<int>& sorted_nums2) {
  // TODO
}

// Merge sort algorithm by recursively merging two sorted numbers.
//
// Time complexity: O(n*logn).
// Space complexity: O(n).
void MergeSortRecur(std::vector<int>& nums) {
  // Base case.
  if (nums.size() == 1)
    return nums;

  // Sort the 1st & 2nd halves respectively and merge them.
  auto mid = nums.size() / 2;
  auto sorted_nums1 = MergeSortRecur(
    std::vector<int>(nums.begin(), nums.begin() + mid - 1));
  auto sorted_nums2 = MergeSortRecur(
    std::vector<int>(nums.begin() + mid, nums.end()));
  return MergeSortedVectorsRecur(sorted_nums1, sorted_nums2);
}

// Helper method for MergeSortRecur().
// Merge two sorted vectors.
std::vector<int> MergeSortedVectorsIter(
  std::vector<int>& sorted_nums1, 
  std::vector<int>& sorted_nums2) {
  // TODO
}

// Merge sort algorithm by iteratively merging two sorted numbers.
//
// Time complexity: O(n*logn).
// Space complexity: O(n).
void MergeSortIter(std::vector<int>& nums) {
  // TODO
}

int main() {
  return 0;
}
