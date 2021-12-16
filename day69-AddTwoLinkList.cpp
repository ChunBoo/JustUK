//add two link lists,used reversed order
//lsd:least significant digit


#include"linkNode.h"
#include<iostream>

LinkNode* addTwoLinkLists(LinkNode* ha,LinkNode* hb)
{
    LinkNode* dummy = new LinkNode(-1);
    LinkNode* head=dummy;
    int carry=0;
    while(ha||hb||carry)
    {
        int curValue=carry;
        if(ha)
        {
            curValue+=ha->m_val;
            ha=ha->next;
        }
        if(hb)
        {
            curValue+=hb->m_val;
            hb=hb->next;
        }
        carry=curValue/10;
        dummy->next=new LinkNode(curValue%10);
        dummy=dummy->next;
    }
    return head->next;
}

int main()
{
    LinkNode* HA=new LinkNode(-1);
    LinkNode* HB=new LinkNode(-1);
    LinkNode* pA=HA;
    LinkNode* pB=HB;
    for(int i=1;i<3;++i)
    {
        pA->next=new LinkNode(i);
        pA=pA->next;
    }
    for(int i=3;i<5;++i)
    {
        pB->next=new LinkNode(i);
        pB=pB->next;
    }
    LinkNode* sum=addTwoLinkLists(HA->next,HB->next);
    sum->printNode();

    return 0;
}