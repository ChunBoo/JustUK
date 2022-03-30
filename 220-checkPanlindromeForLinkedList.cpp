#include"linkNode.h"

#include<iostream>

bool isPanlindromeLinkedList(LinkNode* head)
{
    if(!head)
        return true;
    LinkNode* fast=head;
    LinkNode* slow=head;
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    LinkNode* right=nullptr;
    while(slow)
    {
        LinkNode* p=slow->next;
        slow->next=right;
        right=slow;
        slow=p;
    }
    LinkNode* left=head;
    while(left&&right)
    {
        if(left->m_val!=right->m_val)
            return false;
        left=left->next;
        right=right->next;
    }
    return true;
}


int main()
{
    LinkNode* head=new LinkNode(1);
    LinkNode* first=new LinkNode(2);
    LinkNode* second=new LinkNode(2);
    LinkNode* last=new LinkNode(3);
    head->next=first;
    first->next=second;
    second->next=last;
    std::cout<<isPanlindromeLinkedList(head);
    return 0;
}
