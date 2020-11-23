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
    bool isValid(vector<int>& queens) {
        // Check current queen position is valid among previous queens.
        int cur_row = queens.size() - 1;
        int cur_col = queens[cur_row];

        // Check any queens can attack the current queen.
        for (int row = 0; row < cur_row; row++) {
            int col = queens[row];
            int col_diff = abs(cur_col - col);
            int row_diff = abs(cur_row - row);

            // If two queens are in the same column or diagonal.
            if (col_diff == 0 || col_diff == row_diff)
                return false;
        }

        return true; 
    }

    void dfsBacktrack(int n, 
                      vector<int>& queens,
                      vector<vector<int>>& result) {
        // DFS with backtracking.
        // Base case.
        if (queens.size() == n) {
            result.push_back(queens);
            return;
        }

        // Recursive case: choose i, explore and backtrack.
        for (int col = 0; col < n; col++) {
            queens.push_back(col);
            if (isValid(queens))
                dfsBacktrack(n, queens, result);
            queens.pop_back();
        }
    }

    vector<vector<string>> resultToStrings(int n,
                                           vector<vector<int>>& result) {
        // Convert result to strings.
        vector<vector<string>> resultStrings;

        for (auto queens : result) {
            vector<string> strings;
            for (auto col : queens) {
                string s = string(col, '.') + 
                           'Q' + 
                           string(n - col - 1, '.');
                strings.push_back(s);
            }
            resultStrings.push_back(strings);
        }

        return resultStrings;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> result;
        vector<int> queens;
        dfsBacktrack(n, queens, result);
        return resultToStrings(n, result);
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
    Print2DStringVector(resultStrings);

    return 0;
}
