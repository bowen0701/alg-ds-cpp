// Queue of integers.

#include <iostream>
#include <vector>
#include "ds_queue.h"

// Queue using vector.
Queue::Queue() : queue(std::vector<int>()) {}

Queue::~Queue() {}

bool Queue::isEmpty() const {
  return queue.empty();
}

int Queue::peek() const {
  if (!isEmpty()) {
    return queue.back();
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

void Queue::enqueue(int item) {
  queue.insert(queue.begin(), item);
}

int Queue::dequeue() {
  if (!isEmpty()) {
    int back = queue.back();
    queue.pop_back();
    return back;
  } else {
    throw std::out_of_range("The queue is empty!");
  }
}

int Queue::size() const {
  return queue.size();
}

void Queue::show() const {
  for (int i = 0; i < queue.size(); i++) {
    std::cout << queue[i] << " ";
  }
}

int main() {
  Queue q;

  // Output: true.
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  // Output: false; 3 2 1; 3; 1
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;
  std::cout << "Peek: " << q.peek() << std::endl;

  q.dequeue();
  q.dequeue();

  // Output: false; 3; 1; 3.
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;
  std::cout << "Peek: " << q.peek() << std::endl;

  q.dequeue();

  // Output: true; ; 0.
  std::cout << "Is empty: " << std::boolalpha << q.isEmpty() << std::endl;
  std::cout << "Show: "; q.show(); std::cout << std::endl;
  std::cout << "Size: " << q.size() << std::endl;

  return 0;
}
