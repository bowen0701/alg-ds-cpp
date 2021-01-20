#ifndef INT_LINKED_LIST_H_
#define INT_LINKED_LIST_H_

class IntNode {
 public:
  IntNode() : data(0), next(NULL) {}
  IntNode(int x) : data(x), next(NULL) {}
 private:
  int data;
  IntNode* next;

  friend class IntLinkedList;
};

class IntLinkedList {
 public:
  IntLinkedList();
  ~IntLinkedList();
  bool isEmpty() const;
  int size() const;
  void show() const;
  void addFront(const int& data);
  void addBack(const int& data);
  void removeNode(const int& data);
  void removeFront();
  void insert(int pos, const int& data);
  int pop(int pos);
  bool search(const int& data);
  int index(const int& data);
 private:
  IntNode* head;
};

#endif  // INT_LINKED_LIST_H_
