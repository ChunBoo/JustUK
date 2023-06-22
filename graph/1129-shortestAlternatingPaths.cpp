/**You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
You are given two arrays redEdges and blueEdges where:
redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
Example 1:
Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
Output: [0,1,-1]
*/
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
       vector<unordered_set<int>> edges_r(n);
       vector<unordered_set<int>> edges_b(n);

       for(const auto &e:redEdges)
        edges_r[e[0]].insert(e[1]);
    
       for(const auto &e:blueEdges)
        edges_b[e[0]].insert(e[1]);
    
       unordered_set<int> seen_r,seen_b;
       queue<pair<int,int>> q{};  //node,color
       q.push({0,0});
       q.push({0,1});
       seen_b.insert(0);
       seen_r.insert(0);
       int steps=0;
       vector<int> ans(n,-1);
       while(!q.empty()){
        size_t size=q.size();
        while(size--){
            int node=q.front().first,color=q.front().second;
            q.pop();
            ans[node]=ans[node]>=0?min(steps,ans[node]):steps;
            const auto &edges=color==0?edges_r:edges_b;
            auto &seen=color==0?seen_r:seen_b;
            for(auto &next:edges[node]){
                if(seen.count(next)) continue;
                seen.insert(next);
                q.push({next,1-color});
            }
        }
        ++steps;

       }
       return ans;
    }
};

int main()
{
    int  n = 3;
    vector<vector<int>> redEdges = {{0,1},{1,2}}, blueEdges = {};
    vector<int> ans=Solution().shortestAlternatingPaths(n,redEdges,blueEdges);
    for(auto &v:ans)
        cout<<v<<',';
}

