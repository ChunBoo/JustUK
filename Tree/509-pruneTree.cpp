#include<iostream>


class TreeNode
{
    public:
        int m_val;
        TreeNode* left{nullptr};
        TreeNode* right{nullptr};
        TreeNode(int v,TreeNode* l=nullptr,TreeNode* r=nullptr):m_val{v},left{l},right{r}{};
        void printTreeNodePreOrder(TreeNode* root)
        {
            if(!root)
                return;
            std::cout<<root->m_val<<'-';
            printTreeNodePreOrder(root->left);
            printTreeNodePreOrder(root->right);
        }
};


TreeNode* pruneTree(TreeNode* root)
{
    if(!root)
        return root;
    
    root->left=pruneTree(root->left);
    root->right=pruneTree(root->right);

    if(!root->left&&!root->right&&(root->m_val!=1))
        return nullptr;
    return root;
}


int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(0);
    TreeNode* right=new TreeNode(1);
    TreeNode* right2=new TreeNode(1);
    root->left=left;
    root->right=right;
    right->right=right2;
    root->printTreeNodePreOrder(root);
    TreeNode* res=pruneTree(root);
    std::cout<<'\n';
    res->printTreeNodePreOrder(res);
}