#include "linkNode.h"
#include<iostream>


void deleteNode(LinkNode* node)
{
    LinkNode* prev=nullptr;
    while(node->next)
    {
        node->m_val=node->next->m_val;
        prev=node;
        node=node->next;
    }
    prev->next=nullptr;
    delete node;
    node=nullptr;
}

void delNode(LinkNode* node)
{
    LinkNode* next=node->next;
    node->m_val=next->m_val;
    node->next=next->next;
    delete next;
}

int main()
{
    LinkNode *root=nullptr;
    LinkNode* first=new LinkNode(1);
    LinkNode* second=new LinkNode(2);
    LinkNode* third=new LinkNode(3);
    LinkNode* fourth=new LinkNode(4);
    first->next=second;
    second->next=third;
    third->next=fourth;
    first->printNode();
    delNode(second);
    // deleteNode(second);
    first->printNode();

}