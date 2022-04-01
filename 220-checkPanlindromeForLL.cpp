//recursion method for the checking one linked list 
//is a panlindrom or not
#include"linkNode.h"
#include<iostream>
LinkNode* g_root=nullptr;
bool dfs(LinkNode* node)
{
    if(!node)
        return true;
    bool ans=dfs(node->next);
    if(g_root->m_val!=node->m_val)
        return false;
    g_root=g_root->next;
    return ans;
}

bool checkingMethod(LinkNode* head)
{
    g_root=head;
    return dfs(head);
}

int main()
{
    LinkNode* head=new LinkNode(1);
    LinkNode* first=new LinkNode(2);
    LinkNode* second=new LinkNode(2);
    LinkNode* last=new LinkNode(1);
    head->next=first;
    first->next=second;
    second->next=last;
    std::cout<<checkingMethod(head);
    return 0;
}