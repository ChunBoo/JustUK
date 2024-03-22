/**
 * @brief You are given a 0-indexed m x n integer matrix grid. Your initial position is at the top-left cell (0, 0).

Starting from the cell (i, j), you can move to one of the following cells:

Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
Return the minimum number of cells you need to visit to reach the bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.

 

Example 1:


Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
Output: 4
Explanation: The image above shows one of the paths that visits exactly 4 cells.
 * 
 */

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));

        dist[0][0]=1;
        vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>> row(m),col(n); //two priority queues

        auto update=[](int& x,int y){
            if(x==-1||y<x)
                x=y;
        };

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                while(!row[r].empty()&&row[r].top().second+grid[r][row[r].top().second]<c)
                    row[r].pop();
                if(!row[r].empty())
                    update(dist[r][c],dist[r][row[r].top().second]+1);
                
                while(!col[c].empty()&&col[c].top().second+grid[col[c].top().second][c]<r)
                    col[c].pop();
                if(!col[c].empty())
                    update(dist[r][c],dist[col[c].top().second][c]+1);
                
                if(dist[r][c]!=-1)
                {
                    row[r].emplace(dist[r][c],c);
                    col[c].emplace(dist[r][c],r);
                }
            }
        }
        return dist[m-1][n-1];
    }
};