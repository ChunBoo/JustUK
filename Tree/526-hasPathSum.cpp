#include<iostream>
using std::cout;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v,TreeNode* l=nullptr, TreeNode* r=nullptr):val{v},left{l},right{r}{};
};

bool f(const TreeNode* root, int v,int target)
{
    if(!root)
        return false;
    v+=root->val;
    if((v==target)&&(!root->left)&&(!root->right))
        return true;
    return f(root->left,v,target)||f(root->right,v,target);
}

bool hasPathSum(const TreeNode* root,int target)
{
    int iVal=0;
    return f(root,iVal,target);
}

int main()
{
    TreeNode* root=new TreeNode(7);
    TreeNode* one=new TreeNode(1);
    TreeNode* two=new TreeNode(2);
    TreeNode* three=new TreeNode(3);

    root->left=one;
    one->left=two;
    one->right=three;
    cout<<hasPathSum(root,11);
}
