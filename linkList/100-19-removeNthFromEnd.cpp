/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */
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