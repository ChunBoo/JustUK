#include<iostream>
#include"treeNode.h"
#include<set>
void dfs(TreeNode* root,int x ,std::set<int>& s)
{
    if(!root)
        return ;
    s.insert(x);
    if(root->left)
        dfs(root->left,x-1,s);
    if(root->right)
        dfs(root->right,x+1,s);
}
size_t getLinesBTSet(TreeNode* root)
{
    if(!root)
        return 0;
    std::set<int> s{};
    dfs(root,0,s);
    return s.size();
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    left->addLeftChild(0);
    root->addRightChild(3);
    root->left=left;
    std::cout<<getLinesBTSet(root);
    return 0;
}