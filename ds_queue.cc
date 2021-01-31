// Queue.

#include <iostream>
#include <vector>
#include "ds_queue.h"

// Queue using vector.
IntQueue::IntQueue() : queue(std::vector<int>()) {}

IntQueue::~IntQueue() {}

bool IntQueue::isEmpty() const {
  return queue.empty();
}

int IntQueue::peek() const  {
  if (!isEmpty()) {
    return queue[queue.size() - 1];
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

void IntQueue::enqueue(int item)  {
  queue.insert(queue.begin(), item);
}

int IntQueue::dequeue()  {
  if (!isEmpty()) {
    int back = queue.back();
    queue.pop_back();
    return back;
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

int IntQueue::size() const  {
  return queue.size();
}

void IntQueue::show() const  {
  std::cout << "[";
  for (int i = 0; i < queue.size(); i++) {
    std::cout << queue[i];
    if (i != queue.size() - 1) std::cout << ", ";
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
