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

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class SolutionSortAll {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Edge cases: list1 or list2 is empty.
        if (!l1) return l2;
        if (!l2) return l1;

        // Append list1 and list2's values into a vector and sort them.
        vector<ListNode*> lists{l1, l2};
        vector<int> vals;
        for (auto ls : lists) {
            while (ls) {
                vals.push_back(ls->val);
                ls = ls->next;
            }
        }
        sort(vals.begin(), vals.end());

        // Create a new list based on the sorted vector.
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        for (auto val : vals) {
            current->next = new ListNode(val);
            current = current->next;
        }
        return dummy->next;
    }
};

// class SolutionRecur {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         // TODO
//     }
// };

// class SolutionIter {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         // TODO
//     }
// };

// TODO: revise show().
void show(ListNode* ls) {
    while (ls) {
        cout << ls->val << "->";
        ls = ls->next;
    }
}

int main() {
    // Input: 1->2->4, 1->3->4
    // Output: 1->1->2->3->4->4
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* ls = SolutionSortAll().mergeTwoLists(l1, l2);
    show(ls);
    cout << endl;

    return 0;
}
