/**
 * The Bellman-Ford algorithm is a graph search algorithm that finds the shortest path from a source vertex to all other vertices in a weighted graph. It's especially useful for graphs that contain negative weight edges, as many other shortest path algorithms (like Dijkstra's) don't handle these correctly.

The algorithm works by iteratively relaxing the distances to vertices, starting from the source. It does this for |V|-1 times, where |V| is the number of vertices in the graph. After these iterations, if the algorithm can still relax any edges, it means there's a negative cycle in the graph.

Here's a basic pseudocode representation of the Bellman-Ford algorithm:
function BellmanFord(graph, source):
    distance[source] = 0
    for each vertex v in graph:
        if v is not source:
            distance[v] = infinity
            predecessor[v] = undefined

    for i from 1 to size(vertices)-1:
        for each edge (u, v) with weight w in edges:
            if distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
                predecessor[v] = u

    for each edge (u, v) with weight w in edges:
        if distance[u] + w < distance[v]:
            error "Graph contains a negative-weight cycle"
The time complexity of the Bellman-Ford algorithm is O(|V||E|), where |V| is the number of vertices and |E| is the number of edges in the graph. This makes it less efficient than Dijkstra's for graphs without negative weight edges, but it's the best option when negative weights are present.
*/


/**
 * There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

1

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:
 
The cheapest price from city <code>0</code> to city <code>2</code> with at most 1 stop costs 200, as marked red in the picture.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        constexpr int InfTime=1e9;
        vector<vector<int>> d(k+2,vector<int>(n,InfTime));
        d[0][src]=0;
        for(int i=1;i<=k+1;++i){
            d[i][src]=0;
            for(const auto& p:flights){
                d[i][p[1]]=min(d[i][p[1]],d[i-1][p[0]]+p[2]);
            }
        }
        return d[k+1][dst]==InfTime?-1:d[k+1][dst];
    }   
};