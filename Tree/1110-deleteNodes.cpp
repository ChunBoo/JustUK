#include "treeNode.h"
#include<vector>
#include<iostream>
#include<algorithm> //for std::find
using VEC=std::vector<int>;
using std::cout;

TreeNode* process(TreeNode* root, VEC& to_del, VEC& ans)
{
    if(!root)
        return nullptr;
    root->left=process(root->left,to_del,ans);
    root->right=process(root->right,to_del,ans);
    if(std::find(to_del.begin(),to_del.end(),root->m_val)==to_del.end())
        return root;
    if(root->left)
        ans.push_back(root->left->m_val);
    if(root->right)
        ans.push_back(root->right->m_val);
    return nullptr;
}


VEC delNodes(TreeNode* root, VEC& to_delete)
{
    VEC ans{};
    if(!root)
        return ans;
    root=process(root,to_delete,ans);
    if(root)
        ans.push_back(root->m_val);
    return ans;
}

int main()
{
        TreeNode *root=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *five=new TreeNode(5);
    // TreeNode *six=new TreeNode(6);
    // TreeNode *seven=new TreeNode(7);

    root->left=two;
    root->right=three;

    two->left=four;
    three->right=five;
    VEC to_del{2,3};
    VEC ans=delNodes(root,to_del);
    for(auto i:ans)
        cout<<i<<',';
}