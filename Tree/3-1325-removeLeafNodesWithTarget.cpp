/**
 * Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if it’s parent node becomes a leaf node and has the value target,
 it should also be deleted (you need to continue doing that until you can’t).
*/

/**
  Definition for a binary tree node.*/

#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)
            return root;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->val==target && !root->left&&!root->right)
        {
            delete root;
            return nullptr;
        }
        return root;
    }
};

int main()
{
    TreeNode* root=new TreeNode(1);
    TreeNode* left=new TreeNode(1);
    TreeNode* right=new TreeNode(1);
    root->left=left;
    root->right=right;
    TreeNode* res=Solution().removeLeafNodes(root,1);
    if(res) cout<<res->val;
}