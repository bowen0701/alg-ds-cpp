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

// Merge two sorted list by sorting all values.
// Time complexity: O((n1+n2)*log(n1+n2)), where ni is the length of listi.
// Space complexity: O((n1+n2)).
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
        if (l1->val < l2->val) {
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
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
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

        return dummy->next;
    }
};

void show(ListNode* ls) {
    while (ls) {
        cout << ls->val;
        if (ls->next) cout << "->";
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

    show(l1); cout << "; ";
    show(l2); cout << endl;

    ListNode* ls = SolutionSortAll().mergeTwoLists(l1, l2);
    show(ls); cout << endl;

    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ls = SolutionRecur().mergeTwoLists(l1, l2);
    show(ls); cout << endl;

    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ls = SolutionIter().mergeTwoLists(l1, l2);
    show(ls); cout << endl;

    return 0;
}
