//the middle element of a ll
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


LinkNode* middleNode(LinkNode* head)
{
    if(!head)
        return nullptr;
    
    LinkNode* slow=head;
    LinkNode* fast=head;

    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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
    LinkNode* midNode=middleNode(head);
    std::cout<<"Middle node value: "<<midNode->val<<'\n';
    return 0;

}