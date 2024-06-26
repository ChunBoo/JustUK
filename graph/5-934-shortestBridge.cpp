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

#include<iostream>
#include<vector>
#include<queue>
// #include<>
using namespace std;

class S {
public:
  int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int, int>> q;
    bool found = false;
    for (int i = 0; i < int(A.size()) && !found; ++i)
      for (int j = 0; j < int(A[0].size()) && !found; ++j)
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
          if (tx < 0 || ty < 0 || tx >= int(A[0].size()) || ty >= int(A.size()) || A[ty][tx] == 2) continue;          
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
    if (x < 0 || y < 0 || x >= int(A[0].size()) || y >=int(A.size()) || A[y][x] != 1) return;
    A[y][x] = 2;
    q.emplace(x, y);
    dfs(A, x - 1, y, q);
    dfs(A, x, y - 1, q);
    dfs(A, x + 1, y, q);
    dfs(A, x, y + 1, q);
  }
};
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        m_=grid.size();
        n_=grid[0].size();

        bool found=false;
        queue<pair<int,int>> q;
        for(int r=0;r<m_&&!found;++r)
        {
            for(int c=0;c<n_&&!found;++c)
            {
                if(grid[r][c])
                {
                    dfs(grid,c,r,q);
                    found =true;
                }
            }
        }
        int steps=0;
        const vector<int> dirs{0,-1,0,1,0};
        while(!q.empty())
        {
            size_t size=q.size();
            while(size--)
            {
                auto p=q.front();
                q.pop();
                int r=p.first, c=p.second;

                for(int i=0;i<4;++i)
                {
                    int tr=r+dirs[i];
                    int tc=c+dirs[i+1];
                    if(tr<0||tr>=m_||tc<0||tc>=n_||grid[tr][tc]==2)
                        continue;
                    if(grid[tr][tc]==1)
                        return steps;
                    grid[tr][tc]=2;
                    q.emplace(tr,tc);
                }
            }
            ++steps;
        }
        return -1;
    }

private:
    int m_;
    int n_;
    void dfs(vector<vector<int>>& grid,int x,int y,queue<pair<int,int>>& q)
    {
        if(x<0||x>=n_||y<0||y>=m_||grid[y][x]!=1)
            return;
        grid[y][x]=2;

        q.emplace(y,x);
        dfs(grid,x+1,y,q);
        dfs(grid,x-1,y,q);
        dfs(grid,x,y+1,q);
        dfs(grid,x,y-1,q);
    }
};

int main()
{
  vector<vector<int>> grid{{0,1},{1,0}};
  cout<<S().shortestBridge(grid);
}
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