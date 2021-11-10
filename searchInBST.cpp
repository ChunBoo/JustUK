
//serach in BST

#include<iostream>
#include<vector>

struct Node
{
    int m_val;
    Node* left=nullptr;
    Node* right=nullptr;
};

class CNode
{
    private:
        int m_val;
        CNode* left{nullptr};
        CNode* right{nullptr};
    public:
        CNode(int value):m_val{value}{}
};


CNode* createTree(const std::vector<int>& nums)  //create BST tree method ....
{
    if(nums.empty())
        return nullptr;

    CNode *header{nullptr};

    for(auto i:nums)
    {
        CNode* newNode=new CNode(i);
        header->
    }
}

bool searchInBST(CNode* root,int target)
{
    if(!root)
        return false;
    if(root->m_val==target)
        return true;
    
    if(root->m_val<target)
        return searchInBST(root->left,target);
    else
        return searchInBST(root->right,target);
}

int main()
{

}