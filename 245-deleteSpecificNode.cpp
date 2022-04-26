#include "linkNode.h"
#include<iostream>
//delete the specific node from a linked list, this node can not be the last one

void deleteNodeWhileLoop(LinkNode* node)
{     
    LinkNode* prev=node;
    while(node->next)
    {
        node->m_val=node->next->m_val;
        prev=node;
        node=node->next;
    }
    prev->next=nullptr;
    delete node;
}

void delNode(LinkNode* node)
{
    LinkNode* next =node->next;
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
    // deleteNodeWhileLoop(second);
    // deleteNodeWhileLoop(fourth);
    delNode(fourth);
    first->printNode();

}