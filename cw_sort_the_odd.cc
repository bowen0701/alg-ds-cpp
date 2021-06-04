// Codewars: Sort the odd
// 6 kyu
//
// URL: https://www.codewars.com/kata/578aa45ee9fd15ff4600090d/train/cpp
//
// Task
// You will be given an array of numbers. You have to sort the odd numbers in ascending order 
// while leaving the even numbers at their original positions.
//
// Examples
// [7, 1]  =>  [1, 7]
// [5, 8, 6, 3, 4]  =>  [3, 8, 6, 5, 4]
// [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]

#include <vector>
#include <cassert>

class Kata {
public:
  bool is_odd(int num) {
    return num % 2 == 1;
  }
  
  std::vector<int> sortArray(std::vector<int> array) {
    // Edge case.
    if (array.size() == 0) return array;
    
    // Iterate through items, bubble sort for odd numbers.
    for (int i = 0; (unsigned) i < array.size() - 1; i++) {
      if (!is_odd(array[i])) continue;

      for (int j = i + 1; (unsigned) j < array.size(); j++) {
        if (!is_odd(array[j])) continue;

        if(array[i] > array[j]) {
          auto temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
    }

    return array;
  }
};

int main() {
  Kata kata;

  std::vector<int> expected1{ };
  assert(kata.sortArray(std::vector<int>{ }) == expected1);

  std::vector<int> expected2{ 1, 3, 2, 8, 5, 4 };
  assert(kata.sortArray(std::vector<int>{ 5, 3, 2, 8, 1, 4 }) == expected2);

  std::vector<int> expected3{ 1, 3, 5, 8, 0 };
  assert(kata.sortArray(std::vector<int>{ 5, 3, 1, 8, 0 }) == expected3);

  return 0;
}
