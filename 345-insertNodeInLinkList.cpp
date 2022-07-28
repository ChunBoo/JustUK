#include"linkNode.h"

#include<iostream>


LinkNode* insertNodeByPos(LinkNode* head, int val, int pos)
{
    if(!head)
        return new LinkNode(val);
    LinkNode *dummyHead=new LinkNode(0);
    dummyHead->next=head;
    LinkNode *preNode=dummyHead;
    for(int i=0;i<pos;++i)
    {
        preNode=head;
        head=head->next;
    }
    LinkNode* newNode=new LinkNode(val);
    preNode->next=newNode;
    newNode->next=head;

    return dummyHead->next;
}


int main()
{
    LinkNode* firstNode=new LinkNode(1);
    LinkNode* secNode=new LinkNode(3);
    firstNode->next=secNode;

    firstNode->printNode();
    LinkNode* newLinkList=insertNodeByPos(firstNode,2,1);
    newLinkList->printNode();
    newLinkList=insertNodeByPos(firstNode,4,3);
    newLinkList->printNode();

    return 0;
}