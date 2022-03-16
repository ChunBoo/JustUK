//given a binary tree, return how many vertical lines can be found
/*
           4
        3     5
      2  3.5 4.5 6

*/

#include<iostream>
#include"treeNode.h"
#include<deque>
#include<cmath>
#include<set>

using DT=std::deque<std::pair<TreeNode*,int>>;  //<TreeNode*,offset>
using PAIR=std::pair<TreeNode*,int>;


int getLinesBTSet(TreeNode* root)
{
  if(!root)
    return 0;
  DT q{{root,0}};
  std::set<int> s{};
  while(!q.empty())
  {
      TreeNode* curNode=q.front().first;
      int curOffset=q.front().second;
      q.pop_front();
      s.insert(curOffset);
      if(curNode->left)
        q.push_back({curNode->left,curOffset-1});
      if(curNode->right)
        q.push_back({curNode->right,curOffset+1});
  }
  return s.size();
}



size_t getLinesBT(TreeNode* root)  //this method is wrong!!!!
{
    size_t ans=0;
    if(!root)
        return ans;
    std::deque<TreeNode*> q{};
    q.push_back(root);
    while(!q.empty())
    {
        ans=std::max(ans,q.size()+1);

        TreeNode* cur=q.front();
        q.pop_front();
        if(cur->left)
            q.push_back(cur->left);
        if(cur->right)
            q.push_back(cur->right);
    }
    return ans;
}

int main()
{
    TreeNode* root=new TreeNode(2);
    TreeNode* left=new TreeNode(1);
    left->addLeftChild(0);
    root->addRightChild(3);
    root->left=left;
    std::cout<<getLinesBT(root);
    return 0;
}