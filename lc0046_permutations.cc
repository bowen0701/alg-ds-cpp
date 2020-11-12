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
                     vector<int>& temp,
                     vector<std::vector<int>>& result) {
        // Util for permute() by backtracking.

        // Base case.
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // If nums[i] exists in temp vector, skip nums[i].
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end())
                continue;

            // Choose nums[i].
            temp.push_back(nums[i]);

            // Explore what will follow that.
            permuteUtil(nums, temp, result);

            // Backtrack by unchoosing nums[i].
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // Permute number vector.
        // Time complexity: O(n*n!).
        // Space complexity: O(n*n!).
        vector<int> temp;
        vector<vector<int>> result;
        permuteUtil(nums, temp, result);
        return result;
    }
};

int main() {
    vector<int> nums {1, 2, 3};
    vector<vector<int>> result = Solution().permute(nums);
    Print2DVector(result);

    return 0;
}
