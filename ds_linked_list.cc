// Linked list of integers.

#include "ds_linked_list.h"

IntLinkedList::IntLinkedList() {
  : head(NULL) {}
}

IntLinkedList::~IntLinkedList() {
  while (!IsEmpty()) RemoveFront();
}

IntLinkedList::IsEmpty() const
const int& IntLinkedList::front() const
void IntLinkedList::AddFront(const int& data)
void IntLinkedList::RemoveFront()

int main() {
  return 0;
}
