
/**You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

 

Example 1:

Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
Output: 5
Explanation: The optimal path from (1,1) to (4,5) is the following:
- (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -> (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.
Example 2:

Input: start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
Output: 7
Explanation: It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
 * 
 * 
*/
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        unordered_map<long,int> ids;
        vector<pair<int,int>> pos;
        vector<vector<pair<int,int>>> g;

        auto getId=[&](int x,int y){
            const auto key=(unsigned long)x<<32|y;
            if(ids.count(key)) return ids[key];
            const int id=ids.size();
            ids[key]=id;
            pos.emplace_back(x,y);
            return id;
        };
        const int s=getId(start[0],start[1]);
        const int t=getId(target[0],target[1]);

        auto addEdge=[&](int x1,int y1,int x2,int y2,int c=INT_MAX){
            int n1=getId(x1,y1),n2=getId(x2,y2);
            if(n1==n2) return ;//same points
            while(g.size()<=max(n1,n2)) g.push_back({});
            int cost=min(c,abs(x1-x2)+abs(y1-y2));
            g[n1].emplace_back(cost,n2);
            //directional for special edge
            if(c==INT_MAX) g[n2].emplace_back(cost,n1);
        };
        for(const auto& r:specialRoads)
            addEdge(r[0],r[1],r[2],r[3],r[4]);
        for(int i=0;i<pos.size();++i)
            for(int j=i+1;j<pos.size();++j)
                addEdge(pos[i].first,pos[i].second,pos[j].first,pos[j].second);
        
        vector<int> dist(ids.size(),INT_MAX);
        dist[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.emplace(0,s); 
        while(!q.empty()){
            auto [d,u]=q.top();
            q.pop();
            if(d>dist[u]) continue;
            if(u==t) return d;
            for(auto [c,v]:g[u])
                if(d+c<dist[v])
                    q.emplace(dist[v]=d+c,v);
        }
        return -1;
    }
};