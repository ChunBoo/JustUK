#include"linkNode.h"
#include<iostream>
#include<vector>

// using bs for sort linked list

LinkNode* breakMid(LinkNode* head)
{
    if(!head||!head->next)
        return head;
    LinkNode* fast=head;
    LinkNode* slow=head;
    LinkNode* prev=nullptr;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=nullptr;
    return slow;
}

LinkNode* merge(LinkNode* ha,LinkNode* hb)
{
    LinkNode* dummy=new LinkNode(-1);

    while(ha&&hb)
    {
        if(ha->m_val<hb->m_val)
        {
            dummy->next=ha;
            ha=ha->next;
        }
        else
        {
            dummy->next=hb;
            hb=hb->next;
        }
        dummy=dummy->next;
    }
    return dummy->next;
}

LinkNode* mergeSortList(LinkNode* head)
{
    if(!head||!head->next)
        return head;
    LinkNode *right=mergeSortList(breakMid(head));
    LinkNode *left=mergeSortList(head);
    return merge(right,left);
    
}

int main()
{
    std::vector<int> nums{1,3,2,5,4};
    LinkNode* head=new LinkNode(-1);
    LinkNode* p=head;
    for(auto i:nums)
    {   
        p->addNode(i);
        p=p->next;
    }
    head->printList();
    LinkNode *newHead=mergeSortList(head);
    newHead->printList();
    return 0;
}