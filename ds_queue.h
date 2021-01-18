#ifndef INT_QUEUE_H_
#define INT_QUEUE_H_

#include <vector>

class IntQueue {
 public:
  Queue();
  ~Queue();
  bool IsEmpty() const;
  int Peek() const;
  void Enqueue(int item);
  int Dequeue();
  int Size();
  void Show();
 private:
  vector<int> items;
};

#endif // INT_QUEUE_H_
