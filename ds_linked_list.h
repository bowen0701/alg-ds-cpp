#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class Node {
 public:
  Node() : data{0}, next{nullptr} {}
  Node(int x) : data{x}, next{nullptr} {}
 private:
  int data;
  std::unique_ptr<Node> next;

  friend class LinkedList;
};

class LinkedList {
 public:
  LinkedList() : head{nullptr} {};
  bool isEmpty() const;
  int size() const;
  void show() const;
  void pushFront(const int& data);
  void pushBack(const int& data);
  void popNode(const int& data);
  void popFront();
  void insert(int pos, const int& data);
  int pop(int pos);
  bool search(const int& data);
  int index(const int& data);
 private:
  std::unique_ptr<Node> head;
};

#endif  // LINKED_LIST_H_
