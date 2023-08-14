/**
 * Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*,vector<TreeNode*>> g;
    void buildGraph(TreeNode* parent,TreeNode* child)
    {
        if(parent){
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left) buildGraph(child,child->left);
        if(child->right) buildGraph(child,child->right);
    }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(nullptr,root);
        vector<int> ans;
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        seen.insert(target);
        q.push(target);

        int k_=0;
        while(!q.empty()&&k_<=k){
            int s=q.size();
            while(s--){
                TreeNode* node=q.front();q.pop();
                if(k==k_) ans.push_back(node->val);
                for(TreeNode* child:g[node]){
                    if(seen.count(child)) continue;
                    q.push(child);
                    seen.insert(child);
                }
            }
            ++k_;
        }
        return ans;
    }
};