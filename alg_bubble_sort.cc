#include <iostream>
#include <vector>
#include <random>

void BubbleSort(std::vector<int>& nums) {
  // Bubble sort.
  // Time complexity: O(n^2).
  // Space complexity: O(1).
  int n = nums.size();

  // Start from i=n-1,n-2,...,1, swap (nums[j], nums[j+1]), for j=0,...,i-1
  // if the order is not correct.
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j ++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
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
  std::cout << "nums: " << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  // Apply bubble sort. 
  std::cout << "Bubble sort:" << std::endl;
  BubbleSort(nums);
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
