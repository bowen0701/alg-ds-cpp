#ifndef INT_LINKED_LIST_H_
#define INT_LINKED_LIST_H_

class IntNode {
 private:
  int data;
  IntNode* next;

  friend class IntLinkedList;
};

class IntLinkedList {
 public:
  IntLinkedList();
  ~IntLinkedList();
  bool IsEmpty() const;
  const int& front() const;
  void AddFront(const int& data);
  void RemoveFront();
 private:
  IntNode* head;
};

#endif  // INT_LINKED_LIST_H_
