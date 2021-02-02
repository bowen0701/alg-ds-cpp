#ifndef INT_STACK_H_
#define INT_STACK_H_

#include <vector>

class IntStack {
 public:
  IntStack();
  ~IntStack();
  bool isEmpty() const;
  int peek() const;
  void push(int item);
  int pop();
  int size() const;
  void show() const;

 private:
  std::vector<int> stack;
};

#endif // INT_STACK_H_
