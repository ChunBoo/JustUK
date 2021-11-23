// if a link list has a cycle or not
#include<iostream>
#include<vector>
class LinkNode
{
    public:
        int val;
        LinkNode* next;
        LinkNode(int value):val{value},next{nullptr}{}
        LinkNode* addNode(int value)
        {
            LinkNode* newNode= new LinkNode(value);
            this->next=newNode;
            return this;
        }
};

bool hasCycle(LinkNode* head)
{
    if(!head)
        return true;
    
    LinkNode* fast=head;
    LinkNode* slow=head;

    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)  // can not judge by value
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> nums{1,2,3,4,5};
    LinkNode *head=new LinkNode(-1);
    LinkNode *p=head;
    for(auto i:nums)
    {
        LinkNode* newNode=new LinkNode(i);
        p->next=newNode;
        p=p->next;
    }
    // p->next=head->next;
    bool isCycled=hasCycle(head);
    std::cout<<"LL has cycle:"<<(isCycled?"Yes":"No")<<'\n';
    return 0;
}