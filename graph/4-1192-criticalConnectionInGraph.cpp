/**
 * There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.
Solution: Tarjan
Time complexity: O(v+e)
Space complexity: O(v+e)
*/

// class Solution {
// public:
//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         vector<vector<int>> g(n);
//         vector<int> ts(n,INT_MAX);
//         vector<vector<int>> ans;
//         int t=0;
//         function<int(int,int)> tarjan=[&](int i,int p){
//             int min_i=ts[i]=++t;
//             for(int j:g[i]){
//                 if(ts[j]==INT_MAX){
//                     int min_j=tarjan(j,i);
//                     if(ts[i]<min_j)
//                         ans.push_back({i,j});
//                 }
//                 else if(j!=p)
//                     min_i=min(min_i,ts[j]);
//                             }
//                             return min_i;
//         };
//         for(const auto& e:connections)
//         {
//             g[e[0]].push_back(e[1]);
//             g[e[1]].push_back(e[0]);
//         }
//         tarjan(0,-1);
//         return ans;
//     }
// };

class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> g(n);
    vector<int> ts(n, INT_MAX);
    vector<vector<int>> ans;
    int t = 0;
    
    function<int(int, int)> tarjan = [&](int i, int p) {
      int min_i = ts[i] = ++t;
      for (int j : g[i]) {
        if (ts[j] == INT_MAX) {
          int min_j = tarjan(j, i);
          min_i = min(min_i, min_j);
          if (ts[i] < min_j)
            ans.push_back({i, j});
        } else if (j != p) {
          min_i = min(min_i, ts[j]);
        }
      }
      return min_i;
    };
    
    for (const auto& e : connections) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    
    tarjan(0, -1);
    return ans;
  }
};