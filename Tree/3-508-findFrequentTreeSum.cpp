/**
 * Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

1
2
3
  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.

Examples 2
Input:

1
2
3
  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.

Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.

 
 * 
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        int maxCnt=0;
        for(auto &[k,v]:count_)
        {
            if(v>maxCnt)
            {
                maxCnt=v;
            }
        }

        for(auto &[k,v]:count_)
        {
            if(v==maxCnt)
                ans.push_back(k);
        }
        return ans;
    }
private:
    unordered_map<int,int> count_;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int sum=root->val+l+r;
        ++count_[sum];
        return sum;
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int freq=-1;
        unordered_map<int,int> count;
        sumTree(root,ans,freq,count);
        return ans;
    }
    int sumTree(TreeNode* root,vector<int>& ans,int& freq,unordered_map<int,int>& cnt)
    {
        if(!root)
            return 0;
        int sum=root->val+sumTree(root->left,ans,freq,cnt)
                +sumTree(root->right,ans,freq,cnt);
        ++cnt[sum];
        if(cnt[sum]>freq)
        {
            freq=cnt[sum];
            ans.clear();
        }
        if(cnt[sum]==freq)
            ans.push_back(sum);
        return sum;
    }
};