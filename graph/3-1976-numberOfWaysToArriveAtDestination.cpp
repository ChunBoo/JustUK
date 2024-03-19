/**
 * @file 3-1976-numberOfWaysToArriveAtDestination.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-05
 * 
 * @copyright Copyright (c) 2024
 * You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:
 * 
 */


class Solution {
public:
    using LL=long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long MOD=1E9+7;
        vector<vector<pair<int,int>>> e(n);

        for(const auto& road:roads){
            int x=road[0],y=road[1],t=road[2];
            e[x].emplace_back(y,t);
            e[y].emplace_back(x,t);
        }

        vector<LL> dist(n,LLONG_MAX);
        vector<LL> paths(n);

        priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> q;
        q.emplace(0,0);

        dist[0]=0;
        paths[0]=1;

        while(!q.empty()){
            auto [t,u]=q.top();
            q.pop();
            if(t>dist[u])
                continue;
            for(auto &[v,w]:e[u]){
                if(t+w<dist[v]){
                    dist[v]=t+w;
                    paths[v]=paths[u];
                    q.emplace(t+w,v);
                }
                else if(t+w==dist[v])
                    paths[v]=(paths[u]+paths[v])%MOD;
            }
        
        }
        return paths[n-1];
    }
};