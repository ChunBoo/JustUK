/****
 * There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

 

Example 1:


Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.
Example 2:
 */


class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
          int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge: edges) {
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        vector<int> visited(n);
        visited[0] = true;
        int ans = 0;
        
        function<void(int, int, int)> dfs = [&](int u, int time, int value) {
            if (u == 0) {
                ans = max(ans, value);
            }
            for (const auto& [v, dist]: g[u]) {
                if (time + dist <= maxTime) {
                    if (!visited[v]) {
                        visited[v] = true;
                        dfs(v, time + dist, value + values[v]);
                        visited[v] = false;
                    }
                    else {
                        dfs(v, time + dist, value);
                    }
                }
            }
        };
        
        dfs(0, 0, values[0]);
        return ans;


    }
};