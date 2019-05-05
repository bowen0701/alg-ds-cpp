#include <iostream>

using namespace std;

long factorial_recur(int n) {
  // Factorial by recursion.
  // Time complexity: O(n).
  // Space complexity: O(n).
  if (n <= 1)
    return 1;
  
  return n * factorial_recur(n - 1);
}

long _factorial_memo(int n, long F[n]) {
  if (n <= 1)
    return 1;

  return 0;
}

long factorial_memo(int n) {
  // Factorial by top-down recursion w/ memoization.
  // Time complexity: O(n).
  // Space complexity: O(n).
  return 0;
}

// long factorial_dp(int n) {
//   // Factorial by bottom-up dynamic programming.
//   // Time complexity: O(n).
//   // Space complexity: O(n).
//   long F[n + 1];
//   F[0] = 1;
//   F[1] = 1;

//   for (int i = 2; i <= n; i++)
//     F[i] = i * F[i - 1];

//   return F[n];
// }

// long factorial_iter(int n) {
//   // Factorial by bottom-up dynamic programming w/ optimized space.
//   //
//   // Time complexity: O(n).
//   // Space complexity: O(1).
//   long fn = 1;

//   if (n <= 1)
//     return fn;
//   else
//     for (int i = 2; i <= n; i++)
//       fn = i * fn;

//   return fn;
// }

int main() {
  int n = 5;
  
  cout << "Recur: " << factorial_recur(n) << endl;
  // cout << "Memo: " << factorial_memo(n) << endl;
  // cout << "DP: " << factorial_dp(n) << endl;
  // cout << "Iter: " << factorial_iter(n) << endl;

  return 0;
}
