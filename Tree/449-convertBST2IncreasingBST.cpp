#include<iostream>
#include<vector>
using VEC=std::vector<int>;

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
        void inorder(TreeNode* root,VEC& nodes)
        {
            if(!root)
                return ;
            inorder(root->m_left,nodes);
            nodes.push_back(root->m_val);
            inorder(root->m_right,nodes);
        }
        void printOut()
        {
            VEC nodes{};
            inorder(this,nodes);
            for(auto &v:nodes)
                std::cout<<v<<",";
        }
};

void f(TreeNode* root, VEC& nodes)
{
    if(!root)
        return ;
    f(root->getLeft(),nodes);
    nodes.push_back(root->getVal());
    f(root->getRight(),nodes);
}
TreeNode* convertBST2IncreasingBST( TreeNode* root)
{
    if(!root)
        return root;
    VEC nodes{};
    f(root,nodes);
    TreeNode* cur=new TreeNode(-1);
    TreeNode* ans=cur;
    for(auto &v:nodes)
    {
        cur->setRight(new TreeNode(v));
        cur=cur->getRight();
    }   
    return ans->getRight();
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    TreeNode* right=new TreeNode(3);
    root->setLeft(left);
    root->setRight(right);
    root->printOut();
    std::cout<<"\nnew res:\n";
    TreeNode* ans=convertBST2IncreasingBST(root);
    ans->printOut();
}