// Linked list of integers.

#include <iostream>
#include "ds_linked_list.h"

LinkedList::~LinkedList() {
  // Prevent stack overflow due to the recursive nodes destruction.
  while (head) { head = std::move(head->next); }
}

// Check list is empty or not.
// Time complexity: O(1).
// Space complexity: O(1).
bool LinkedList::isEmpty() const { 
  return head == nullptr; 
}

// Obtain list size.
// Time complexity: O(n).
// Space complexity: O(1).
int LinkedList::size() const {
  Node* current = head;

  int counter = 0;
  while (current) {
    counter++;
    current = current->next;
  }
  delete current;

  return counter;
}

// Show the list.
// Time complexity: O(n).
// Space complexity: O(1).
void LinkedList::show() const {
  Node* current = head;

  while (current) {
    std::cout << current->data << " ";
    current = current->next;
  }
  delete current;
}

// Push data to list head.
// Time complexity: O(1).
// Space complexity: O(1).
void LinkedList::pushFront(const int& data) {
  auto temp{std::make_unique<Node>(data)};
  if (head) { temp->next = std::move(head); }
  head = std::move(temp);
}


// Append data to list tail.
// Time complexity: O(n).
// Space complexity: O(1).
void LinkedList::pushBack(const int& data) {
  // Create new node.
  Node* new_node = new Node(data);

  // Edge case.
  if (!head) {
    head = new_node;
    return;
  }

  // Add new node to back.
  Node* current = head;
  while (current->next) {
    current = current->next;
  }
  current->next = new_node;
}

// Remove data from list, if existed.
// Time complexity: O(n).
// Space complexity: O(1).
void LinkedList::popNode(const int& data) {
  // Edge case: no head.
  if (head == nullptr) { return; }

  // Edge case: head contains data to be removed.
  if (head->data == data) { pushFront(data); }

  // Iterate through list to find node.
  Node* current = head;
  while (current->next) {
    if (current->next->data == data) {
      current->next = current->next->next;
      return;
    } else {
      current = current->next;
    }
  }
}

// Remove front node.
// Time complexity: O(1).
// Space complexity: O(1).
void LinkedList::popFront() {
  if (head) {
    Node* old_head = head;
    head = head->next;
    delete old_head;
  }
}

// Insert data to specified position of list.
// Time complexity = O(pos).
// Space complexity: O(1).
void LinkedList::insert(int pos, const int& data) {
  // Edge case: empty head and insert position > 0.
  if (!head && pos > 0) {
    std::cout << "Cannot insert to empty linked list." << std::endl;
    return;
  }

  // Two pointer method: previous & current.
  Node* current = head;
  Node* previous = nullptr;
  int counter = 0;

  if (!head) pushFront(data);

  while (counter < pos && current->next) {
    previous = current;
    current = current->next;
    counter++;
  }

  Node* new_node = new Node(data);
  new_node->next = current;

  if (pos == 0) {
    head = new_node;
  } else {
    previous->next = new_node;
  }
}

// Pop list node at specified position.
// Time complexity: O(pos).
// Space complexity: O(1).
int LinkedList::pop(int pos = -1) {
  // Edge case: no head.
  if (!head) return 0;

  // When no input for pos, set to tail position.
  if (pos == -1) pos = size() - 1;

  // Two pointer method: previous & current.
  Node* previous = nullptr;
  Node* current = head;
  int counter = 0;
  while (counter < pos && current->next) {
    previous = current;
    current = current->next;
    counter++;
  }

  int pop_data = current->data;
  previous->next = nullptr;
  delete current;
  return pop_data;
}

// Search data in list.
// Time complexity: O(n).
// Space complexity: O(1).
bool LinkedList::search(const int& data) {
  // Edge case: no head.
  if (!head) return false;

  // Iterate through list to find data.
  Node* current = head;
  while (current) {
    if (current->data == data) {
      return true;
    } else {
      current = current->next;
    }
  }
  return false;
}

// Obtain node's index in list.
// Time complexity: O(n).
// Space complexity: O(1).
int LinkedList::index(const int& data) {
  // Edge case: no head.
  if (!head) return -1;

  // Iterate through list.
  Node* current = head;
  int counter = 0;

  while (current->next) {
    if (current->data == data) {
      return counter;
    }
    else {
      current = current->next;
      counter++;
    }
  }

  if (current->data == data) return counter;
  else return -1;
}

int main() {
  LinkedList ll{};

  ll.pushFront(1);
  ll.pushFront(2);
  ll.pushFront(3);
  ll.pushFront(4);

  // Output: 4 3 2 1
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 2 1
  ll.popFront();
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: false
  std::cout << "is empty: " << std::boolalpha << ll.isEmpty() << std::endl;

  // Output: 3 2 1 0
  ll.pushBack(0);
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 1 0
  ll.popNode(2);
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 1 2 0
  ll.insert(3, 2);
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 1 2
  std::cout << "pop: " << ll.pop() << std::endl;
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: true false
  std::cout << std::boolalpha << ll.search(2) << std::endl;
  std::cout << std::boolalpha << ll.search(0) << std::endl;

  // Output: -1 1
  std::cout << ll.index(4) << std::endl;
  std::cout << ll.index(1) << std::endl;

  // Output: true
  ll.popFront();
  ll.popFront();
  ll.popFront();
  std::cout << "is empty: " << std::boolalpha << ll.isEmpty() << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  return 0;
}
