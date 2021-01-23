#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <vector>

template<typename T>
void printVector(std::vector<T>& vec) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    if (i != vec.size() - 1) std::cout << vec[i] << ", ";
    else std::cout << vec[i];
  }
  std::cout << "]" << std::endl;
}

template<typename T>
void print2DVector(std::vector<std::vector<T>>& vec) {
  for (auto v : vec) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
      if (i != v.size() - 1) std::cout << v[i] << ", ";
      else std::cout << v[i];
    }
    std::cout << "]" << std::endl;
  }
}

#endif UTIL_H_
