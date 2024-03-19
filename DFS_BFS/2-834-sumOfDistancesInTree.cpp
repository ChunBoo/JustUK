/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.

*/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);  
        for(auto &e:edges){
            int x=e[0],y=e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> ans(n);
        vector<int> size(n,1);

        function<void(int,int,int)> dfs=[&](int x,int pa,int d){
            ans[0]+=d;
            for(int y:g[x]){
                if(y!=pa){
                    dfs(y,x,d+1);
                    size[x]+=size[y];
                }
            }
        };
        dfs(0,-1,0);

        function<void(int,int)> reroot=[&](int x,int pa){
            for(int y:g[x]){
                if(y!=pa){
                    ans[y]=ans[x]+n-2*size[y];
                    reroot(y,x);
                }
            }
        };
        reroot(0,-1);
        return ans;
    }
};