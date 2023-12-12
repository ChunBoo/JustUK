
/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Example 1:

1
2
3
    2
   / \
  1   3
Binary tree [2,1,3], return true.

Example 2:

1
2
3
    1
   / \
  2   3
Binary tree [1,2,3], return false.

Solution 1
Traverse the tree and limit the range of each subtree and check whether root’s value is in the range.

Time complexity: O(n)

Space complexity: O(n)

Note: in order to cover the range of -2^31 ~ 2^31-1, we need to use long or nullable integer.


*/
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN,LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long min,long max)
    {
        if(!root)
            return true;
        if(root->val<=min||root->val>=max)
            return false;
        return isValidBST(root->left,min,root->val)&&isValidBST(root->right,root->val,max);
    }
};



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,nullptr,nullptr);
    }
private:
    bool isValidBST(TreeNode* root, int* min,int *max)
    {
        if(!root)   return true;
        if(min&&(root->val<=*min)||(max&&(root->val>=*max)))
            return false;
        return isValidBST(root->left, min,&root->val)&&
                isValidBST(root->right,&root->val,max);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev_=nullptr;
        return inorder(root);
    }
private:
    TreeNode* prev_;
    bool inorder(TreeNode* root)
    {
        if(!root)   return true;
        if(!inorder(root->left))
            return false;
        if(prev_&&root->val<=prev_->val)
            return false;
        prev_=root;
        return inorder(root->right);
    }
};