
/**
 * @brief 
 * You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform..


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
 * 
 */

/**
 * DFS
 * 从第一列的任一单元格 (i,0)(i,0)(i,0) 开始递归。枚举往右上/右/右下三个方向走，如果走一步后，没有出界，且格子值大于 grid[i][j]\textit{grid}[i][j]grid[i][j]，则可以走，继续递归。

在递归过程中，记录能访问到的最大列号，作为答案。

代码实现时，为避免重复递归之前访问过的格子，可以用一个 vis\textit{vis}vis 数组标记访问过的格子。但实际上，可以把 grid[i][j]\textit{grid}[i][j]grid[i][j] 置为 000 从而无需创建 vis\textit{vis}vis 数组。这是因为网格值均为正数，
并且我们只能访问到比当前格子值更大的格子，所以置为 000 会导致永远无法访问到该格子，这正是我们所希望的。
 * 
 */
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        rows_=grid.size();
        cols_=grid[0].size();
        int ans=0;
        for(int r=0;r<rows_;++r)
            dfs(grid,r,0,ans);
        return ans;
    }
private:
    int rows_;
    int cols_;
    void dfs(vector<vector<int>>& grid,int r,int c,int& ans){
        ans=max(ans,c);
        if(ans==cols_-1)
            return ;
        for(int k=max(0,r-1);k<min(r+2,rows_);++k)
        {
            if(grid[k][c+1]>grid[r][c])
                dfs(grid,k,c+1,ans);
        }
        grid[r][c]=0;
    }
};