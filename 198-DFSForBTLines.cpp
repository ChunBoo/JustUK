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
    std::set<int> s;
    if(!root)
        return 0;
    int x=0;
    dfs(root,0,s);
    return s.size();
}

int main()
{
    TreeNode* root=new TreeNode(2);
    root->addLeftChild(1);
    root->addRightChild(3);
    std::cout<<getLinesBTSet(root);
    return 0;
}