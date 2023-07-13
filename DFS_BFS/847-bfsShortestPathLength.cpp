/**
 * You have an undirected, connected graph of n nodes labeled from 0 to n - 1.
You are given an array graph where graph[i] is a list of all the nodes connected
with node i by an edge.

Return the length of the shortest path that visits every node. You may start and
stop at any node, you may revisit nodes multiple times, and you may reuse edges.
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
*/
#include <iostream>
#include <queue>
#include <vector>


using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n=graph.size();
        const int kAns=(1<<n)-1;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(1<<n));
        for(int i=0;i<n;++i)
            q.push({i,1<<i});
        int steps=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto p=q.front();
                q.pop();
                int node=p.first;
                int sts=p.second;
                if(sts==kAns) 
                  return steps;
                if(visited[node][sts]) continue;
                visited[node][sts]=1;
                cout << "visited Node: " << node << '\n';
                for(int nxt:graph[node])
                    q.push({nxt,sts|(1<<nxt)});
            }
            ++steps;
        }
        return -1;
    }
};

int main() {

  vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
  cout << Solution().shortestPathLength(graph);
}