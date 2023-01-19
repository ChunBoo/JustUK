#include<iostream>
class TreeNode
{
    public:
        int m_val{};
        TreeNode* m_left{};
        TreeNode* m_right{};
        TreeNode(int v=0, TreeNode* l=nullptr, TreeNode* r=nullptr):m_val{v},m_left{l},m_right{r}{};
};

bool dfoo(const TreeNode* root)
{
    if((!root->m_left) &&(!root->m_right))
        return root->m_val==1;
    bool l=dfoo(root->m_left);
    bool r=dfoo(root->m_right);
    if(root->m_val==3)
        return l && r;
    return l ||r;
}

bool evaluateTree(const TreeNode* root)
{
    return dfoo(root);
}


int main()
{
    TreeNode* root=new TreeNode(3);
    TreeNode* left=new TreeNode(1);
    TreeNode* right1=new TreeNode(3);
    TreeNode* left2=new TreeNode(1);
    TreeNode* right2=new TreeNode(0);

    root->m_left=left;
    root->m_right=right1;

    right1->m_left=left2;
    right1->m_right=right2;

    std::cout<<evaluateTree(root);
}