// given a binary search tree and one target value ,if there are two nodes sum is equal to target,return true,
//or return false
#include"treeNode.h"
#include<vector>
#include<iostream>

void getNodesInOrder(std::vector<int>& nodes,TreeNode* head)  //inorder method to get all ones in BST
{
    if(!head)
        return ;
    getNodesInOrder(nodes,head->left);
    nodes.push_back(head->m_val);
    getNodesInOrder(nodes,head->right);
}

bool isHasTarget(TreeNode* head,int target)
{
    if(!head)
        return false;
    std::vector<int> nodes{};
    getNodesInOrder(nodes,head);

    int L=0,R=nodes.size()-1;  //two pointers
    while(L<R)
    {
        if(nodes[L]+nodes[R]==target)
            return true;
        if(nodes[L]+nodes[R]>target)
            R-=1;
        else
            L+=1;
    }
    return false;
}

int main()
{
    TreeNode* root= new TreeNode(7);
    TreeNode* l1= new TreeNode(6);
    TreeNode* r1= new TreeNode(8);
    root->left=l1;
    root->right=r1;
    std::cout<<isHasTarget(root,130);
    return 0;
}