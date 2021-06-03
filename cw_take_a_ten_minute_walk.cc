// Codewars: Take a Ten Minute Walk
// 6 kyu
//
// URL: https://www.codewars.com/kata/54da539698b8a2ad76000228/train/cpp
// 
// You live in the city of Cartesia where all roads are laid out in a perfect grid. 
// You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. 
// The city provides its citizens with a Walk Generating App on their phones -- 
// everytime you press the button it sends you an array of one-letter strings representing directions to walk 
// (eg. ['n', 's', 'w', 'e']). You always walk only a single block for each letter (direction) and 
// you know it takes you one minute to traverse one city block, so create a function that will return true if the walk the 
// app gives you will take you exactly ten minutes (you don't want to be early or late!) and will, of course, 
// return you to your starting point. Return false otherwise.
//
// Note: you will always receive a valid array containing a random assortment of direction letters ('n', 's', 'e', or 'w' only). 
// It will never give you an empty array (that's not a walk, that's standing still!).

#include <vector>
#include <cassert>

bool isValidWalk(std::vector<char> walk) {
  // Check if 10 characters.
  if (walk.size() != 10) return false;

  // Check if return to starting point.
  int ns_sum = 0;
  int we_sum = 0;

  for (auto d : walk) {
    if (d == 'n') {
      ns_sum++;
    } else if (d == 's') {
      ns_sum--;
    } else if (d == 'w') {
      we_sum++;
    } else if (d == 'e') {
      we_sum--;
    }
  }

  if (ns_sum == 0 && we_sum == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  assert (isValidWalk(std::vector<char>{'n'}) == false);
  assert (isValidWalk(std::vector<char>{'n','s','n','s','n','s','n','s','n','s'}) == true);
  assert (isValidWalk(std::vector<char>{'n','s'}) == false);
  assert (isValidWalk(std::vector<char>{'n','s','n','s','n','s','n','s','n','s','n','s'}) == false);
  assert (isValidWalk(std::vector<char>{'e','w','e','w','n','s','n','s','e','w'}) == true);
  assert (isValidWalk(std::vector<char>{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}) == false);
  assert (isValidWalk(std::vector<char>{'n','s','e','w','n','s','e','w','n','s'}) == true);
  assert (isValidWalk(std::vector<char>{'s','e','w','n','n','s','e','w','n','s'}) == true);
  assert (isValidWalk(std::vector<char>{'n','s','n','s','n','s','n','s','n','n'}) == false);
  assert (isValidWalk(std::vector<char>{'e','e','e','w','n','s','n','s','e','w'}) == false);
  
  return 0;
}
