#include <iostream>
#include <vector>
#include <random>

void SelectionSort(std::vector<int>& nums) {
  // Selection sort algorithm.
  //
  // Procedure:
  // - Start reversely from pos=n-1,..1, 
  // - Select next max num to swap with num at pos.
  //
  // Time complexity: O(n^2).
  // Space complexity: O(1).
  int n = nums.size();
 
  for (int i = n - 1; i >= 1; i--) {
    int i_max = 0;
    for (int j = 1; j <= i; j++) {
      if (nums[i_max] < nums[j]) {
        i_max = j;
      }
    }
    int temp = nums[i];
    nums[i] = nums[i_max];
    nums[i_max] = temp;
  }
}

int main() {
  // Generate nums=1,...,9.
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

  // Apply selection sort.
  SelectionSort(nums);
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
