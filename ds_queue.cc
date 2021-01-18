// Queue.

#include <iostream>
#include <vector>
#include "ds_queue.h"

// Queue using vector.
IntQueue::IntQueue() : items(std::vector<int>()) {}

IntQueue::~IntQueue() {}

bool IsEmpty() const {
  return items.empty();
}

int Peek() const  {
  return items[items.size() - 1];
}

void Enqueue(int item)  {
  items.insert(items.begin(), item);
}

int Dequeue()  {
  return items.pop_back();
}

int Size() const  {
  return items.size();
}

void Show() const  {
  std::cout << "[";
  for (int i = 0; i < items.size(); i++) {
    std::cout << items[i];
    if (i != items.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  return 0;
}
