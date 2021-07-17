#ifndef STACK_H_
#define STACK_H_

#include <vector>

class Stack {
 public:
  Stack();
  ~Stack();
  bool isEmpty() const;
  int peek() const;
  void push(int item);
  int pop();
  int size() const;
  void show() const;

 private:
  std::vector<int> stack;
};

#endif // STACK_H_
