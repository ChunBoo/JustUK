/**
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
// class Solution {
//     private:
//     void dfs(int x,int y,vector<vector<char>>& grid){
//             if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]=='0')
//                 return;
//             grid[x][y]='0';
//             dfs(x,y+1,grid);
//             dfs(x,y-1,grid);
//             dfs(x+1,y,grid);
//             dfs(x-1,y,grid);
//         };
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int ans=0;
        
//         for(int i=0;i<grid.size();++i)
//             for(int j=0;j<grid[0].size();++j)
//         {
//             if(grid[i][j]=='1')
//             {
//                 grid[i][j]='0';
//                 dfs(i,j,grid);
//                 ans+=grid[i][j]-'0';
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x) {
                ans += grid[y][x] - '0';
                dfs(grid, x, y, m, n);
            }
        return ans;                
    }   
private:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == '0')
            return;
        grid[y][x] = '0';
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x, y + 1, m, n);
        dfs(grid, x, y - 1, m, n);
    }
};