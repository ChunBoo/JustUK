/**
 * Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
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
    bool isCousins(TreeNode* root, int x, int y) {
        preOrder(root,x,y,nullptr,0);
        return (_px!=_py) &&(_dx==_dy);
    }
private:
    TreeNode* _px;
    TreeNode* _py;
    int _dx;
    int _dy;

    void preOrder(TreeNode* root,int x,int y,TreeNode* parent,int d)
    {
        if(!root) return;
        if(root->val==x)
        {
            _px=parent;
            _dx=d;
        }
        if(root->val==y)
        {
            _py=parent;
            _dy=d;
        }
        preOrder(root->left,x,y,root,d+1);
        preOrder(root->right,x,y,root,d+1);
    }
};