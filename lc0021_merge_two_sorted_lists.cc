// Leetcode 21. Merge Two Sorted Lists
// Easy
//
// URL: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include <vector>
#include <algorithm>
#include <iostream>

// Definition for singly-linked list.
class ListNode {
 public:
  ListNode() : mVal{0}, next{nullptr} {}
  ListNode(int x) : mVal{x}, next{nullptr} {}
  ListNode(int x, ListNode* next) : mVal{x}, next{next} {}

  int mVal;
  ListNode* next;
};

// Merge two sorted list by sorting all values.
// Time complexity: O((n1+n2)*log(n1+n2)), where ni is the length of listi.
// Space complexity: O((n1+n2)).
class SolutionSortAll {
 public:
  static bool compare(const ListNode* l1, const ListNode* l2) {
      return (l1->mVal < l2->mVal);
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Edge cases: list1 or list2 is empty.
    if (!l1) return l2;
    if (!l2) return l1;

    // Append list1 and list2 nodes into a vector and sort them.
    std::vector<ListNode*> lists{l1, l2};
    std::vector<ListNode*> vec;
    for (auto ls : lists) {
      while (ls) {
        vec.push_back(ls);
        ls = ls->next;
      }
    }
    std::sort(vec.begin(), vec.end(), compare);

    // Append null pointer as final node of linked list.
    vec.push_back(nullptr);

    // Use a dummy node to create a new list based on the sorted nodes.
    ListNode dummy;
    ListNode* current = &dummy;
    for (auto ls : vec) {
      current->next = ls;
      current = current->next;
    }
    return dummy.next;
  }
};

// Merge two sorted list by recursion.
// Time complexity: O(n1+n2).
// Space complexity: O(n1+n2).
class SolutionRecur {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Edge cases: list1 or list2 is empty.
    if (!l1) return l2;
    if (!l2) return l1;

    // Recusively append next node to the smaller node.
    if (l1->mVal <= l2->mVal) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

// Merge two sorted list by iteration.
// Time complexity: O(n1+n2).
// Space complexity: O(1).
class SolutionIter {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // Edge cases: list1 or list2 is empty.
    if (!l1) return l2;
    if (!l2) return l1;

    // Iteratively append smaller node to the tail when both exist.
    // ListNode* dummy = new ListNode();
    ListNode dummy;
    ListNode* current = &dummy;
    while (l1 && l2) {
      if (l1->mVal <= l2->mVal) {
        current->next = l1;
        l1 = l1->next;
      } else {
        current->next = l2;
        l2 = l2->next;
      }
      current = current->next;
    }

    // Append the remaining node.
    if (!l1) {
      current->next = l2;
    } else {
      current->next = l1;
    }

    return dummy.next;
  }
};

void show(ListNode* ls) {
  while (ls) {
    std::cout << ls->mVal << " ";
    ls = ls->next;
  }
  std::cout << std::endl;
}

int main() {
  // Input: 1->2->4, 1->3->4
  // Output: 1->1->2->3->4->4
  ListNode* l1 = new ListNode{1};
  l1->next = new ListNode{2};
  l1->next->next = new ListNode{4};

  ListNode* l2 = new ListNode{1};
  l2->next = new ListNode{3};
  l2->next->next = new ListNode{4};

  std::cout << "l1: "; 
  show(l1);
  std::cout << "l2: "; 
  show(l2);

  ListNode* ls = SolutionSortAll().mergeTwoLists(l1, l2);
  show(ls); 

  l1 = new ListNode{1};
  l1->next = new ListNode{2};
  l1->next->next = new ListNode{4};

  l2 = new ListNode{1};
  l2->next = new ListNode{3};
  l2->next->next = new ListNode{4};

  ls = SolutionRecur().mergeTwoLists(l1, l2);
  show(ls);

  l1 = new ListNode{1};
  l1->next = new ListNode{2};
  l1->next->next = new ListNode{4};

  l2 = new ListNode{1};
  l2->next = new ListNode{3};
  l2->next->next = new ListNode{4};

  ls = SolutionIter().mergeTwoLists(l1, l2);
  show(ls); 

  return 0;
}
