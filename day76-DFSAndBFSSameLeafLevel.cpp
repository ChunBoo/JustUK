//DFS for checking all leaves at same level
#include"treeNode.h"

#include<iostream>
#include<set>
#include<deque>

void dfs(TreeNode* root,std::set<int>& d,int curLevel)
{
    if(!root)
        return ;
    if(!root->left&&!root->right)
    {
        d.insert(curLevel);
    }
    if(root->left)
    {
        dfs(root->left,d,curLevel+1);
    }
    if(root->right)
        dfs(root->right,d,curLevel+1);
}

bool isSameLevel(TreeNode* root)
{
    std::set<int> d{};
    dfs(root,d,0);
    return d.size()==1;
}


bool BFSForCheckingSameLeafLevel(TreeNode* root)
{
    if(!root)
        return true;

    std::set<int> d{};
    std::deque<std::pair<TreeNode*,int>> q{};
    q.push_back(std::pair<TreeNode*,int>(root,0));

    while(!q.empty())
    {
        std::pair<TreeNode*,int> tempPair=q.front();
        q.pop_front();
        if(!tempPair.first->left && !tempPair.first->right)
        {
            d.insert(tempPair.second);
            if(d.size()>1)
                return false;
        }
        if(tempPair.first->left)
        {
            q.push_back(std::pair<TreeNode*,int>(tempPair.first->left,tempPair.second+1));
        }

        if(tempPair.first->right)
            q.push_back(std::pair<TreeNode*,int>(tempPair.first->right,tempPair.second+1));
    }
    return true;

}



int main()
{
    TreeNode* root=new TreeNode(4);
    TreeNode* left=new TreeNode(3);
    left->addLeftChild(2);

    TreeNode* right=new TreeNode(5);
    root->left=left;
    root->right=right;
    std::cout<<"Tree is:";
    root->printTreeInOrder(root);
    std::cout<<"\nResult is:";

    bool ret=BFSForCheckingSameLeafLevel(  root);
    std::cout<<ret<<'\n';
    return 0;

}

