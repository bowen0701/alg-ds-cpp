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
  return stack.size();
}

void IntStack::show() const {
  std::cout << "[";
  for (int i = 0; i < stack.size(); i++) {
    std::cout << stack[i];
    if (i != stack.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  IntStack s;
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;

  // Output: [1, 2, 3].
  s.push(1);
  s.push(2);
  s.push(3);
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Peek: " << s.peek() << std::endl;

  // Output: [1].
  s.pop();
  s.pop();
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Peek: " << s.peek() << std::endl;

  // Output: [].
  s.pop();
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;

  return 0;
}
