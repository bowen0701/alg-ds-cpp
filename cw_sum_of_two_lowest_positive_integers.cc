// Codewars: Sum of two lowest positive integers
// 7 kyu
//
// URL: https://www.codewars.com/kata/558fc85d8fd1938afb000014/train/cpp
//
// Create a function that returns the sum of the two lowest positive numbers given an array of 
// minimum 4 positive integers. No floats or non-positive integers will be passed.
//
// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
//
// [10, 343445353, 3453445, 3453545353453] should return 3453455.

#include <vector>
#include <queue>
#include <cassert>

long sumTwoSmallestNumbers(std::vector<long> numbers) {
  // Create a max priority queue with the first 2 numbers.
  std::priority_queue<long> pq;
  pq.push(numbers[0]);
  pq.push(numbers[1]);

  // Iterate through the remaining numbers, push into the queue if smaller.
  for (int i = 2; i < numbers.size(); i++) {
    if (numbers[i] < pq.top()) {
      pq.push(numbers[i]);
      pq.pop();
    }
  }

  long sum = 0;
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }

  return sum;
}

int main() {
  assert(sumTwoSmallestNumbers(std::vector<long>{ 19, 5, 42, 2, 77 }) == 7); 
  assert(sumTwoSmallestNumbers(std::vector<long>{ 10, 343445353, 3453445, 3453545353453 }) == 3453455); 

  return 0;
}
