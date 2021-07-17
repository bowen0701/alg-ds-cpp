// Stack of integers.

#include <iostream>
#include <vector>

#include "ds_stack.h"

Stack::Stack() {
  stack = std::vector<int>();
}

Stack::~Stack() {}

bool Stack::isEmpty() const {
  return stack == std::vector<int>();
}

int Stack::peek() const {
  if (!isEmpty()) {
    return stack.back();
  } else {
    throw std::out_of_range("The stack is empty");
  }
}

void Stack::push(int item) {
  stack.push_back(item);
}

int Stack::pop() {
  if (!isEmpty()) {
    auto back = stack.back();
    stack.pop_back();
    return back;
  } else {
    throw std::out_of_range("The stack is empty");
  }
}

int Stack::size() const {
  return stack.size();
}

void Stack::show() const {
  std::cout << "[";
  for (int i = 0; i < stack.size(); i++) {
    std::cout << stack[i];
    if (i != stack.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  Stack s;

  // Output: true.
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;

  s.push(1);
  s.push(2);
  s.push(3);

  // Output: false; [1, 2, 3]; 3; 3.
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Peek: " << s.peek() << std::endl;

  s.pop();
  s.pop();

  // Output: fals; [1]; 1; 1.
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;
  std::cout << "Peek: " << s.peek() << std::endl;

  s.pop();
  // Output: true; []; 0.
  std::cout << "Is empty: " << std::boolalpha << s.isEmpty() << std::endl;
  std::cout << "Show: "; s.show(); std::cout << std::endl;
  std::cout << "Size: " << s.size() << std::endl;

  return 0;
}
