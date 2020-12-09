#include <iostream>

// Tower of Hanoi.
// height = 1: 0 + 1 + 0 = 1 step,
// height = 2: 1 + 1 + 1 = 3 steps,
// height = 3: 3 + 1 + 3 = 7 steps,
// height = 4: 7 + 1 + 7 = 15 steps,
// and so on.
// TowerOfHanoi(n) = 2^n - 1.
// Time complexity: T(1) = 1, T(n) = 2T(n - 1) + 1 => O(2^n).
// Space complexity: O(1).
void TowerOfHanoi(int height, 
                  std::string from_pole, 
                  std::string to_pole, 
                  std::string with_pole, 
                  int& counter) {
  if (height == 1) {
    std::cout << from_pole << "->" << to_pole << std::endl;
    counter++;
    return;
  }

  // Move (n - 1) disks to with_pole, the (largest) nth to to_pole,
  // finally (n - 1) disks to to_pole.
  TowerOfHanoi(height - 1, from_pole, with_pole, to_pole, counter);
  TowerOfHanoi(1, from_pole, to_pole, with_pole, counter);
  TowerOfHanoi(height - 1, with_pole, to_pole, from_pole, counter);  
}

int main() {
  std::string from_pole = "A"; 
  std::string to_pole = "B";
  std::string with_pole = "C";

  // Output: 1.
  int height1 = 1;
  int counter1 = 0;
  std::cout << "height: " << height1 << std::endl;
  TowerOfHanoi(height1, from_pole, to_pole, with_pole, counter1);
  std::cout << "Counter: " << counter1 << std::endl;

  // Output: 3.
  int height2 = 2;
  int counter2 = 0;
  std::cout << "height: " << height2 << std::endl;
  TowerOfHanoi(height2, from_pole, to_pole, with_pole, counter2);
  std::cout << "Counter: " << counter2 << std::endl;

  // Output: 31.
  int height3 = 5;
  int counter3 = 0;
  std::cout << "height: " << height3 << std::endl;
  TowerOfHanoi(height3, from_pole, to_pole, with_pole, counter3);
  std::cout << "Counter: " << counter3 << std::endl;

  return 0;
}
