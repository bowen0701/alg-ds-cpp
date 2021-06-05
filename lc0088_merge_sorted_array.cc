// Leetcode 88. Merge Sorted Array
// Easy
//
// URL: https://leetcode.com/problems/merge-sorted-array/
//
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as 
// one sorted array.
//
// Note:
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is greater or equal to m + n) 
// to hold additional elements from nums2.
//
// Example:
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
// Output: [1,2,2,3,5,6]

#include <vector>
#include "util.h"

class Solution {
public:
    // Merge two sorted vectors.
    // Time complexity: O(m+n).
    // Space complexity: O(1).
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // Two pointer method: Start from last elements of nums1 & nums2.
        int i = m - 1, j = n - 1;

        for (int k = nums1.size() - 1; k >= 0; k--) {
            if (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k] = nums1[i];
                    i--;
                } else {
                    nums1[k] = nums2[j];
                    j--;
                }
            } else if (i >= 0 && j < 0) {
                nums1[k] = nums1[i];
                i--;
            } else if (i < 0 && j >= 0) {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};

int main() {
    // Output: [1,2,2,3,5,6]
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2 = {2,5,6};
    int n = 3;

    Solution().merge(nums1, m, nums2, n);
    printVector(nums1);

    return 0;
}
