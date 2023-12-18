/**
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

1
2
3
4
5
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans_;
    }
private:
    vector<int> ans_;
    int count_;
    int maxCount_;
    int val_;
    void inorder(TreeNode* root)
    {
        if(!root)   
          return ;
        inorder(root->left);
        visit(root->val);
        inorder(root->right);
    }
    void visit(int val)
    {
        if(count_>0&&(val_==val))
        {
            count_++;
        }
        else
        {
            val_=val;
            count_=1;
        }
        if(count_>maxCount_)
        {
            maxCount_=count_;
            ans_.clear();
        }
        if(count_==maxCount_)
        {
            ans_.push_back(val);
        }
    }
};


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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        modeCount_=maxCount_;
        count_ = 0;
        inorder(root);
        return ans_;
    }
private:
    vector<int> ans_;
    int maxCount_=0;
    int modeCount_=INT_MAX;
    int val_=0;
    int count_=0;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        visit(root->val);
        inorder(root->right);
    }
    void visit(int val)
    {
        if(count_>0&&(val==val_))
            ++count_;
        else
        {
            count_=1;
            val_=val;
        }
        if(count_>maxCount_)
        {
            maxCount_=count_;
        }
        if(count_==modeCount_)
            ans_.push_back(val);
    }
};