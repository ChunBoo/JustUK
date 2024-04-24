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


/***
 * You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
*/
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> g;
        //create the graph
        dfs(g,root);
        queue<vector<int>> q;
        q.push({start,0});

        unordered_set<int> seen;
        seen.insert(start);
        int dis=0;
        while(!q.empty()){
            auto vals=q.front();
            q.pop();
            int nodeVal=vals[0];
            dis=vals[1];
            for(int child:g[nodeVal]){
                if(!seen.count(child)){
                    q.push({child,dis+1});
                    seen.insert(child);
                }
            }
        }
        return dis;

    }
private:
    void dfs(unordered_map<int,vector<int>>& g, TreeNode* root)
    {
        for(TreeNode* child:vector<TreeNode*>{root->left,root->right}){
            if(child)
            {
                g[root->val].push_back(child->val);
                g[child->val].push_back(root->val);
                dfs(g,child);
            }
        }
    }
};