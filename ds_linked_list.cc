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
  while (current) {
    counter++;
    current = current->next;
  }
  delete current;

  return counter;
}

void IntLinkedList::Show() const {
  IntNode* current = head;
  while (current) {
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

void IntLinkedList::RemoveNode(const int& data) {
  // Edge case: no head.
  if (!head) return;

  // Edge case: head contains data to be removed.
  if (head->data == data) RemoveFront();

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

void IntLinkedList::RemoveFront() {
  if (head) {
    IntNode* old_head = head;
    head = head->next;
    delete old_head;
  }
}

void IntLinkedList::Insert(const int& pos, const int& data) {
  // Edge case: empty head and insert position > 0.
  if (!head && pos > 0) {
    std::cout << "Cannot insert to empty linked list." << std::endl;
    return;
  }

  // Two pointer method: previous & current.
  IntNode* current = head;
  IntNode* previous = NULL;
  int counter = 0;

  if (!head) AddFront(data);

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

  // Output: 3 1 0
  ll.RemoveNode(2);
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  // Output: 4 3 1 0
  ll.Insert(0, 4);
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  // Output: 4 3 1 2 0
  ll.Insert(3, 2);
  ll.Show();
  std::cout << "size: " << ll.Size() << std::endl;

  ll.RemoveNode(4);
  ll.RemoveNode(2);

  // Output: true
  ll.RemoveFront();
  ll.RemoveFront();
  ll.RemoveFront();
  std::cout << "is empty: " << std::boolalpha << ll.IsEmpty() << std::endl;
  std::cout << "size: " << ll.Size() << std::endl;

  return 0;
}
