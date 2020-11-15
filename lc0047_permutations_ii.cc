/* Leetcode 47. Permutations II
Medium

URL: https://leetcode.com/problems/permutations-ii/

Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
Constraints:
- 1 <= nums.length <= 8
- -10 <= nums[i] <= 10
*/

#include <vector>
#include <algorithm>
#include "util.h"

using namespace std;

class Solution {
public:
    void permuteUniqueUtil(vector<int>& temp,
                           vector<vector<int>>& result,
                           vector<bool>& is_used,
                           vector<int>& nums) {
        // Util for permuteUnique() by backtracking.

        // Base case.
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip number i if it's used or is the same as used (i-1).
            if (is_used[i] || 
                (i > 0 && nums[i] == nums[i - 1] && is_used[i - 1])) {
                continue;
            }

            // Choose i, explore, and backtrack.
            is_used[i] = true;
            temp.push_back(nums[i]);

            permuteUniqueUtil(temp, result, is_used, nums);

            is_used[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Sort nums to avoid duplicates.
        sort(nums.begin(), nums.end());

        // Apply backtracking.
        vector<int> temp;
        vector<vector<int>> result;

        vector<bool> is_used;
        for (int i = 0; i < nums.size(); i++) 
            is_used.push_back(false);

        permuteUniqueUtil(temp, result, is_used, nums);
        return result;
    }
};

int main() {
    vector<int> nums1 {1, 2, 1};
    vector<vector<int>> result1 = Solution().permuteUnique(nums1);
    Print2DVector(result1);

    vector<int> nums2 {1, 2, 3};
    vector<vector<int>> result2 = Solution().permuteUnique(nums2);
    Print2DVector(result2);

    return 0;
}
