
#include"linkNode.h"
#include<iostream>
void swapLinkNodes(LinkNode* header)
{
    LinkNode* p=header;
    while( p&&p->next)
    {
        int temp=p->m_val;
        p->m_val=p->next->m_val;
        p->next->m_val=temp;
        p=p->next->next;
    }
}


LinkNode* swapNodeRecursion(LinkNode* node)
{
    if(!node || !node->next)
        return node;
    LinkNode* tail=swapNodeRecursion(node->next->next);
    LinkNode* header=node->next;

    header->next=node;
    node->next=tail;
    return header;
}

int main()
{
    LinkNode* head=new LinkNode(1);
    head->addNode(2);
    head->printNode();
    LinkNode* newHeader=swapNodeRecursion(head);
    // swapLinkNodes(head);
    newHeader->printNode();
    return 0;
}