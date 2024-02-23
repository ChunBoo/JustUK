/**
 * @brief 
 * You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
 
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            long long tmp=0;
            while(sz--){
                TreeNode* cur=q.front();
                q.pop();
                tmp+=cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ans.push_back(tmp);
        }
        int sz=ans.size();
        //sort(ans.begin(),ans.end(),[](long long a, long long b) {
        //return a > b;});

        if(sz<k)
            return -1;
        sort(ans.begin(),ans.end());
        return *(ans.end()-k);
    }
};