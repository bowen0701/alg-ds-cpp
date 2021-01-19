// Queue.

#include <iostream>
#include <vector>
#include "ds_queue.h"

// Queue using vector.
IntQueue::IntQueue() : items(std::vector<int>()) {}

IntQueue::~IntQueue() {}

bool IntQueue::IsEmpty() const {
  return items.empty();
}

int IntQueue::Peek() const  {
  if (!IsEmpty()) {
    return items[items.size() - 1];
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

void IntQueue::Enqueue(int item)  {
  items.insert(items.begin(), item);
}

int IntQueue::Dequeue()  {
  if (!IsEmpty()) {
    int back = items.back();
    items.pop_back();
    return back;
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

int IntQueue::Size() const  {
  return items.size();
}

void IntQueue::Show() const  {
  std::cout << "[";
  for (int i = 0; i < items.size(); i++) {
    std::cout << items[i];
    if (i != items.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  IntQueue q;
  std::cout << "Is empty: " << std::boolalpha << q.IsEmpty() << std::endl;

  // Output: [3, 2, 1].
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);
  std::cout << "Is empty: " << std::boolalpha << q.IsEmpty() << std::endl;
  std::cout << "Show: "; q.Show(); std::cout << std::endl;
  std::cout << "Size: " << q.Size() << std::endl;
  std::cout << "Peek: " << q.Peek() << std::endl;

  // Output: [3].
  q.Dequeue();
  q.Dequeue();
  std::cout << "Is empty: " << std::boolalpha << q.IsEmpty() << std::endl;
  std::cout << "Show: "; q.Show(); std::cout << std::endl;
  std::cout << "Size: " << q.Size() << std::endl;
  std::cout << "Peek: " << q.Peek() << std::endl;

  // Output: [].
  q.Dequeue();
  std::cout << "Is empty: " << std::boolalpha << q.IsEmpty() << std::endl;
  std::cout << "Show: "; q.Show(); std::cout << std::endl;
  std::cout << "Size: " << q.Size() << std::endl;

  return 0;
}
