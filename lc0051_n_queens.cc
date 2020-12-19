/*Leetcode 51. N-Queens.
Hard.

URL: https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an nxn chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle 
as shown above.
*/

#include <vector>
#include <string>
#include "util.h"

using namespace std;

class Solution {
public:
    // Check current queen position is valid among previous queens.
    bool isValid(vector<int>& queens) {
        int r_cur = queens.size() - 1;
        int c_cur = queens[r_cur];

        // Check any queens can attack the current queen.
        for (int r = 0; r < r_cur; r++) {
            int c = queens[r];
            int c_diff = abs(c_cur - c);
            int r_diff = abs(r_cur - r);

            // If two queens are in the same column or diagonal.
            if (c_diff == 0 || c_diff == r_diff)
                return false;
        }

        return true; 
    }

    // DFS with backtracking.
    void dfsBacktrack(int n, 
                      vector<int>& queens,
                      vector<vector<string>>& result) {
        // Base case.
        if (queens.size() == n) {
            vector<string> str;
            for (auto c : queens) {
                string s = string(c, '.') + 'Q' + string(n - c - 1, '.');
                str.push_back(s);
            }
            result.push_back(str);
            return;
        }

        // Recursive case: choose i, explore and backtrack.
        for (int c = 0; c < n; c++) {
            queens.push_back(c);
            if (isValid(queens)) {
                dfsBacktrack(n, queens, result);
            }
            queens.pop_back();
        }
    }

    // Solve N-Queens.
    // Time complexity: O(n!).
    // Space complexity: O(n).
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens;
        dfsBacktrack(n, queens, result);
        return result;
    }
};

int main() {
    // Output: [
    // [".Q..",  // Solution 1
    //  "...Q",
    //  "Q...",
    //  "..Q."],
    // ["..Q.",  // Solution 2
    //  "Q...",
    //  "...Q",
    //  ".Q.."]
    // ]
    int n = 4;
    vector<vector<string>> resultStrings = Solution().solveNQueens(n);
    Print2DVector(resultStrings);

    return 0;
}
