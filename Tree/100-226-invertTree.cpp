/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "treeNode.h"
#include <iostream>
using std::cout;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode *right=root->right;
        root->right=invertTree(root->left);
        root->left=invertTree(right);
        return root;
    }
};

int main()
{
    TreeNode *one=new TreeNode(1);
    TreeNode *two=new TreeNode(2);
    TreeNode *three=new TreeNode(3);
    TreeNode *four=new TreeNode(4);
    TreeNode *five=new TreeNode(5);

    one->left=two;
    one->right=three;
    two->left=four;
    three->right=five;

    TreeNode::printTreeNodePreOrder(one);
    
    TreeNode *res=Solution().invertTree(one);
    cout<<'\n';
    TreeNode::printTreeNodePreOrder(res);


}