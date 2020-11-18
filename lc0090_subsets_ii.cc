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

using namespace std;

class Solution {
public:
    void subsetsWithDupUtil(vector<int>& nums, 
                            vector<int>& temp,
                            vector<vector<int>>& result,
                            int start) {
        // Util for subsetsWithDup() by backtracking.

        // Base case.
        result.push_back(temp);

        // Recursive case: choose i, explore, and backtrack.
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);
            subsetsWithDupUtil(nums, temp, result, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Subsets with duplicates.
        // Time complexity: O(n*2^n).
        // Space complexity: O(n*2^n).

        // Sort nums to avoid duplicates.
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> result;
        int start = 0;
        subsetsWithDupUtil(nums, temp, result, start);
        return result;
    }
};

int main() {
    // Output = [[2],[1],[1,2,2],[2,2],[1,2],[]]
    vector<int> nums {2, 1, 2};
    vector<vector<int>> result = Solution().subsetsWithDup(nums);
    Print2DVector(result);

    return 0;
}
