//given a binary tree, return true if it can be splitted by two same tree which they has same sum
#include"treeNode.h"
#include<iostream>
#include<set>   //

int dfs(TreeNode* root,std::set<int>& seen)
{
    if(!root)
        return 0;
    int ans=0;
    ans+=root->m_val+dfs(root->left,seen)+dfs(root->right,seen);
    seen.insert(ans);
    return ans;
}

int main()
{
    TreeNode *root=new TreeNode(10);
    TreeNode *left=new TreeNode(5);
    TreeNode *right=new TreeNode(10);
    TreeNode *left2=new TreeNode(1);
    TreeNode *right2=new TreeNode(4);
    root->left=left;
    root->right=right;
    right->left=left2;
    right->right=right2;

    std::set<int> seen{};
    int sum=dfs(root,seen);
    if(seen.find(sum/2)!=seen.end())
        std::cout<<"Can be splitted as two same subtree.\n";
    else
        std::cout<<"Can not be splitted as two same subtree.\n";
    return 0;
}