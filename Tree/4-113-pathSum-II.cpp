/*Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

1
2
3
4
5
6
7
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

1
2
3
4
[
   [5,4,11,2],
   [5,8,4,5]
]
Idea:
Recursion
Solution:
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        pathSum(root, sum, curr, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr) {
            if(root->val == sum) {
                ans.push_back(curr);
                ans.back().push_back(root->val);
            }
            return;
        }
        
        curr.push_back(root->val);
        int new_sum = sum - root->val;
        pathSum(root->left, new_sum, curr, ans);
        pathSum(root->right, new_sum, curr, ans);
        curr.pop_back();
    }
};