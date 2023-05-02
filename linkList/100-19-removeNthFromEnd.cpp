/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
 /* Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */
#include<iostream>
// #include<>
using std::cout;


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head, *fast=head;
        int cur=1;
        while(cur<=n)
        {
            if(fast->next)
                fast=fast->next;
            else
                return head->next;
            
            cur+=1;
        }
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};


int main()
{
    ListNode *first=new ListNode(1);
    
    ListNode *second=new ListNode(2);
    ListNode *third=new ListNode(3);
    ListNode *four=new ListNode(4);
    third->next=four;
    second->next=third;
    first->next=second;
    ListNode *res=Solution().removeNthFromEnd(first,2);
    while(res)
    {
        cout<<res->val;
        res=res->next;
    }
}