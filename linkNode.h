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
            LinkNode* p=this;
            LinkNode* newNode=new LinkNode(val);
            p->next=newNode;
            p=p->next;
            return newNode;
        }

        void printNode()
        {
            LinkNode* p=this->next;
            while(p&&p->next)
            {
                std::cout<<p->m_val<<'-';
                p=p->next;
            }
            std::cout<<p->m_val<<'\n';
        }
};
/*
LinkNode* mergeLists(LinkNode* headA,LinkNode* headB)
{
    if(!headA||!headB)
        return headA?headA:headB;
    LinkNode* dummy=new LinkNode(-1);
    
    while(headA && headB)
    {
        if(headA->m_val<=headB->m_val)
        {
            dummy->next=headA;
            headA=headA->next;
        }
        else
        {
            dummy->next=headB;
            headB=headB->next;
        }
        dummy=dummy->next;
    }
    if(headA)
        dummy->next=headA;
    if(headB)
        dummy->next=headB;
    return dummy->next;
}
*/


    LinkNode* mergeLists(LinkNode* list1,LinkNode* list2){
        if((!list1)||(!list2)){
            return list1?list1:list2;
        }
        LinkNode* head,* cur;
        if(list1->m_val>list2->m_val){
            head=list2;
            list2=list2->next;
        }else{
            head=list1;
            list1=list1->next;
        }
        cur=head;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->m_val>list2->m_val){
                cur->next=list2;
                list2=list2->next;
            }else{
                cur->next=list1;
                list1=list1->next;
            }
            cur=cur->next;
        }
        if(list1!=nullptr) cur->next=list1;
        if(list2!=nullptr) cur->next=list2;
        return head;
    }
#endif