/***
 * There is a company with n branches across the country, some of which are connected by roads. Initially, all branches are reachable from each other by traveling some roads.

The company has realized that they are spending an excessive amount of time traveling between their branches. As a result, they have decided to close down some of these branches (possibly none). However, they want to ensure that the remaining branches have a distance of at most maxDistance from each other.

The distance between two branches is the minimum total traveled length needed to reach one branch from another.

You are given integers n, maxDistance, and a 0-indexed 2D array roads, where roads[i] = [ui, vi, wi] represents the undirected road between branches ui and vi with length wi.

Return the number of possible sets of closing branches, so that any branch has a distance of at most maxDistance from any other.

Note that, after closing a branch, the company will no longer have access to any roads connected to it.

Note that, multiple roads are allowed.


Input: n = 3, maxDistance = 5, roads = [[0,1,2],[1,2,10],[0,2,10]]
Output: 5
Explanation: The possible sets of closing branches are:
- The set [2], after closing, active branches are [0,1] and they are reachable to each other within distance 2.
- The set [0,1], after closing, the active branch is [2].
- The set [1,2], after closing, the active branch is [0].
- The set [0,2], after closing, the active branch is [1].
- The set [0,1,2], after closing, there are no active branches.
It can be proven, that there are only 5 possible sets of closing branches.
 */

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> g(n,vector<int>(n,INT_MAX/2));

        for(auto& e:roads){
            g[e[0]][e[1]]=g[e[1]][e[0]]=min(g[e[0]][e[1]],e[2]);
        }

        vector<vector<int>> f(n);

        auto check=[&](int s)->bool{
            for(int i=0;i<n;i++){
                if((s>>i)&1){
                    f[i]=g[i];
                }
            }
        

            for(int k=0;k<n;k++){
                if(((s>>k)&1)==0){
                    continue;
                }
                for(int i=0;i<n;i++){
                    if(((s>>i)&1)==0)
                        continue;
                        for(int j=0;j<n;j++){
                            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                        }
                }
            }

            for(int i=0;i<n;i++){
                if(((s>>i)&1)==0) continue;
                for(int j=0;j<i;j++){
                    if((s>>j)&1&&f[i][j]>maxDistance){
                        return false;
                    }
                }
            }
            return true;
        };
        int ans=0;
        for(int s=0;s<(1<<n);s++){
            ans+=check(s);
        }
        return ans;
            
    }
};