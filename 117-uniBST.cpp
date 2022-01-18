//check the BST is a unique tree or not?

//   1
// 1    1
//1 1  1  1

#include"treeNode.h"
#include<iostream>
#include<set>
#include<deque>
bool isUniTree(TreeNode* root)
{
    if(!root)
        return true;
    std::deque<TreeNode*> q;
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

int main()
{
    TreeNode* root=new TreeNode(1);
    root->addLeftChild(1);
    root->addRightChild(2);
    bool res=isUniTree(root);
    std::cout<<"Tree is Unique Value is: "<<res<<'\n';
    return 0;
}
