//reverse LL

#include<iostream>
#include<vector>

class CListNode
{
    public:
     int m_value{};
     CListNode *next=nullptr;
     CListNode(int val):m_value{val},next{nullptr}{}
     CListNode *addNode(int val)
     {
         CListNode *newNode= new CListNode(val);
         this->next=newNode;
         return newNode;
     }
     void printList(CListNode* head)
     {
         if(!head)
            return;
         CListNode *p=head;
         while(p)
         {
             std::cout<<p->m_value<<'\n';
             p=p->next;
         }
     }
     CListNode *reverseList(CListNode *head)
     {
         if(!head || !head->next)
            return head;
         CListNode *ret=reverseList(head->next);
        //  ret->next=head;
         head->next->next=head;
         head->next=nullptr;
         return ret;
     }

     CListNode *reverseList2(CListNode *head)
     {
        if(!head||!head->next)
            return head;
        CListNode* pre=nullptr;
        CListNode* cur=head;
        while(cur)
        {
            CListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
     }
};


int main()
{
    std::vector<int> elem{1,2,3,4,5};
    CListNode *head=new CListNode(-1);
    CListNode *p=head;
    for(auto i: elem)
    {
        p->next=p->addNode(i);
        p=p->next;
    }
    p=head;
    std::cout<<"Before Reverse,the list is: \n";
    p->printList(p);
    CListNode *rNode= p->reverseList2(p);
    std::cout<<"After Reverse,the list is: \n";
    rNode->printList(rNode);
    
    return 0;
}


