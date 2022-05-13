#include"treeNode.h"

#include<iostream>
#include<set>
int dfs(TreeNode* root,std::set<int>& seen)
{
    if(!root)
        return 0;
    int s=0;
    s=root->m_val+dfs(root->left,seen)+dfs(root->right,seen);
    seen.insert(s);
    return s;
}

int main()
{
    TreeNode *root=new TreeNode(10);
    TreeNode *left=new TreeNode(5);
    TreeNode *right=new TreeNode(10);
    TreeNode *left2=new TreeNode(2);
    TreeNode *right2=new TreeNode(4);
    root->left=left;
    root->right=right;
    right->left=left2;
    right->right=right2;

    std::set<int> seen{};
    int sum=dfs(root,seen);
    if(seen.find(sum/2)!=seen.end())
        std::cout<<"Can be splitted as two same subtree.\n";

    return 0;
}