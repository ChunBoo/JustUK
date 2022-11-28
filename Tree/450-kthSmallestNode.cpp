#include<iostream>
class TreeNode
{
    private:
        int m_val{};
        TreeNode* m_left{nullptr};
        TreeNode* m_right{nullptr};
    public:
        TreeNode(int val,TreeNode* left=nullptr, TreeNode* right=nullptr): m_val{val}, m_left{left},m_right{right}{};
        void setLeft( TreeNode* left){m_left=left;}
        TreeNode* getLeft() const {return m_left;}

        void setRight( TreeNode* right){m_right=right;}
        TreeNode* getRight() const {return m_right;}

        int getVal() const {return m_val;}
};

int f(const TreeNode* root,int& k)
{
    if(k<0 || !root)
        return -1;
    f(root->getLeft(),k);
      k-=1;
    if(k==0)
        return root->getVal();
  
    f(root->getRight(),k);
}

int findKthSmallestNode(const TreeNode* root,int k)
{
    if(!root || k<0)
        return -1;
    return f(root,k);
}

int main()
{
        TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    TreeNode* right=new TreeNode(3);
    root->setLeft(left);
    root->setRight(right);
    // root->printOut();
    std::cout<<findKthSmallestNode(root,2);
}