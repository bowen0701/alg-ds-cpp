/*Leetcode 78. Subsets
Medium

URL: https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <vector>
#include "util.h"

class Solution {
public:
    // Util for subsets() by DFS with backtracking.
    void DfsBacktrack(std::vector<int>& nums,
                      std::vector<int>& temp,
                      std::vector<std::vector<int>>& result,
                      int start) {
        // Base case.
        result.push_back(temp);

        // Recursive case: Choose i, explore and backtrack.
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            DfsBacktrack(nums, temp, result, i + 1);
            temp.pop_back();
        }
    }

    // Subsets of numbers.
    // Time complexity: O(n*2^n).
    // Space complexity: O(n*2^n).
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> temp;
        std::vector<std::vector<int>> result;
        int start = 0;
        DfsBacktrack(nums, temp, result, start);
        return result;
    }
};

int main() {
    // Output: [[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]
    std::vector<int> nums {1, 2, 3};
    std::vector<std::vector<int>> result = Solution().subsets(nums);
    Print2DVector(result);

    return 0;
}
