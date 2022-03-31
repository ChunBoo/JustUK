#include"linkNode.h"
#include<stack>
#include<iostream>
#include<vector>
bool isPanlindromeLinkedList(LinkNode* head)  //used array method
{
    if(!head)
        return true;
    std::vector<int> vec{};
    LinkNode* p=head;
    while(p)
    {
        vec.push_back(p->m_val);
        p=p->next;
    }
    int sz=vec.size();
    for(int i=0;i<sz/2;++i)
    {
        if(vec[i]!=vec[sz-i-1])
            return false;
    }
    return true;
}

bool isPanlindromeLinkedList3(LinkNode* head)  //used stack method
{
    if(!head)
        return true;
    std::stack<LinkNode*> s{};
    LinkNode* p=head;
    while(p)
    {
        s.push(p);
        p=p->next;
    }
    while(head)
    {
        LinkNode* topNode=s.top();
        s.pop();
        if(topNode->m_val!=head->m_val)
            return false;
        head=head->next;
    }
    return true;
}
bool isPanlindromeLinkedList22(LinkNode* head)  //revert second half of LL method
{
    if(!head)
        return true;
    //fast,slow pointers method
    LinkNode* fast=head;
    LinkNode* slow=head;

    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    //revert the second half
    LinkNode* right=nullptr;
    while(slow)
    {
        LinkNode* p=slow->next;  //create temp pointer to save the slow->next
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
    LinkNode* last=new LinkNode(1);
    head->next=first;
    first->next=second;
    second->next=last;
    std::cout<<isPanlindromeLinkedList(head);
    return 0;
}
