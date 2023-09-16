/**Given the head of a linked list, rotate the list to the right by k places.

 */
 /* Definition for singly-linked list.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||!head) return head;
        ListNode *p=head, *t=nullptr,*n=nullptr;
        int sz=1;
        ListNode* dummy=head;
        while(dummy->next)
        {
            sz+=1;
            dummy=dummy->next;
        }
        t=dummy;
        int i=0;
        int K=k%sz;
        if(K==0) return head;
        while(i++<sz-K-1)
        {
            p=p->next;

        }
        n=p->next;
        p->next=nullptr;
        t->next=head;
        return n;
    }
};