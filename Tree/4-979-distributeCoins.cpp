/**
 * Given the root of a binary tree with N nodes, each node in the tree has node.valcoins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.

Example 1:


Solution: Recursion
Compute the balance of left/right subtree, ans += abs(balance(left)) + abs(balance(right))
balance(root) = balance(left) + balance(right) + root.val – 1

Time complexity: O(n)
Space complexity: O(n)
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
    int distributeCoins(TreeNode* root) {
        int ans=0;
        balance(root,ans);
        return ans;
    }
private:
    int balance(TreeNode* root, int& ans){
        if(!root)   
            return 0;
        int l=balance(root->left,ans);
        int r=balance(root->right,ans);
        ans+=abs(l)+abs(r);
        return l+r+root->val-1;
    }
};