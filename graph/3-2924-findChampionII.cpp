/**
 * @brief 
 * There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.

You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.

A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.

Team a will be the champion of the tournament if there is no team b that is stronger than team a.

Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.

Notes

A cycle is a series of nodes a1, a2, ..., an, an+1 such that node a1 is the same node as node an+1, the nodes a1, a2, ..., an are distinct, and there is a directed edge from the node ai to node ai+1 for every i in the range [1, n].
A DAG is a directed graph that does not have any cycle.
 * 
 */

// class Solution {
// public:
//     int findChampion(int n, vector<vector<int>>& edges) {
//         vector<int> inDegree(n,0);

//         const int m = edges.size();

//         for(int i=0;i<m;++i)
//         {
//             vector<int> cur=edges[i];
//             inDegree[cur[1]]++;
//         }

//         int count=0;
//         int ans=0;
//         for(int i=0;i<n;++i)
//         {
//             if(inDegree[i]==0)
//             {
//                 count++;
//                 ans=i;
//             }
//         }
//         return count>1?-1:ans;
//     }
// };

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        for (auto e : edges) {
            degree[e[1]]++;
        }
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                if (champion == -1) {
                    champion = i;
                } else {
                    return -1;
                }
            }
        }
        return champion;
    }
};

