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
    void subsetsUtil(vector<int>& nums,
                     vector<int>& temp,
                     vector<vector<int>>& result,
                     int start) {
        // Util for subsets() by backtracking.

        // Base case.
        result.push_back(temp);

        // Choose i, explore and backtrack.
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            subsetsUtil(nums, temp, result, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // Create subsets of numbers.
        // Time complexity: O(n*2^n).
        // Space complexity: O(n*2^n).
        vector<int> temp;
        vector<vector<int>> result;
        int start = 0;
        subsetsUtil(nums, temp, result, start);
        return result;
    }
};

int main() {
    vector<int> nums {1, 2, 3};
    vector<vector<int>> result = Solution().subsets(nums);
    Print2DVector(result);

    return 0;
}
