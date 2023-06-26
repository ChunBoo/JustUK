/**
 * You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 * 
*/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx=-1,sy=-1;
        int n=1;
        for(int i=0;i<grid.size();++i){
            for(int j=0; j<grid[0].size();++j){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                if(grid[i][j]==0)
                    n+=1;
            }
        }
        return dfs(grid,sx,sy,n);
    }
private:
    int dfs(vector<vector<int>>& grid,int x,int y,int n){
        if(x<0||x==grid.size()||y<0||y==grid[0].size()||
            grid[x][y]==-1)
                return 0;
        
        if(grid[x][y]==2)
            return n==0;

        grid[x][y]=-1;
        int path=dfs(grid,x+1,y,n-1)+
                 dfs(grid,x,y+1,n-1)+
                 dfs(grid,x-1,y,n-1)+
                 dfs(grid,x,y-1,n-1);
        grid[x][y]=0;
        return path;
    }
};