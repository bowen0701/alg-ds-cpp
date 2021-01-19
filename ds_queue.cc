// Queue.

#include <iostream>
#include <vector>
#include "ds_queue.h"

// Queue using vector.
IntQueue::IntQueue() : items(std::vector<int>()) {}

IntQueue::~IntQueue() {}

bool IntQueue::isEmpty() const {
  return items.empty();
}

int IntQueue::peek() const  {
  if (!isEmpty()) {
    return items[items.size() - 1];
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

void IntQueue::enqueue(int item)  {
  items.insert(items.begin(), item);
}

int IntQueue::dequeue()  {
  if (!isEmpty()) {
    int back = items.back();
    items.pop_back();
    return back;
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

int IntQueue::size() const  {
  return items.size();
}

void IntQueue::show() const  {
  std::cout << "[";
  for (int i = 0; i < items.size(); i++) {
    std::cout << items[i];
    if (i != items.size() - 1) std::cout << ", ";
  }
  std::cout << "]";
}

int main() {
  IntQueue q;
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;

  // Output: [3, 2, 1].
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;
  std::cout << "Peek: " << q.peek() << std::endl;

  // Output: [3].
  q.dequeue();
  q.dequeue();
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;
  std::cout << "Peek: " << q.peek() << std::endl;

  // Output: [].
  q.dequeue();
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;

  return 0;
}
