/**
 * You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.
*/
class Solution {
public:
  int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int, int>> q;
    bool found = false;
    for (int i = 0; i < A.size() && !found; ++i)
      for (int j = 0; j < A[0].size() && !found; ++j)
        if (A[i][j]) {
          dfs(A, j, i, q);
          found = true;
        }
    
    int steps = 0;
    vector<int> dirs{0, 1, 0, -1, 0};
    while (!q.empty()) {      
      size_t size = q.size();
      while (size--) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int tx = x + dirs[i];
          int ty = y + dirs[i + 1];
          if (tx < 0 || ty < 0 || tx >= A[0].size() || ty >= A.size() || A[ty][tx] == 2) continue;          
          if (A[ty][tx] == 1) return steps;
          A[ty][tx] = 2;
          q.emplace(tx, ty);
        }
      }
      ++steps;
    }
    return -1;
  }
private:  
  void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
    if (x < 0 || y < 0 || x >= A[0].size() || y >= A.size() || A[y][x] != 1) return;
    A[y][x] = 2;
    q.emplace(x, y);
    dfs(A, x - 1, y, q);
    dfs(A, x, y - 1, q);
    dfs(A, x + 1, y, q);
    dfs(A, x, y + 1, q);
  }
};

// class Solution {

// private:
//     void dfs(vector<vector<int>>& A,int x,int y,queue<pair<int,int>>& q){
//         if(x<0||y<0||x>=A[0].size()||y>=A.size()||A[y][x]!=1)
//         {
//             A[y][x]=2;
//             q.emplace(x,y);
//             dfs(A,x-1,y,q);
//             dfs(A,x,y-1,q);
//             dfs(A,x+1,y,q);
//             dfs(A,x,y+1,q);
//         }
//     }
// public:
//     int shortestBridge(vector<vector<int>>& grid) {
//         queue<pair<int,int>> q;
//         bool found=false;
//         for(int i=0;i<grid.size()&&!found;++i)
//             for(int j=0;j<grid[0].size()&&!found;++j)
//             {
//                 if(grid[i][j])
//                 {
//                     dfs(grid,j,i,q);
//                     found=true;
//                 }
//             }
//         int steps=0;
//         vector<int> dirs{0,1,0,-1,0};
//         while(!q.empty()){
//             size_t size=q.size();
//             while(size--){
//                 int x=q.front().first;
//                 int y=q.front().second;
//                 q.pop();
//                 for(int i=0;i<4;++i){
//                     int tx=x+dirs[i];
//                     int ty=y+dirs[i+1];
//                     if(tx<0||ty<0||tx>=grid[0].size()||ty>=grid.size()||grid[ty][tx]==2)
//                         continue;
//                     if(grid[ty][tx]==1) return steps;
//                     grid[ty][tx]=2;
//                     q.emplace(tx,ty);
//                 }
//             }
//             ++steps;
//         }
//         return -1;
//     }
// };