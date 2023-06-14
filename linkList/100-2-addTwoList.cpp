

#include "../linkNode.h"

LinkNode* addTwoLinkList(LinkNode* l1, LinkNode* l2)
{
    LinkNode dummy;
    LinkNode* tail=&dummy;
    int sum=0;
    while(l1||l2||sum)
    {
        sum+=(l1?l1->m_val:0)+(l2?l2->m_val:0);
        l1=l1?l1->next:nullptr;
        l2=l2?l2->next:nullptr;
        LinkNode* newNode=new LinkNode(sum%10);
        sum/=10;
        tail->next=newNode;
        tail=tail->next;
    }
    return dummy.next;

}