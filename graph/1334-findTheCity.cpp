/**
 * There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX/2));
        for(const auto& e:edges)
            dp[e[0]][e[1]]=dp[e[1]][e[0]]=e[2];
        
        for(int k=0;k<n;++k)
            for(int u=0;u<n;++u)
                for(int v=0;v<n;++v)
                    dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
        int ans=-1;
        int min_nb=INT_MAX;
        for(int u=0;u<n;++u){
            int nb=0;
            for(int v=0;v<n;++v)
                if(v!=u&&dp[u][v]<=distanceThreshold) 
                  ++nb;
            if(nb<=min_nb){
                min_nb=nb;
                ans=u;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> g(n);
        for(const auto&e:edges){
            g[e[0]].emplace_back(e[1],e[2]);
            g[e[1]].emplace_back(e[0],e[2]);
        }
        //return the  number of nodes within t from s.
        auto dijkstra=[&](int s){
            vector<int> dist(n,INT_MAX/2);
            set<pair<int,int>> q;  //<dist,node>
            vector<set<pair<int,int>>::const_iterator> its(n);
            dist[s]=0;
            for(int i=0;i<n;++i)
                its[i]=q.emplace(dist[i],i).first;
            while(!q.empty()){
                auto it=cbegin(q);
                int d=it->first;
                int u=it->second;
                q.erase(it);

                if(d>distanceThreshold) break;
                for(const auto&p:g[u]){
                    int v=p.first;
                    int w=p.second;
                    if(dist[v]<=d+w) continue;
                    //decrease key
                    q.erase(its[v]);
                    its[v] = q.emplace(dist[v] = d + w, v).first;
                }
            }
            return count_if(begin(dist),end(dist),[distanceThreshold](int d){return d<=distanceThreshold;});
            };
            int ans=-1;
            int min_nb=INT_MAX;
            for(int i=0;i<n;++i){
                int nb=dijkstra(i);
                if(nb<=min_nb){
                    min_nb=nb;
                    ans=i;
                }
            }
            return ans;
    }
};