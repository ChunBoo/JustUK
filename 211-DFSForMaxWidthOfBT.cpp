#include"treeNode.h"
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using DT=std::map<int,std::vector<int>>;
using DTIterator=std::map<int,std::vector<int>>::iterator;
void dfs2(TreeNode* root,DT& m,int level,int val)
{
    if(!root)   
        return ;
    DTIterator _find=m.find(level);
    if(_find!=m.end())
    {
        std::vector<int> tmpList=_find->second;
        tmpList[0]=std::min(tmpList[0],val);
        tmpList[1]=std::max(tmpList[1],val);
        _find->second=tmpList;
    }
    else
    {
        m[level].push_back(val);
        m[level].push_back(val);
    }
    dfs2(root->left,m,level+1,val*2);
    dfs2(root->right,m,level+1,val*2+1);
}

int getMaxWidth2(TreeNode* root)
{
    if(!root)
        return 0;
    DT m{};
    int max=INT_MIN,min=INT_MAX;
    dfs2(root,m,0,0);
    for(auto i:m)
    {
        max=std::max(i.second[1],max);
        min=std::min(i.second[0],min);
    }

    return max-min+1;
}



void dfs(TreeNode* root,int& max,int& min,int val)
{
    if(!root)
        return ;
    max=std::max(max,val);
    min=std::min(min,val);
    dfs(root->left,max,min,val*2);
    dfs(root->right,max,min,val*2+1);
}

int getMaxWidth(TreeNode* root)
{
    if(!root)
        return 0;

    int max=INT_MIN,min=INT_MAX;
    dfs(root,max,min,0);
    return max-min+1;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(2);
    TreeNode* right=new TreeNode(3);
    left->addLeftChild(4);
    right->addLeftChild(5);
    root->left=left;
    root->right=right;
    std::cout<<getMaxWidth2(root);
    return 0;
}