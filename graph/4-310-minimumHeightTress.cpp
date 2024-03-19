/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
题目中给定的含有 nnn 个节点的树，可以推出含有以下特征：

任意两个节点之间有且仅有一条路径；
树中的共有 n−1n-1n−1 条不同的边；
叶子节点的度为 111，非叶子节点的度至少为 222；
树的高度由根节点到叶子节点的最大距离决定。
最直接的解法是，枚举以每个节点为根构成的树，然后求出该树的高度，所有树的最小高度即为答案，需要的时间复杂度为 O(n2)O(n^2)O(n 
2
 )，在此不再描述。

设 dist[x][y]\textit{dist}[x][y]dist[x][y] 表示从节点 xxx 到节点 yyy 的距离，假设树中距离最长的两个节点为 (x,y)(x,y)(x,y)，它们之间的距离为 maxdist=dist[x][y]\textit{maxdist} = \textit{dist}[x][y]maxdist=dist[x][y]，则可以推出以任意节点构成的树最小高度一定为 minheight=⌈maxdist2⌉\textit{minheight} = \Big \lceil \dfrac{\textit{maxdist}}{2} \Big \rceilminheight=⌈ 
2
maxdist
​
 ⌉，且最小高度的树根节点一定在 节点 xxx 到节点 yyy 的路径上。

首先证明树的高度一定为 minheight=⌈maxdist2⌉\textit{minheight} = \Big \lceil \dfrac{\textit{maxdist}}{2} \Big \rceilminheight=⌈ 
2
maxdist
​
 ⌉，可以用反证法证明，假设存在节点 zzz，以节点 zzz 为根的树的高度 h<minheighth < \textit{minheight}h<minheight，则可以推出：

如果节点 zzz 存在于从 xxx 到 yyy 的路径上，由于 xxx 与 yyy 均为叶子节点，则可以知道 xxx 到 zzz 距离与 yyy 到 zzz 距离均小于 minheight\textit{minheight}minheight，dist[x][y]=dist[x][z]+dist[z][y]≤2×⌈dist[x][y]2⌉−2<dist[x][y]\textit{dist}[x][y] = \textit{dist}[x][z] + \textit{dist}[z][y] \le 2 \times \Big \lceil \dfrac{\textit{dist}[x][y]}{2} \Big \rceil - 2 < \textit{dist}[x][y]dist[x][y]=dist[x][z]+dist[z][y]≤2×⌈ 
2
dist[x][y]
​
 ⌉−2<dist[x][y]，这与 xxx 到 yyy 的距离为 dist[x][y]\textit{dist}[x][y]dist[x][y] 相矛盾；

如果节点 zzz 不存在于 xxx 到 yyy 的路径上，假设 zzz 到 xxx 的路径为 z→⋯→a→⋯→xz \rightarrow \cdots \rightarrow a \rightarrow \cdots \rightarrow xz→⋯→a→⋯→x，zzz 到 yyy 的路径为 z→⋯→a→⋯→yz \rightarrow \cdots \rightarrow a \rightarrow \cdots \rightarrow yz→⋯→a→⋯→y，这两个路径之间一定存在公共的交叉点，假设交叉点为 aaa，则可以知道此时 zzz 到 xxx 的距离为 dist[z][x]=dist[z][a]+dist[a][x]\textit{dist}[z][x] = \textit{dist}[z][a] + \textit{dist}[a][x]dist[z][x]=dist[z][a]+dist[a][x]，zzz 到 yyy 的距离为 dist[z][y]=dist[z][a]+dist[a][y]\textit{dist}[z][y] = \textit{dist}[z][a] + \textit{dist}[a][y]dist[z][y]=dist[z][a]+dist[a][y]，由于树的高度小于 h<minheighth < \textit{minheight}h<minheight，所以可以推出 dist[z][a]+dist[a][x]<minheight\textit{dist}[z][a] + \textit{dist}[a][x] < \textit{minheight}dist[z][a]+dist[a][x]<minheight，dist[z][a]+dist[a][y]<minheight\textit{dist}[z][a] + \textit{dist}[a][y] < \textit{minheight}dist[z][a]+dist[a][y]<minheight，即可以推出 dist[a][x]+dist[a][y]≤2×minheight−2=2×⌈dist[x][y]2⌉−2<dist[x][y]\textit{dist}[a][x] + \textit{dist}[a][y] \le 2 \times \textit{minheight} - 2 = 2 \times \Big \lceil \dfrac{\textit{dist}[x][y]}{2} \Big \rceil - 2 < \textit{dist}[x][y]dist[a][x]+dist[a][y]≤2×minheight−2=2×⌈ 
2
dist[x][y]
​
 ⌉−2<dist[x][y]，这与 xxx 到 yyy 的距离为 dist[x][y]\textit{dist}[x][y]dist[x][y] 相矛盾；

其次证明最小高度树的根节点一定存在于 xxx 到 yyy 的路径上，假设存在节点 zzz 它的最小高度为 minheight\textit{minheight}minheight，但节点 zzz 不存在于 xxx 到 yyy 之间的路径上：

