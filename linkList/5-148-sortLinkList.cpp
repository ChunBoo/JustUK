/*
Problem
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5


Solution: Merge Sort
Top-down (recursion)

Time complexity: O(nlogn)

Space complexity: O(logn)


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* slow=head, *fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=nullptr;
        return merge(sortList(head),sortList(mid));
    }
private:
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l1&&l2)
        {
            if(l1->val>l2->val)
                swap(l1,l2);
            tail->next=l1;
            l1=l1->next;
            tail=tail->next;
        }
        if(l1) tail->next=l1;
        if(l2) tail->next=l2;
        return dummy.next;
    }
};

//bottom up
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    // 0 or 1 element, we are done.
    if (!head || !head->next) return head;
    
    int len = 1;
    ListNode* cur = head;
    while (cur = cur->next) ++len;
    
    ListNode dummy(0);
    dummy.next = head;
    ListNode* l;
    ListNode* r;
    ListNode* tail;
    for (int n = 1; n < len; n <<= 1) {      
      cur = dummy.next; // partial sorted head
      tail = &dummy;
      while (cur) {
        l = cur;
        r = split(l, n);
        cur = split(r, n);
        auto merged = merge(l, r);
        tail->next = merged.first;
        tail = merged.second;
      }
    }      
    return dummy.next;
  }
private:
  // Splits the list into two parts, first n element and the rest.
  // Returns the head of the rest.
  ListNode* split(ListNode* head, int n) {    
    while (--n && head)
      head = head->next;
    ListNode* rest = head ? head->next : nullptr;
    if (head) head->next = nullptr;
    return rest;
  }
  
  // Merges two lists, returns the head and tail of the merged list.
  pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l1->val > l2->val) swap(l1, l2);
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    while (tail->next) tail = tail->next;
    return {dummy.next, tail};
  }
};