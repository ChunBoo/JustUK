/**
 * @brief 
 * 一开始把所有 (i,0)(i,0)(i,0) 都加入一个列表。每一轮循环，遍历列表中的坐标，把右边这一列的能到达的格子坐标加入一个新列表。注意只有之前没入队的格子才能入队，可以用一个 vis\textit{vis}vis 数组，在入队前标记这个格子。

返回可以到达的最大列号，即为最大移动次数。


 */
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int rows=grid.size();
        const int cols=grid[0].size();
        vector<int> seen(rows,-1), q(rows);
        iota(begin(q),end(q),0);

        for(int c=0;c<cols-1;c++){
            vector<int> nxt;
            for(int r:q){
                for(int k=max(0,r-1);k<min(rows,r+2);++k){
                    if(seen[k]!=c&&grid[k][c+1]>grid[r][c])
                    {
                        seen[k]=c;
                        nxt.push_back(k);
                    }
                }
            }
            if(nxt.empty())
                return c;
            q=move(nxt);
        }
        return cols-1;
    }
};