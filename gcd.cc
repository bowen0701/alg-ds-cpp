#include <iostream>
using namespace std;

int gcd(int m, int n){
  // Greatest Common Divisor (GCD) by Euclid's Algorithm.
  // Time complexity: O(m%n).
  int r;

  while (n != 0) {
    r = m % n;
    m = n;
    n = r;
  }

  return m;
}

int main(){
  int m = 10;
  int n = 4;
  cout << "gcd: " << gcd(m, n) << endl;
  return 0;
}
