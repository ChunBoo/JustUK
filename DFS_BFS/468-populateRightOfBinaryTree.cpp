#include<iostream>
#include<deque>

class TreeNode
{
    private:
        int m_val{};
        TreeNode* left{};
        TreeNode* right{};
        TreeNode* next{};
    public:
        TreeNode(int v, TreeNode* left=nullptr, TreeNode* right=nullptr,TreeNode* next=nullptr):
            m_val{v},left{left},right{right},next{next}{};
        TreeNode* getRight() const {return right;}
        void setNext(TreeNode* node){next=node;}
};

using Q=std::queue<TreeNode>;

TreeNode* populateRight(TreeNode& root)
{
    if(!root)
        return root;
    Q q{root};
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;++i)
        {
            TreeNode* cur=q.front();
            q.pop_front();
            if(cur->left)
                q.push_back(cur->left);
            if(cur->right)
                q.push_back(cur->right);
            if(i!=n-1)
                cur->setNext(q.front());
        }
    }
    return root;
}
