/***
 * You are given a 0-indexed 2D integer matrix grid of size 3 * 3, representing the number of stones in each cell. The grid contains exactly 9 stones, and there can be multiple stones in a single cell.

In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.

Return the minimum number of moves required to place one stone in each cell.
 */

class Solution {

public:
    int minimumMoves(vector<vector<int>>& grid) {
        dfs(0,0,grid);
        return ans;
    }
private:
    int ans=INT_MAX;
    void dfs(int cur,int moves, vector<vector<int>>& grid){
        if(cur==9){
            ans=min(ans,moves);
            return ;
        }
        if(moves>ans) return ;
        int r=cur/3, c=cur%3;
        if(grid[r][c]!=0){
            dfs(cur+1,moves,grid);
            return;
        }
        else{
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    if(grid[x][y]>1){
                        grid[x][y]-=1;
                        grid[r][c]+=1;
                        dfs(cur+1,moves+abs(r-x)+abs(c-y),grid);
                        grid[x][y]+=1;
                        grid[r][c]-=1;
                    }
                }
            }
        }
    }
};