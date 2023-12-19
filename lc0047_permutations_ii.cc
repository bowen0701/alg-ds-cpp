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

class Solution {
 public:
  // Util for permuteUnique() by DFS with backtracking.
  void DfsBacktrack(std::vector<int>& nums,
                    std::vector<int>& temp,
                    std::vector<std::vector<int>>& result,
                    std::vector<bool>& is_used) {
    // Base case.
    if (temp.size() == nums.size()) {
      result.push_back(temp);
      return;
    }

    // Recursive case: Choose i, explore, and backtrack.
    for (int i = 0; i < nums.size(); i++) {
      // Skip number i if it's used or is the same as used (i-1).
      if (is_used[i] || 
        (i > 0 && nums[i] == nums[i - 1] && is_used[i - 1])) {
        continue;
      }

      is_used[i] = true;
      temp.push_back(nums[i]);

      DfsBacktrack(nums, temp, result, is_used);

      is_used[i] = false;
      temp.pop_back();
    }
  }

  // Permute numbers with duplicates.
  // Time complexity: O(n*n!).
  // Space complexity: O(n*n!).
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    // Sort nums to avoid duplicates.
    std::sort(nums.begin(), nums.end());

    // Apply backtracking.
    std::vector<int> temp;
    std::vector<std::vector<int>> result;

    std::vector<bool> is_used;
    for (int i = 0; i < nums.size(); i++) 
      is_used.push_back(false);

    DfsBacktrack(nums, temp, result, is_used);
    return result;
  }
};

int main() {
    // Output:
    // [[1,1,2],
    //  [1,2,1],
    //  [2,1,1]]
    std::cout << "For [1, 2, 1]:" << std::endl;
    std::vector<int> nums {1, 2, 1};
    std::vector<std::vector<int>> result = Solution().permuteUnique(nums);
    Print2DVector(result);

    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    std::cout << "For [1, 2, 3]:" << std::endl;
    nums = {1, 2, 3};
    result = Solution().permuteUnique(nums);
    Print2DVector(result);

    return 0;
}