设 zzz 到 xxx 的路径为 z→⋯→a→⋯→xz \rightarrow \cdots \rightarrow a \rightarrow \cdots \rightarrow xz→⋯→a→⋯→x，zzz 到 yyy 的路径为 z→⋯→a→⋯→yz \rightarrow \cdots \rightarrow a \rightarrow \cdots \rightarrow yz→⋯→a→⋯→y，这两个路径之间一定存在公共的交叉点，假设交叉点为 aaa, 则可以知道此时 zzz 到 xxx 的距离为 dist[z][x]=dist[z][a]+dist[a][x]\textit{dist}[z][x] = \textit{dist}[z][a] + \textit{dist}[a][x]dist[z][x]=dist[z][a]+dist[a][x]，zzz 到 yyy 的距离为 dist[z][y]=dist[z][a]+dist[a][y]\textit{dist}[z][y] = \textit{dist}[z][a] + \textit{dist}[a][y]dist[z][y]=dist[z][a]+dist[a][y]，由于树的高度小 h=minheighth = \textit{minheight}h=minheight，所以可以推出 dist[z][a]+dist[a][x]≤minheight\textit{dist}[z][a] + \textit{dist}[a][x] \le \textit{minheight}dist[z][a]+dist[a][x]≤minheight，dist[z][a]+dist[a][y]≤minheight\textit{dist}[z][a] + \textit{dist}[a][y] \le \textit{minheight}dist[z][a]+dist[a][y]≤minheight，由于 zzz 不在 xxx 到 yyy 的路径上，所以可以知道 dist[z][a]≥1\textit{dist}[z][a] \ge 1dist[z][a]≥1，即可以推出 dist[a][x]<minheight，dist[a][y]<minheight\textit{dist}[a][x] < \textit{minheight}，\textit{dist}[a][y] < \textit{minheight}dist[a][x]<minheight，dist[a][y]<minheight，即可以推出 dist[a][x]+dist[a][y]≤2×minheight−2=2×⌈dist[x][y]2⌉−2<dist[x][y]\textit{dist}[a][x] + \textit{dist}[a][y] \le 2 \times \textit{minheight} - 2 = 2 \times \Big \lceil \dfrac{\textit{dist}[x][y]}{2} \Big \rceil - 2 < \textit{dist}[x][y]dist[a][x]+dist[a][y]≤2×minheight−2=2×⌈ 
2
dist[x][y]
​
 ⌉−2<dist[x][y]，这与 xxx 到 yyy 的距离为 dist[x][y]\textit{dist}[x][y]dist[x][y] 相矛盾。
综合上述推理，设两个叶子节点的最长距离为 maxdist\textit{maxdist}maxdist，可以得到结论最小高度树的高度为 ⌈maxdist2⌉\Big \lceil \dfrac{\textit{maxdist}}{2} \Big \rceil⌈ 
2
maxdist
​
 ⌉，且最小高度树的根节点一定存在其最长路径上。假设最长的路径的 mmm 个节点依次为 p1→p2→⋯→pmp_1 \rightarrow p_2 \rightarrow \cdots \rightarrow p_mp 
1
​
 →p 
2
​
 →⋯→p 
m
​
 ，最长路径的长度为 m−1m-1m−1，可以得到以下结论：

如果 mmm 为偶数，此时最小高度树的根节点为 pm2p_{\frac{m}{2}}p 
2
m
​
 
​
  或者 pm2+1p_{\frac{m}{2} + 1}p 
2
m
​
 +1
​
 ，且此时最小的高度为 m2\dfrac{m}{2} 
2
m
​
 ；

如果 mmm 为奇数，此时最小高度树的根节点为 pm+12p_{\frac{m+1}{2}}p 
2
m+1
​
 
​
 ，且此时最小的高度为 m−12\dfrac{m-1}{2} 
2
m−1
​
 。

因此我们只需要求出路径最长的两个叶子节点即可，并求出其路径的最中间的节点即为最小高度树的根节点。可以利用以下算法找到图中距离最远的两个节点与它们之间的路径：

以任意节点 ppp 出现，利用广度优先搜索或者深度优先搜索找到以 ppp 为起点的最长路径的终点 xxx；

以节点 xxx 出发，找到以 xxx 为起点的最长路径的终点 yyy；

xxx 到 yyy 之间的路径即为图中的最长路径，找到路径的中间节点即为根节点。

 
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        vector<int> parent(n,-1);
        //find the farest node which from node 0
        int x=findLongestNode(0,parent,adj);
        //find the farest node which from node x
        int y=findLongestNode(x,parent,adj);
        //findout the path between node x and y
        vector<int> path;
        parent[x]=-1;
        while(y!=-1){
            path.emplace_back(y);
            y=parent[y];
        }
        int m=path.size();
        // return (m%2==0)?{path[m/2-1],path[m/2]}:{path[m/2]}; // error: initializer list cannot be used on the right hand side of operator '?'
        if(m%2==0)
            return {path[m/2-1],path[m/2]};
        else
            return {path[m/2]};
    }
private:
    int findLongestNode(int s,vector<int>& parent, vector<vector<int>>& adj){
        const int n=adj.size();
        queue<int> q;
        vector<bool> seen(n);
        q.emplace(s);
        seen[s]=true;
        int node=-1;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            node=curr;
            for(auto &v:adj[curr]){
                if(!seen[v]){
                    seen[v]=true;
                    parent[v]=curr;
                    q.emplace(v);
                }
            }
        }
        return node;
    }
};