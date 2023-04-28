/**
 * Definition for a binary tree node.
 */

#include<iostream>
#include "../treeNode.h"
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root2)
            return root1;
        if(!root1)
            return root2;
        root1->m_val+=root2->m_val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};

int main()
{
    TreeNode *r1=new TreeNode(1);
    TreeNode *left1=new TreeNode(2);
    TreeNode *right1=new TreeNode(3);
    
    r1->left=left1;
    r1->right=right1;

    TreeNode *r2=new TreeNode(1);
    TreeNode *left2=new TreeNode(2);
    TreeNode *right2=new TreeNode(3);
    
    r2->left=left2;
    r2->right=right2;

    TreeNode *nr=Solution().mergeTrees(r1,r2);

    TreeNode::printTreeInOrder(nr);
    std::cout<<'\n';
    TreeNode::printTreeNodePreOrder(nr);
}
