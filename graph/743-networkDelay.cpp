/**
 * You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/
//bell-man
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        constexpr int MAX_TIME=101*100;
        vector<int> dist(n,MAX_TIME);
        dist[k-1]=0;
        for(int i=1;i<n;++i){
            for(const auto& time:times){
                int u=time[0]-1,v=time[1]-1,w=time[2];
                dist[v]=min(dist[v],dist[u]+w);
            }
        }
        int max_dist=*max_element(dist.begin(),dist.end());
        return max_dist==MAX_TIME?-1:max_dist;
    }
};
//Floyd-warshall-allpairs
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        constexpr int MAX_TIME=101*100;
        vector<vector<int>> d(n,vector<int>(n,MAX_TIME));

        for(auto time:times)
            d[time[0]-1][time[1]-1]=time[2];
        
        for(int i=0;i<n;++i)
            d[i][i]=0;

        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        
        int ans=INT_MIN;
        for(int i=0;i<n;++i)
        {
            if(d[k-1][i]>=MAX_TIME) return -1;
            ans=max(ans,d[k-1][i]);
        }
        return ans;
    }
};