#include <iostream>
using namespace std;

long factorial_recur(int n) {
  // Factorial by recursion.
  if (n <= 1)
    return 1;
  else
    return n * factorial_recur(n - 1);
}

long factorial_memo(int n) {
  // Factorial by bottom-up dynamic programming.
  long A[n + 1];
  A[0] = 1;
  A[1] = 1;

  // TODO: Implement factorial_memo().
  return 0
}

long factorial_dp(int n) {
  // Factorial by bottom-up dynamic programming w/
  // optimized space.

  // TODO: Implement factorial_dp().
  return 0;
}

int main() {
  int n = 10;
  cout << "By recursion: " << factorial_recur(n) << endl;
  return 0;
}