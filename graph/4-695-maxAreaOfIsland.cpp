/*Given a non-empty 2D array grid of 0’s and 1’s, an island is a group of 1‘s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)


[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

1
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.



Idea:

Use DFS to find the connected components

*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                ans = max(ans, area(grid, j, i, w, h));
        return ans;
    }
private:
    int area(vector<vector<int>>& grid, int x, int y, int w, int h) {
        if (x < 0 || y < 0 || x >= w || y >= h || grid[y][x] == 0) return 0;
        
        grid[y][x] = 0;
        
        return area(grid, x - 1, y, w, h) 
             + area(grid, x + 1, y, w, h)
             + area(grid, x, y - 1, w, h)
             + area(grid, x, y + 1, w, h)
             + 1;            
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h=grid.size();
        if(h==0)
            return 0;
        int w=grid[0].size();
        int ans=0;
        for(int r=0;r<h;++r)
        {
            for(int c=0;c<w;++c)
                ans=max(ans,area(grid,r,c,h,w));
        }
        return ans;
    }
    int area( vector<vector<int>>& grid,int r,int c,int h,int w)
    {
        if(r<0||r>=h||c<0||c>=w||grid[r][c]==0)
            return 0;
        grid[r][c]=0;
        return area(grid,r-1,c,h,w)+area(grid,r+1,c,h,w)+
               area(grid,r,c-1,h,w)+area(grid,r,c+1,h,w)+1;
    }
};