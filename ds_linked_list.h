#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class Node {
 public:
  Node() : data(0), next(NULL) {}
  Node(int x) : data(x), next(NULL) {}
 private:
  int data;
  Node* next;

  friend class LinkedList;
};

class LinkedList {
 public:
  LinkedList();
  ~LinkedList();
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
  Node* head;
};

#endif  // LINKED_LIST_H_
