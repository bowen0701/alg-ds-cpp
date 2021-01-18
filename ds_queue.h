#ifndef INT_QUEUE_H_
#define INT_QUEUE_H_

#include <vector>

class IntQueue {
 public:
  IntQueue();
  ~IntQueue();
  bool IsEmpty() const;
  int Peek() const;
  void Enqueue(int item);
  int Dequeue();
  int Size() const;
  void Show() const;
 private:
  std::vector<int> items;
};

#endif // INT_QUEUE_H_
