/***
 * You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:


Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.
 */


class Solution {
public:
    using LL=long long;
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int n=bombs.size();
        auto isConnected=[&](int u,int v)->bool{
            long long dx=bombs[u][0]-bombs[v][0];
            long long dy=bombs[u][1]-bombs[v][1];
            return (LL)bombs[u][2]*bombs[u][2]>=dx*dx+dy*dy;
        };
        
        unordered_map<int,vector<int>> edges;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected(i,j)){
                    edges[i].push_back(j);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> visited(n);
            int cnt=1;
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int cidx=q.front();
                q.pop();
                for(const int nidx:edges[cidx]){
                    if(visited[nidx]){
                        continue;
                    }
                    cnt+=1;
                    q.push(nidx);
                    visited[nidx]=1;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};