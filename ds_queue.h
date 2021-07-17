#ifndef QUEUE_H_
#define QUEUE_H_

#include <vector>

class Queue {
 public:
  Queue();
  ~Queue();
  bool isEmpty() const;
  int peek() const;
  void enqueue(int item);
  int dequeue();
  int size() const;
  void show() const;
 private:
  std::vector<int> queue;
};

#endif // QUEUE_H_
