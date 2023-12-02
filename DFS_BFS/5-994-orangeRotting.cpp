/**
 * In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1instead.
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int R=grid.size(),C=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int r=0;r<R;++r)
          for(int c=0;c<C;++c)
            if(grid[r][c]==1) ++fresh;
            else if(grid[r][c]==2) 
                q.emplace(r,c);
        vector<int> dirs{1,0,-1,0,1};
        int days=0;
        while(!q.empty()&&fresh)
        {
            int sz=q.size();
            while(sz--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;++i)
                {
                    int dr=r+dirs[i];
                    int dc=c+dirs[i+1];
                    if(dr<0||dr>=R||dc<0||dc>=C||grid[dr][dc]!=1)
                        continue;
                    --fresh;
                    grid[dr][dc]=2;
                    q.emplace(dr,dc);
                }
            }
            ++days;
        }
        return fresh?-1:days;
    }
};