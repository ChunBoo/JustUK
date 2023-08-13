/**
 * In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.
 * 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    private:
    enum State{UNKNOWN,VISITING,SAFE,UNSAFE};
    State dfs(const vector<vector<int>>& g,int cur,vector<State>& states){
        if(states[cur]==VISITING)
            return UNSAFE;
        if(states[cur]!=UNKNOWN)
            return states[cur];
        states[cur]=VISITING;
        for(int nxt:g[cur])
            if(dfs(g,nxt,states)==UNSAFE)
                return states[cur]=UNSAFE;
        return states[cur]=SAFE;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<State> s{graph.size(),UNKNOWN};
        vector<int> ans;
        for(int i=0;i<int(graph.size());++i){
            if(dfs(graph,i,s)==SAFE)
                ans.push_back(i);
        }
        std::sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    vector<vector<int>> graph= {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> res=Solution().eventualSafeNodes(graph);
    for(auto v:res)
        cout<<v<<',';
}