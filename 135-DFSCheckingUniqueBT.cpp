//DFS for unique binary tree

#include "treeNode.h"
#include<iostream>
#include<set>

void getAllNodesValue(TreeNode* root,std::set<int>& s)
{    if(!root)
        return ;
    s.insert(root->m_val);
    if(root->left)
        getAllNodesValue(root->left,s);
    if(root->right)
        getAllNodesValue(root->right,s);}
bool isUniqueTreeByDFS(TreeNode* root)
{
    std::set<int> s;
    if(!root)
        return true;
    getAllNodesValue(root,s);
    return s.size()==1;
}

#if 0
bool getAllNodesValueisUniqueTree(TreeNode* root,int val)
{
    if(!root)
        return true;
    if(root->m_val!=val)
        return false;
    bool ans=true;
    if(root->left)
      ans&=  isUniqueTree(root->left,val);
    if(root->right)
        ans&=isUniqueTree(root->right,val);

    return ans;

}
#endif
int main()
{
     TreeNode* root=new TreeNode(1);
    TreeNode* l1Left=new TreeNode(1);
    TreeNode* l1right=new TreeNode(1);
    TreeNode* l21left=new TreeNode(1);
    TreeNode* l21right=new TreeNode(1);
    TreeNode* l22left=new TreeNode(1);
    TreeNode* l22right=new TreeNode(2);
    
    l1Left->left=l21left;
    l1Left->right=l21right;
    
    l1right->left=l22left;
    l1right->right=l22right;

    root->left=l1Left;
    root->right=l1right;
    bool res=isUniqueTreeByDFS(root);
    std::cout<<res<<'\n';

    return 0;
}