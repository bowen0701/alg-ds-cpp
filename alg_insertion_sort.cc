#include <iostream>
#include <vector>
#include <random>

void InsertionSort(std::vector<int>& nums) {
  // Insertion sort.
  // Time complexity: O(n^2).
  // Space complexity: O(1).
  int n = nums.size();

  // Start from i=1,...,n-1, swap (nums[j-1], nums[j]),
  // for j=i,i-1,...,1, if their order is not correct.
  for (int i = 1; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      if (j > 0 && nums[j - 1] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;
      }
    }
  }
}

int main() {
  // Generate vector nums=0,...,9.
  int n = 10;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    nums[i] = i;
  }

  // Shuffle nums.
  unsigned seed = 71;
  std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  // Apply insertion sort.
  InsertionSort(nums);
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
