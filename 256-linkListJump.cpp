#include"linkNode.h"
#include<iostream>
//given a link list's header, return a new link list after removing the nodes
LinkNode* jump(LinkNode* node)
{   
    if(!node)
        return nullptr;
    LinkNode* head=node;
    for(int i=0;i<head->m_val;++i)
    {
        head=head->next;
        if(!head)
            break;
    }
    node->next=jump(head);
    return node;
}

int main()
{
    LinkNode* head=new LinkNode(2);
    head->addNode(2);
    head->printNode();
    LinkNode* newHeader=jump(head);
    // swapLinkNodes(head);
    newHeader->printNode();
    return 0;
}