/*Leetcode 90. Subsets II
Medium

URL: https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums,
return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <vector>
#include <algorithm>
#include "util.h"

class Solution {
public:
    // Util for subsetsWithDup() by DFS with backtracking.
    void dfsBacktrack(std::vector<int>& nums, 
                      std::vector<int>& temp,
                      std::vector<std::vector<int>>& result,
                      int start) {
        // Base case.
        result.push_back(temp);

        // Recursive case: choose i, explore, and backtrack.
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);
            dfsBacktrack(nums, temp, result, i + 1);
            temp.pop_back();
        }
    }

    // Subsets with duplicates.
    // Time complexity: O(n*2^n).
    // Space complexity: O(n*2^n).
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        // Sort nums to avoid duplicates.
        sort(nums.begin(), nums.end());

        // Apply DFS backtracking.
        std::vector<int> temp;
        std::vector<std::vector<int>> result;
        int start = 0;
        dfsBacktrack(nums, temp, result, start);
        return result;
    }
};

int main() {
    // Output = [[2],[1],[1,2,2],[2,2],[1,2],[]]
    std::vector<int> nums {2, 1, 2};
    std::vector<std::vector<int>> result = Solution().subsetsWithDup(nums);
    print2DVector(result);

    return 0;
}
