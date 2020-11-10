/* Leetcode 46. Permutations
Medium

URL: https://leetcode.com/problems/permutations/

Given a collection of distinct integers, return all possible 
permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
] 
*/

#include <vector>
#include <algorithm>
#include "util.h"

using namespace std;

class Solution {
public:
    void permuteUtil(vector<int>& nums,
                     vector<int>& vec,
                     vector<std::vector<int>>& result) {
        // Util for permute(): backtracking.

        // Base case.
        if (vec.size() == nums.size()) {
            result.push_back(vec);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // If nums[i] exists in temp vec, skip nums[i].
            if (find(vec.begin(), vec.end(), nums[i]) != vec.end())
                continue;

            // Choose nums[i].
            vec.push_back(nums[i]);

            // Explore what will follow that.
            permuteUtil(nums, vec, result);

            // Backtrack by unchoosing nums[i].
            vec.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // Permute number vector.
        // Time complexity: O(n*n!).
        // Space complexity: O(n*n!).
        vector<int> vec;
        vector<vector<int>> result;
        permuteUtil(nums, vec, result);
        return result;
    }
};

int main() {
    vector<int> nums {1, 2, 3};
    vector<vector<int>> result = Solution().permute(nums);
    Print2DVector(result);

    return 0;
}
