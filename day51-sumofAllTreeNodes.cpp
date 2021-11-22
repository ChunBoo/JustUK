//used the double end queue:deque(deck) to calculate all the node's sum

#include<iostream>
#include<deque>
#include<vector>
class TNodes
{
    public:
        int m_value;
        TNodes *lChild;
        TNodes *rChild;
        TNodes(int value):m_value{value},lChild{nullptr},rChild{nullptr}{}
        TNodes* addLeftChild(int cValue)
        {
            TNodes* newNode=new TNodes(cValue);
            this->lChild=newNode;
            return newNode;
        }
        TNodes* addRightChild(int cValue)
        {
            TNodes* newNode=new TNodes(cValue);
            this->rChild=newNode;
            return newNode;
        }
};


int sumOfNodes(TNodes *root)
{
    if(!root)
        return 0;
    std::deque<TNodes*> q{};
    int ans=0;
    q.push_back(root);
    while(!q.empty())
    {
        TNodes *tNode=q.front();
        ans+=tNode->m_value;
        q.pop_front();
        if(tNode->lChild)
            q.push_back(tNode->lChild);
        if(tNode->rChild)
            q.push_back(tNode->rChild);
    }
    return ans;
}


int main()
{
    std::vector<int> nodes{2,3,4,5};
    TNodes *root=new TNodes(10);
    root->addLeftChild(2);
    TNodes *rightNode= new TNodes(3);
    rightNode->addLeftChild(4);
    rightNode->addRightChild(15);
    root->rChild=rightNode;

    int sum=sumOfNodes(root);
    std::cout<<"Sum of tree is: "<<sum<<'\n';

    return 0;
}