#include<iostream>
#include "linkNode.h"
#include<vector>
bool isLinkListIsascending(LinkNode* head)
{
    if(!head)
        return true;
    
    LinkNode *slow=head,*fast=head->next;
    while(fast)
    {
        if(slow->m_val>=fast->m_val)
            return false;
        slow=fast;
        fast=fast->next;
    }
    return true;
}

bool isLinkListIsascendingVector(const LinkNode* head)
{
    std::vector<int> vals{};
    if(!head)
        return true;
    
    while(head)
    {
        vals.push_back(head->m_val);
        head=head->next;
    }
    for(int i=1;i<vals.size();++i)
    {
        if(vals[i-1]>=vals[i])
            return false;
    }
    return true;
}


int main()
{
    LinkNode *head=new LinkNode(1);
    LinkNode *first=new LinkNode(2);
    LinkNode *second=new LinkNode(3);
    LinkNode *third=new LinkNode(4);

    head->next=first;
    first->next=second;
    second->next=third;
    std::cout<<isLinkListIsascendingVector(head);
    return 0;
}