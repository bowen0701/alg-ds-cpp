// Leetcode 23. Merge k Sorted Lists
// Hard
//
// URL: https://leetcode.com/problems/merge-k-sorted-lists/
//
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it
// 
// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// 
// Example 2:
// Input: lists = []
// Output: []
//
// Example 3: 
// Input: lists = [[]]
// Output: []
// 
// Constraints:
// * k == lists.length
// * 0 <= k <= 10^4
// * 0 <= lists[i].length <= 500
// * -10^4 <= lists[i][j] <= 10^4
// * lists[i] is sorted in ascending order.
// * The sum of lists[i].length won't exceed 10^4.

#include <iostream>
#include <vector>
#include <algorithm>

// Definition for singly-linked list.
class ListNode {
 public:
  ListNode() : mVal{0}, next{nullptr} {}
  ListNode(int x) : mVal{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : mVal{x}, next{next} {}

  int mVal;
  ListNode* next;
};

// Merge K sorted list by sorting all values.
// Time complexity: O((n1+...+nk)*log(n1+...+nk)), where ni is the length of listi.
// Space complexity: O((n1+..+nk)).
class SolutionSortAll {
public:
  static bool compare(const ListNode* l1, const ListNode* l2) {
      return (l1->mVal < l2->mVal);
  }

  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Edge case.
    if (lists.empty()) return nullptr;

    // Append lists's all nodes to vec and sort them.
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

// Merge K sorted list by merging two into the first one.
// pass

// Merge K sorted list by merging 2 sorted lists pair by pair.
// Time complexity: O(nk*logk)
//   - n is the max number of nodes in one list.
//   - k is the length of lists.
// Space complexity: O(n*logk)
class SolutionMergeTwoRecur {
 public:
  ListNode* merge2ListsRecur(ListNode* l1, ListNode* l2) {
    // Merge two sorted lists recursively.
    // Edge case: l1 or l2 does not exist.
    if (!l1) return l2;
    if (!l2) return l1;

    // Recusively append next node to the smaller node.
    if (l1->mVal < l2->mVal) {
      l1->next = merge2ListsRecur(l1->next, l2);
      return l1;
    } else {
      l2->next = merge2ListsRecur(l1, l2->next);
      return l2;
    }
  }

  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Edge case.
    if (lists.empty()) return nullptr;

    // For each pair of leftmost and rightmost, merge them to the former.
    int n = lists.size();
    while (n > 1) {
      for (int i = 0; i < (int)n / 2; i++) {
        lists[i] = merge2ListsRecur(lists[i], lists[n - 1 - i]);
      }

      // Cut n to n/2.
      n = (int)(n + 1) / 2;
    }

    return lists[0];
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
  // By SolutionSortAll():
  // Example 1:
  // Input: lists = [[1,4,5],[1,3,4],[2,6]]
  // Output: [1,1,2,3,4,4,5,6]
  ListNode* l1 = new ListNode{1};
  l1->next = new ListNode{4};
  l1->next->next = new ListNode{5};

  ListNode* l2 = new ListNode{1};
  l2->next = new ListNode{3};
  l2->next->next = new ListNode{4};

  ListNode* l3 = new ListNode{2};
  l3->next = new ListNode{6};

  std::vector<ListNode*> lists{l1, l2, l3};

  ListNode* ls = SolutionSortAll().mergeKLists(lists);
  show(ls);

  // Example 2:
  // Input: lists = []
  // Output: []
  lists = {};

  ls = SolutionSortAll().mergeKLists(lists);
  show(ls);

  // Example 3:   
  // Input: lists = [[]]
  // Output: []
  l1 = nullptr;
  lists = {l1};

  ls = SolutionSortAll().mergeKLists(lists);
  show(ls);

  // By SolutionMergeTwoRecur():
  // Example 1:
  // Input: lists = [[1,4,5],[1,3,4],[2,6]]
  // Output: [1,1,2,3,4,4,5,6]
  l1 = new ListNode{1};
  l1->next = new ListNode{4};
  l1->next->next = new ListNode{5};

  l2 = new ListNode{1};
  l2->next = new ListNode{3};
  l2->next->next = new ListNode{4};

  l3 = new ListNode{2};
  l3->next = new ListNode{6};

  lists = {l1, l2, l3};

  ls = SolutionMergeTwoRecur().mergeKLists(lists);
  show(ls);

  // Example 2:
  // Input: lists = []
  // Output: []
  lists = {};

  ls = SolutionMergeTwoRecur().mergeKLists(lists);
  show(ls);

  // Example 3:   
  // Input: lists = [[]]
  // Output: []
  l1 = nullptr;
  lists = {l1};

  ls = SolutionMergeTwoRecur().mergeKLists(lists);
  show(ls);

  return 0;
}
