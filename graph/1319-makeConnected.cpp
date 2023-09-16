/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it’s not possible, return -1. 

Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
*/
#include <functional>
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (int(connections.size()) < n - 1)
      return -1;
    vector<vector<int>> g(n);
    for (const auto& c : connections) {  //create the un-directed graph
      g[c[0]].push_back(c[1]);
      g[c[1]].push_back(c[0]);
    }
    vector<int> seen(n);
    int count = 0;
    function<void(int)> dfs = [&](int cur) {
      for (int nxt : g[cur])
        if (!seen[nxt]++) dfs(nxt);      
    };
    for (int i = 0; i < n; ++i)
      if (!seen[i]++ && ++count)
        dfs(i);        
    return count - 1;
  }
};

int main() {
  int n = 4;
  vector<vector<int>> connections{{0, 1}, {0, 2}, {1, 2}};
  cout << Solution().makeConnected(n, connections);
}