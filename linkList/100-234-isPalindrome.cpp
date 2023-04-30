/**
 * Definition for singly-linked list.
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 */


#include<vector>
#include<iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using VEC=std::vector<int>;
using std::cout;

bool isPalindrome(ListNode* head)
{
    ListNode *prev=nullptr,*slow=head,*fast=head;
    if(!head)
        return false;
    while(fast)
    {
        slow=slow->next;
        fast=fast->next?fast->next->next:fast->next;
    }
    //reverse
    while(slow)
    {
        ListNode *tmp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=tmp;
    }

    while(head&&prev)
    {
        if(head->val!=prev->val)
            return false;
        head=head->next;
        prev=prev->next;
    }
    return true;
}

