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
  int Size();
  void Show() const;
  const int& Front() const;
  void AddFront(const int& data);
  void AddBack(const int& data);
  void RemoveNode(const int& data);
  void RemoveFront();
  void Insert(const int& pos, const int& data);
  int Pop(const int& pos);
  bool Search(const int& data);
  int Index(const int& data);
 private:
  IntNode* head;
};

#endif  // INT_LINKED_LIST_H_
