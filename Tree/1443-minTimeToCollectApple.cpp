/*
Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // vector<vector<int>> g(n);
        // for(const auto& e:edges)
        //     g[e[0]].push_back(e[1]);
        
        // function<int(int)> dfs=[&](int cur){
        //     int total=0;
        //     for(int c:g[cur]){
        //         int cost=dfs(c);
        //         if(cost>0||hasApple[c])
        //             total+=2+cost;
        //     }
        //     return total;
        // };
        // return dfs(0);
        vector<vector<int>> g(n);
        for(const auto& e:edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> seen(n);
        function<int(int)> dfs=[&](int cur){
            seen[cur]=1;
            int total=0;
            for(int c:g[cur]){
                if(seen[c]) continue;
                int cost=dfs(c);
                if(cost>0||hasApple[c])
                    total+=2+cost;
            }
            return total;
        };
        return dfs(0);
    }
};