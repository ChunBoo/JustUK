//check the BST is a unique tree or not?
//used the BFS: Bread First Search
//   1
// 1    1
//1 1  1  1

#include"treeNode.h"
#include<iostream>
#include<set>
#include<deque>

bool isUniTreeBFS(TreeNode* root)
{
    if(!root)
        return true;
    std::deque<TreeNode*> q;  //used the deque for BFS
    q.push_back(root);
    std::set<int> s{};

    while(!q.empty())
    {
        TreeNode* tempNode=q.front();
        q.pop_front();
        s.insert(tempNode->m_val);
        if(s.size()>1)
            return false;
        if(tempNode->left)
            q.push_back(tempNode->left);
        if(tempNode->right)
            q.push_back(tempNode->right);
    }
    return true;
}

void dfs(TreeNode* root, std::set<int>& d)
{
    if(!root)
        return ;
    d.insert(root->m_val);
    dfs(root->left,d);  // DFS likes recursion
    dfs(root->right,d);
}

bool isUniTreeDFS(TreeNode* root)
{
    if(!root)
        return true;
    std::set<int> d{};
    dfs(root,d);
    return d.size()==1;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->addLeftChild(1);
    root->addRightChild(1);
    bool res=isUniTreeDFS(root);
    std::cout<<"Tree is Unique Value is: "<<res<<'\n';
    return 0;
}
