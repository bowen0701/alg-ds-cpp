// Find last Fibonacci digit [hardcore version]
// 6 kyu

// URL: https://www.codewars.com/kata/56b7771481290cc283000f28/train/cpp

// Just like in the "father" kata, you will have to return the last digit of the nth element in the Fibonacci sequence (starting with 1,1, to be extra clear, not with 0,1 or other numbers).

// You will just get much bigger numbers, so good luck bruteforcing your way through it ;)

// lastFibDigit(1) == 1
// lastFibDigit(2) == 1
// lastFibDigit(3) == 2
// lastFibDigit(1000) == 5
// lastFibDigit(1000000) == 5

#include <cstdint>
#include <string>

std::uint32_t lastFibDigit(const std::uint32_t n) {
  if (n == 1 || n == 2) return 1;
  
  std::uint32_t a = 1, b = 1;
  for (std::uint32_t i = 3; i <= n; i++) {
    std::uint32_t tmp = b;
    b = (a + b) % 10;
    a = tmp;
  }
  return b;
}

int main() {
  assert(lastFibDigit(1) == 1);
  assert(lastFibDigit(2) == 1);
  assert(lastFibDigit(3) == 2);
  assert(lastFibDigit(1000) == 5);
  assert(lastFibDigit(1000000) == 5);

  return 0;
}