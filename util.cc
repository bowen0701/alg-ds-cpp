#include "util.h"

void Print2DVector(std::vector<std::vector<int>>& vec) {
  for (auto v : vec) {
    std::cout << "(";
    for (int i = 0; i < v.size(); i++) {
      if (i != v.size() - 1) std::cout << v[i] << ", ";
      else std::cout << v[i];
    }
    std::cout << ")" << std::endl;
  }
}
