// Linked list of integers.

#include <iostream>
#include "ds_linked_list.h"

IntLinkedList::IntLinkedList()
  : head(NULL) {}

IntLinkedList::~IntLinkedList() {
  while (!IsEmpty()) RemoveFront();
}

bool IntLinkedList::IsEmpty() const {
  return head == NULL;
}

const int& IntLinkedList::Front() const {
  return head->data;
}

void IntLinkedList::AddFront(const int& data) {
  IntNode* new_head = new IntNode;
  new_head->data = data;
  new_head->next = head;
  head = new_head;
}

void IntLinkedList::RemoveFront() {
  if (head != NULL) {
    IntNode* old_head = head;
    head = old_head->next;
    delete old_head;
  }
}

void IntLinkedList::Show() const {
  IntNode* current = new IntNode;
  current = head;
  while (current != NULL) {
    std::cout << current->data << " ";
    current = current->next;
  }
  delete current;
}

int main() {
  IntLinkedList ll;
  ll.AddFront(1);
  ll.AddFront(2);
  ll.AddFront(3);
  ll.AddFront(4);

  // Output: 1.
  std::cout << ll.Front() << std::endl;

  // // Output: 4 3 2 1
  ll.Show();
  std::cout << std::endl;

  // Output: 3 2 1
  ll.RemoveFront();
  ll.Show();
  std::cout << std::endl;

  // Output: false
  std::cout << std::boolalpha << ll.IsEmpty() << std::endl;

  // Output: true
  ll.RemoveFront();
  ll.RemoveFront();
  ll.RemoveFront();
  std::cout << std::boolalpha << ll.IsEmpty() << std::endl;

  return 0;
}
