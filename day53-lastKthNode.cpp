//the last kth node
#include<iostream>
#include<vector>

class Node
{
    public:
        int m_value;
        Node* next;
        Node(int val):m_value{val},next{nullptr}{}
        int getLastKthNode(int k);
        Node* addNode(int val)
        {
            Node* newNode=new Node(val);
            this->next=newNode;
            return newNode;
        }
};


int Node::getLastKthNode(int k)
{
    if(!this)
        return 0;
    if(k<=0)
        return -1;
    Node* p=this;
    Node* h=this;
    for(int i=0;i<k;++i)
        p=p->next;
    
    while(p)
    {
        h=h->next;
        p=p->next;
    }
    return h->m_value;
}


int main()
{
    Node *head=new Node(-1);
    Node *p=head;
    for(int i=1;i<6;++i)
    {
        p->addNode(i);
        p=p->next;
    }
    int kthValue=head->getLastKthNode(0);
    std::cout<<"The last kth value is: "<<kthValue<<'\n';
    return 0;
}


