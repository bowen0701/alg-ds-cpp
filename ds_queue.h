#ifndef INT_QUEUE_H_
#define INT_QUEUE_H_

#include <vector>

class IntQueue {
 public:
  IntQueue();
  ~IntQueue();
  bool isEmpty() const;
  int peek() const;
  void enqueue(int item);
  int dequeue();
  int size() const;
  void show() const;
 private:
  std::vector<int> queue;
};

#endif // INT_QUEUE_H_
