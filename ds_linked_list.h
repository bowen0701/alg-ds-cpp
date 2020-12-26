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
  const int& Front() const;
  void AddFront(const int& data);
  void RemoveFront();
  void Show() const;
 private:
  IntNode* head;
};

#endif  // INT_LINKED_LIST_H_
