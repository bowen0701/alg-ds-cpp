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
    // Util for permute() by DFS with backtracking.
    void dfsBacktrack(vector<int>& nums,
                      vector<int>& temp,
                      vector<std::vector<int>>& result,
                      vector<bool>& is_used) {
        // Base case.
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        // Recursive case: Choose i, explore, and backtrack.
        for (int i = 0; i < nums.size(); i++) {
            // If nums[i] exists in temp vector, skip nums[i].
            if (is_used[i]) continue;

            is_used[i] = true;
            temp.push_back(nums[i]);

            dfsBacktrack(nums, temp, result, is_used);

            is_used[i] = false;
            temp.pop_back();
        }
    }

    // Permute numbers.
    //
    // Time complexity: O(n*n!).
    // Space complexity: O(n*n!).
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;

        vector<bool> is_used;
        for (int i = 0; i < nums.size(); i++)
            is_used.push_back(false);

        dfsBacktrack(nums, temp, result, is_used);
        return result;
    }
};

int main() {
    // Output:
    // [
    //   [1,2,3],
    //   [1,3,2],
    //   [2,1,3],
    //   [2,3,1],
    //   [3,1,2],
    //   [3,2,1]
    // ] 
    vector<int> nums {1, 2, 3};
    vector<vector<int>> result = Solution().permute(nums);
    Print2DVector(result);

    return 0;
}
