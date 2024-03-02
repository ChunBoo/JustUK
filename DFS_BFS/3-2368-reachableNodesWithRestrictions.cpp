/**
 * @brief There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.

Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
 * 
 */

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n,vector<int>());
        restricted_=vector<int>(n);
        for(auto x:restricted)
            restricted_[x]=1;
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans=0;
        dfs(0,-1,g,ans);
        return ans;
    }

private:
    vector<int> restricted_;
    void dfs(int s,int pre,const vector<vector<int>>& g, int &ans){
        ans++;
        for(auto &nb:g[s]){
          if(nb!=pre&&!restricted_[nb])
            dfs(nb,s,g,ans);
    }
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int> restricted = {4,5};
    cout<<Solution().reachableNodes(n,edges,restricted);
}