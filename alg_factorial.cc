#include <iostream>

using namespace std;

int FactorialRecur(int n) {
  // Factorial by recursion.
  // Time complexity: O(n).
  // Space complexity: O(n).
  if (n <= 1)
    return 1;
  
  return n * FactorialRecur(n - 1);
}

long FactorialMemoUtil(int n, int F[]) {
  // Helper function for factorial_memo().
  if (n <= 1)
    return 1;

  if (F[n] > 0)
    return F[n];

  F[n] = n * FactorialMemoUtil(n - 1, F);
  return F[n];
}

long FactorialMemo(int n) {
  // Factorial by top-down recursion w/ memoization.
  // Time complexity: O(n).
  // Space complexity: O(n).
  int F[n];
  for (int i = 0; i < n; i++) {
    F[i] = 0;
  }
  F[0] = 1;
  F[1] = 1;

  return FactorialMemoUtil(n, F);
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
  
  cout << "Recur: " << FactorialRecur(n) << endl;
  cout << "Memo: " << FactorialMemo(n) << endl;
  // cout << "DP: " << factorial_dp(n) << endl;
  // cout << "Iter: " << factorial_iter(n) << endl;

  return 0;
}
