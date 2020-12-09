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

using namespace std;

class Solution {
public:
    // Util for subsets() by DFS with backtracking.
    void dfsBacktrack(vector<int>& nums,
                      vector<int>& temp,
                      vector<vector<int>>& result,
                      int start) {
        // Base case.
        result.push_back(temp);

        // Recursive case: Choose i, explore and backtrack.
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            dfsBacktrack(nums, temp, result, i + 1);
            temp.pop_back();
        }
    }

    // Subsets of numbers.
    // Time complexity: O(n*2^n).
    // Space complexity: O(n*2^n).
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        int start = 0;
        dfsBacktrack(nums, temp, result, start);
        return result;
    }
};

int main() {
    // Output: [[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]
    vector<int> nums {1, 2, 3};
    vector<vector<int>> result = Solution().subsets(nums);
    Print2DVector(result);

    return 0;
}
