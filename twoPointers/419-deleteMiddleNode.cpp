#include<iostream>
#include<vector>

class Node
{
    public:
        Node(int v,Node* next=nullptr):m_val{v}, m_next{next}{};
        Node* addNode(int v)
        {
            Node* newNode=new Node(v);
            this->m_next=newNode;
            return newNode;
        }
        void printList(Node* head)
        {
            while(head)
            {
                std::cout<<head->m_val<<"->";
                head=head->m_next;
            }
        }
        Node*  solution(Node* head)
        {
            if(!head)
                return head;
            if(!head->m_next)
                return head->m_next;
            
            Node* fast=head;
            Node* slow=head;
            Node* preNode=nullptr;
            while(fast && fast->m_next)
            {
                fast=fast->m_next->m_next;
                preNode=slow;
                slow=slow->m_next;
            }
            preNode->m_next=slow->m_next;
            return head;
        }
    private:
        int m_val;
        Node* m_next;
};


int main()
{
    std::vector<int> nums{1,2,3,4};
    Node s=Node(0);
    Node *p=&s;
    for(auto i:nums)
        p=p->addNode(i);
    
    s.printList(&s);
    s.solution();
    s.printList(&s);
}

