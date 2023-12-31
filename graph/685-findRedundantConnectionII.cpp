/**
 * In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, …, N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:

1
2
3
4
5
6
7
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2--&gt;3
Example 2:


Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 &lt;- 1 -&gt; 2
     ^    |
     |    v
     4 &lt;- 3
Note:

 

The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.


Idea:

Union Find


*/

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        vector<int> parents(edges.size() + 1, 0);
        vector<int> roots(edges.size() + 1, 0);       
        vector<int> sizes(edges.size() + 1, 1);
        
        vector<int> ans1;
        vector<int> ans2;
        
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // A node has two parents
            if (parents[v] > 0) {
                ans1 = {parents[v], v};
                ans2 = edge;
                
                // Delete the later edge
                edge[0] = edge[1] = -1;
            }
            
            parents[v] = u;
        }
        
        for(const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            // Invalid edge (we deleted in step 1)
            if (u < 0 || v < 0) continue;
            
            if (!roots[u]) roots[u] = u;
            if (!roots[v]) roots[v] = v;
            int pu = find(u, roots);
            int pv = find(v, roots);
            
            // Both u and v are already in the tree
            if (pu == pv)
                return ans1.empty() ? edge : ans1;
            
            // Unoin, always merge smaller set (pv) to larger set (pu)
            if (sizes[pv] > sizes[pu])
                swap(pu, pv);
            
            roots[pv] = pu;
            sizes[pu] += sizes[pv];
        }
        
        return ans2;
    }
    
private:
    int find(int node, vector<int>& roots) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
};