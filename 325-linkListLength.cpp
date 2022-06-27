#include"linkNode.h"
#include<iostream>


int LLength(const LinkNode* header)
{
    if(!header)
        return 0;
    // int ans=0;
    return 1+LLength(header->next);
}

int main()
{
    LinkNode *header=new LinkNode(0);
    LinkNode *first=new LinkNode(1);
    LinkNode *second=new LinkNode(2);
    LinkNode *third=new LinkNode(3);
    header->next=first;
    first->next=second;
    second->next=third;

    std::cout<<LLength(header);
}
