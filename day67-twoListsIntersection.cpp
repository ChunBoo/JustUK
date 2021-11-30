//return the intersection node of two link lists
#include"linkNode.h"
#include<iostream>
#include<set>

LinkNode* getIntersectionUsingSet(LinkNode* ha,LinkNode* hb)
{
    std::set<LinkNode*> s;
    while(ha)
    {
        s.insert(ha);
        ha=ha->next;
    }
    while(hb)
    {
        auto inSet=s.find(hb);
        if(inSet!=s.end())
        {
            return hb;
        }
        hb=hb->next;
    }
    return nullptr;
}


LinkNode* getIntersectionUsingTwoPointers(LinkNode* ha,LinkNode* hb)
{
    if(!ha||!hb)
        return nullptr;
    LinkNode* a=ha;
    LinkNode* b=hb;
    while(a!=b)
    {
        a=a?a->next:hb;
        b=b?b->next:ha;
    }
    return a;
}


int main()
{
    LinkNode* ha=new LinkNode(-1);
    LinkNode* hb=new LinkNode(-1);

    LinkNode* pa=ha;

    for(int i=0;i<3;++i)
    {
        pa->next=new LinkNode(i);
        pa=pa->next;
    }

    LinkNode* commonNode= new LinkNode(6);
    pa->next=commonNode;

    LinkNode* pb=hb;
    for(int i=3;i<5;++i)
    {
        pb->next=new LinkNode(i);
        pb=pb->next;
    }
    pb->next=commonNode;
    LinkNode* retComNode=getIntersectionUsingTwoPointers(ha,hb);
    std::cout<<"insection node value: "<<retComNode->m_val<<"\n";

    return 0;


}