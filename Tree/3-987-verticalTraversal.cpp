/**
 * @file 3-987-verticalTraversal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-13
 * 
 * @copyright Copyright (c) 2024
 * 
 * Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;

        function<void(TreeNode*,int,int)> dfs=[&](TreeNode* node,int row,int col) {
            if(!node)
                return;
            nodes.emplace_back(col,row,node->val);
            dfs(node->left,row+1,col-1);
            dfs(node->right,row+1,col+1);
        };

        dfs(root,0,0);
        sort(nodes.begin(),nodes.end());

        vector<vector<int>> ans;

        int lastCol=INT_MIN;

        for(const auto& [col,row,value]:nodes)
        {
            if(col!=lastCol){
                lastCol=col;
                ans.emplace_back();
            }
            ans.back().push_back(value);
        }
        return ans;
    }

};