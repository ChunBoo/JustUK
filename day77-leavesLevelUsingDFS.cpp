// 深度优先搜索算法判断某棵树的叶子节点是否在同一个level上

#include<iostream>
#include<set>
#include "treeNode.h"
void dfs(TreeNode* root,int curLevel,std::set<int>& s)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
    {
        s.insert(curLevel);
    }
    dfs(root->left,curLevel+1,s);
    dfs(root->right,curLevel+1,s);

}
bool sameLeavesLevel(TreeNode* root)
{
    std::set<int> s{};
    dfs(root,0,s);
    std::cout<<s.size()<<'\n';
    return s.size()==1;
}


int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* left=new TreeNode(3);
    left->addLeftChild(2);
    root->left=left;
    TreeNode* right=new TreeNode(5);
    root->right=right;
    root->printTreeInOrder(root);
    std::cout<<'\n';
    bool sameLevel=sameLeavesLevel(root);
    std::cout<<sameLevel<<'\n';
    return 0;
}