class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        int cnt=32-__builtin_clz(n);//get the first position of non-zero number
        parents.resize(n,vector<int>(cnt,-1));

        for(int i=0;i<n;i++){
            parents[i][0]=parent[i];
        }

        for(int i=0;i<cnt-1;i++){
            for(int x=0;x<n;x++){
                int p=parents[x][i];
                if(p!=-1)
                    parents[x][i+1]=parents[p][i];
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        int m=32-__builtin_clz(k);
        for(int i=0;i<m;i++){
            if(k>>i&1)
            {
                node=parents[node][i];
                if(node<0)
                    break;
            }

        }
        return node;
    }
private:
    vector<vector<int>> parents;

};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


/**
 * @brief 
 * 最暴力的做法是，从 node\textit{node}node 出发，一步一步地往上跳，即

node→parent[node]→parent[parent[node]]→⋯\textit{node} \rightarrow \textit{parent}[\textit{node}] \rightarrow \textit{parent}[\textit{parent}[\textit{node}]] \rightarrow \cdots
node→parent[node]→parent[parent[node]]→⋯
需要跳 kkk 次才能到达 node\textit{node}node 的第 kkk 个祖先节点，时间复杂度为 O(k)\mathcal{O}(k)O(k)。

如何优化这个暴力算法呢？

一个初步的想法是，预处理出每个节点的「爷爷节点」，即父节点的父节点，那么就可以两步两步地往上跳，从而减少一半的跳跃次数（循环次数）。

进一步地，再预处理出爷爷节点的爷爷节点，就可以四步四步地往上跳。

请你思考：一般地，要预处理出哪些节点呢？如何利用这些预处理出的节点，快速地找到第 kkk 个祖先节点？

二、解惑
预处理出每个节点的第 2i2^i2 
i
  个祖先节点，即第 1,2,4,8,⋯1,2,4,8,\cdots1,2,4,8,⋯ 个祖先节点（其中 xxx 的第 111 个祖先节点就是 parent[x]\textit{parent}[x]parent[x]）。由于任意 kkk 可以分解为若干不同的 222 的幂（例如 13=8+4+113=8+4+113=8+4+1），所以只需要预处理出这些 2i2^i2 
i
  祖先节点，就可以快速地到达任意第 kkk 个祖先节点。

例如 k=13=8+4+1=1101(2)k=13=8+4+1=1101_{(2)}k=13=8+4+1=1101 
(2)
​
 ，我们可以先往上跳 888 步，再往上跳 444 步和 111 步；也可以先往上跳 111 步，再往上跳 444 步和 888 步。无论如何跳，都只需要跳 333 次就能到达第 131313 个祖先节点。

据此，可以得到下面的算法。

三、算法
在构造函数 TreeAncestor\texttt{TreeAncestor}TreeAncestor 中，预处理出每个节点 x\textit{x}x 的第 2i2^i2 
i
  个祖先节点，记作 pa[x][i]\textit{pa}[x][i]pa[x][i]（若第 2i2^i2 
i
  个祖先节点不存在，则 pa[x][i]=−1\textit{pa}[x][i]=-1pa[x][i]=−1）。计算方式如下：

先枚举 iii，再枚举 xxx。相当于先算出所有爷爷节点，再算出所有爷爷节点的爷爷节点，依此类推。
pa[x][0]=parent[x]\textit{pa}[x][0]=\textit{parent}[x]pa[x][0]=parent[x]，即父节点。
pa[x][1]=pa[pa[x][0]][0]\textit{pa}[x][1]=\textit{pa}[\textit{pa}[x][0]][0]pa[x][1]=pa[pa[x][0]][0]，即爷爷节点。
依此类推，pa[x][i+1]=pa[pa[x][i]][i]\textit{pa}[x][i+1]=\textit{pa}[\textit{pa}[x][i]][i]pa[x][i+1]=pa[pa[x][i]][i]，表示 xxx 的第 2i2^i2 
i
  个祖先节点的第 2i2^i2 
i
  个祖先节点就是 xxx 的第 2i+12^{i+1}2 
i+1
  个祖先节点。特别地，如果 pa[x][i]=−1\textit{pa}[x][i]=-1pa[x][i]=−1 则 pa[x][i+1]=−1\textit{pa}[x][i+1]=-1pa[x][i+1]=−1。
这里 i+1i+1i+1 至多为 ⌊log⁡2n⌋\left\lfloor\log_2 n \right\rfloor⌊log 
2
​
 n⌋。例如 n=13n=13n=13 时，⌊log⁡213⌋=3\left\lfloor\log_2 13 \right\rfloor=3⌊log 
2
​
 13⌋=3，至多需要预处理到第 232^32 
3
  个祖先节点。（当然，你也可以先把树高，或者每个节点的深度求出来，再据此做精细地计算。）
对于 getKthAncestor\texttt{getKthAncestor}getKthAncestor，需要找到 kkk 的二进制表示中的所有 111（相当于把 kkk 分解为若干 2i2^i2 
i
 ）。可以从小到大枚举 iii，如果 kkk 右移 iii 位后的最低位为 111，就说明 kkk 的二进制从低到高第 iii 位是 111，那么往上跳 2i2^i2 
i
  步，将 node\textit{node}node 更新为 pa[node][i]\textit{pa}[\textit{node}][i]pa[node][i]。如果 node=−1\textit{node}=-1node=−1 则说明第 kkk 个祖先节点不存在。
kth-ancestor-of-a-tree-node/solutions/2305895/mo-ban-jiang-jie-shu-shang-bei-zeng-suan-v3rw
 * 
 */