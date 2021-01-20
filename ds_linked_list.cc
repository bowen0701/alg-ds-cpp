// Linked list of integers.

#include <iostream>
#include "ds_linked_list.h"

IntLinkedList::IntLinkedList() : head(NULL) {}

IntLinkedList::~IntLinkedList() {
  while (!isEmpty()) removeFront();
}

// Check list is empty or not.
// Time complexity: O(1).
// Space complexity: O(1).
bool IntLinkedList::isEmpty() const {
  return head == NULL;
}

// Obtain list size.
// Time complexity: O(n).
// Space complexity: O(1).
int IntLinkedList::size() const {
  int counter = 0;

  IntNode* current = head;
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
void IntLinkedList::show() const {
  IntNode* current = head;
  while (current) {
    std::cout << current->data;
    if (current->next) std::cout << "->";
    current = current->next;
  }
  delete current;
}

// Prepend data to list head.
// Time complexity: O(1).
// Space complexity: O(1).
void IntLinkedList::addFront(const int& data) {
  IntNode* new_head = new IntNode(data);
  new_head->next = head;
  head = new_head;
}


// Append data to list tail.
// Time complexity: O(n).
// Space complexity: O(1).
void IntLinkedList::addBack(const int& data) {
  // Create new node.
  IntNode* new_node = new IntNode(data);

  // Edge case.
  if (!head) {
    head = new_node;
    return;
  }

  // Add new node to back.
  IntNode* current = head;
  while (current->next) {
    current = current->next;
  }
  current->next = new_node;
}

// Remove data from list, if existed.
// Time complexity: O(n).
// Space complexity: O(1).
void IntLinkedList::removeNode(const int& data) {
  // Edge case: no head.
  if (!head) return;

  // Edge case: head contains data to be removed.
  if (head->data == data) removeFront();

  // Iterate through list to find node.
  IntNode* current = head;
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
void IntLinkedList::removeFront() {
  if (head) {
    IntNode* old_head = head;
    head = head->next;
    delete old_head;
  }
}

// Insert data to specified position of list.
// Time complexity = O(pos).
// Space complexity: O(1).
void IntLinkedList::insert(int pos, const int& data) {
  // Edge case: empty head and insert position > 0.
  if (!head && pos > 0) {
    std::cout << "Cannot insert to empty linked list." << std::endl;
    return;
  }

  // Two pointer method: previous & current.
  IntNode* current = head;
  IntNode* previous = NULL;
  int counter = 0;

  if (!head) addFront(data);

  while (counter < pos && current->next) {
    previous = current;
    current = current->next;
    counter++;
  }

  IntNode* new_node = new IntNode(data);
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
int IntLinkedList::pop(int pos = -1) {
  // Edge case: no head.
  if (!head) return 0;

  // When no input for pos, set to tail position.
  if (pos == -1) pos = size() - 1;

  // Two pointer method: previous & current.
  IntNode* previous = NULL;
  IntNode* current = head;
  int counter = 0;
  while (counter < pos && current->next) {
    previous = current;
    current = current->next;
    counter++;
  }

  int pop_data = current->data;
  previous->next = NULL;
  delete current;
  return pop_data;
}

// Search data in list.
// Time complexity: O(n).
// Space complexity: O(1).
bool IntLinkedList::search(const int& data) {
  // Edge case: no head.
  if (!head) return false;

  // Iterate through list to find data.
  IntNode* current = head;
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
int IntLinkedList::index(const int& data) {
  // Edge case: no head.
  if (!head) return -1;

  // Iterate through list.
  IntNode* current = head;
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
  IntLinkedList ll;
  ll.addFront(1);
  ll.addFront(2);
  ll.addFront(3);
  ll.addFront(4);

  // Output: 4 3 2 1
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 2 1
  ll.removeFront();
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: false
  std::cout << "is empty: " << std::boolalpha << ll.isEmpty() << std::endl;

  // Output: 3 2 1 0
  ll.addBack(0);
  ll.show(); std::cout << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  // Output: 3 1 0
  ll.removeNode(2);
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
  ll.removeFront();
  ll.removeFront();
  ll.removeFront();
  std::cout << "is empty: " << std::boolalpha << ll.isEmpty() << std::endl;
  std::cout << "size: " << ll.size() << std::endl;

  return 0;
}
