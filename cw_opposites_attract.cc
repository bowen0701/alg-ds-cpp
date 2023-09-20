// Codewards: Opposites Attract
// 8 kyu
//
// URL: https://www.codewars.com/kata/555086d53eac039a2a000083/train/cpp
//
// Timmy & Sarah think they are in love, but around where they live, they will only know once they pick a flower each. 
// If one of the flowers has an even number of petals and the other has an odd number of petals it means 
// they are in love.
//
// Write a function that will take the number of petals of each flower and return true if they are in love and false 
// if they aren't.

#include <string>

bool lovefunc(int f1, int f2) {
  return (f1 % 2) != (f2 % 2) ? true : false;
}

int main() {
	assert(lovefunc(1, 2) == true);
	assert(lovefunc(0, 3) == true);
	assert(lovefunc(99, 198) == true);
	assert(lovefunc(0, 0) == false);
	assert(lovefunc(2, 2) == false);
	assert(lovefunc(101, 101) == false);

	return 0;
}
