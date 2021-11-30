#ifndef LINK_NODE_H
#define LINK_NODE_H
#include<iostream>
class LinkNode
{
    public:
        int m_val;
        LinkNode* next;
        LinkNode(int val):m_val{val},next{nullptr}{}

        LinkNode* addNode(int val)
        {
            LinkNode* newNode=new LinkNode(val);
            this->next=newNode;
            return newNode;
        }

        void printList()
        {
            LinkNode* p=this->next;
            while(p&&p->next)
            {
                std::cout<<p->m_val<<"->";
                p=p->next;
            }
            if(!p->next)
                std::cout<<p->m_val;
            std::cout<<'\n';
        }
};
#endif