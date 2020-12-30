// Linked list of integers.

#include <iostream>
#include "ds_linked_list.h"

IntLinkedList::IntLinkedList() : head(NULL) {}

IntLinkedList::~IntLinkedList() {
  while (!IsEmpty()) RemoveFront();
}

bool IntLinkedList::IsEmpty() const {
  return head == NULL;
}

int IntLinkedList::Size() const {
  int counter = 0;

  IntNode* current = head;
  while (current != NULL) {
    counter++;
    current = current->next;
  }
  delete current;

  return counter;
}

void IntLinkedList::Show() const {
  IntNode* current = head;
  while (current != NULL) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
  delete current;
}

const int& IntLinkedList::Front() const {
  return head->data;
}

void IntLinkedList::AddFront(const int& data) {
  IntNode* new_head = new IntNode(data);
  new_head->next = head;
  head = new_head;
}

void IntLinkedList::AddBack(const int& data) {
  // Create new node.
  IntNode* new_node = new IntNode(data);

  // Edge case.
  if (head == NULL) {
    head = new_node;
    return;
  }

  // Add new node to back.
  IntNode* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void IntLinkedList::RemoveNode(const int& data) {
  // TODO
}

void IntLinkedList::RemoveFront() {
  if (head != NULL) {
    IntNode* old_head = head;
    head = head->next;
    delete old_head;
  }
}

void IntLinkedList::Insert(const int& pos, const int& data) {
  // TODO
}

int IntLinkedList::Pop(const int& pos) {
  // TODO
  return 0;
}

bool IntLinkedList::Search(const int& data) {
  // TODO
  return true;
}

int IntLinkedList::Index(const int& data) {
  // TODO
  return 0;
}

int main() {
  IntLinkedList ll;
  ll.AddFront(1);
  ll.AddFront(2);
  ll.AddFront(3);
  ll.AddFront(4);

  // Output: 1.
  std::cout << "front: " << ll.Front() << std::endl;

  // // Output: 4 3 2 1
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  // Output: 3 2 1
  ll.RemoveFront();
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  // Output: false
  std::cout << "is empty: " << std::boolalpha << ll.IsEmpty() << std::endl;

  // Output: 3 2 1 0
  ll.AddBack(0);
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  // Output: true
  ll.RemoveFront();
  ll.RemoveFront();
  ll.RemoveFront();
  ll.RemoveFront();
  std::cout << "is empty: " << std::boolalpha << ll.IsEmpty() << std::endl;
  std::cout << "size: " << ll.Size() << std::endl;

  return 0;
}
