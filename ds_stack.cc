// Stack.

#include <iostream>
#include <vector>

#include "ds_stack.h"

IntStack::IntStack() {
  stack = std::vector<int>();
}

IntStack::~IntStack() {}

bool IntStack::isEmpty() const {
  return stack == std::vector<int>();
}

int IntStack::peek() const {
  if (!isEmpty()) {
    return stack[stack.size() - 1];
  } else {
    throw std::out_of_range("The stack is empty");
  }
}

void IntStack::push(int item) {
  stack.push_back(item);
}

int IntStack::pop() {
  if (!isEmpty()) {
    auto back = stack.back();
    stack.pop_back();
    return back;
  } else {
    throw std::out_of_range("The stack is empty");
  }
}

int IntStack::size() const {
  return queue.size();
}

void IntStack::show() const {
  std::cout << "[";
  for (int i = 1; i < queue.size; i++) {
    std::cout << queue[i];
    if (i != queue.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  return 0;
}
