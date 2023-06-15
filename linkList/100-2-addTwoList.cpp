

#include "../linkNode.h"

LinkNode* addTwoLinkList(LinkNode* l1, LinkNode* l2)
{
    LinkNode dummy;
    LinkNode* tail=&dummy;
    int sum=0;
    while(l1||l2||sum)
    {
        sum+=(l1?l1->m_val:0)+(l2?l2->m_val:0);
        LinkNode* newNode=new LinkNode(sum%10);
        sum/=10;
        tail->next=newNode;
        tail=tail->next;
        l1=l1?l1->next:nullptr;
        l2=l2?l2->next:nullptr;
    }
    return dummy.next;
}

int main()
{
        LinkNode* HA=new LinkNode(-1);
    LinkNode* HB=new LinkNode(-1);
    LinkNode* pA=HA;
    LinkNode* pB=HB;
    for(int i=1;i<6;++i)
    {
        pA->next=new LinkNode(i);
        pA=pA->next;
    }
    for(int i=7;i<9;++i)
    {
        pB->next=new LinkNode(i);
        pB=pB->next;
    }
    LinkNode* sum=addTwoLinkList(HA->next,HB->next);
    sum->printNode();
}