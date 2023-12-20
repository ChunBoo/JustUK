/**
 * In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.
Solution
Step 1: give each connected component a unique id and count its ara.

Step 2: for each 0 zero, check its 4 neighbours, sum areas up by unique ids.

Time complexity: O(n*m)

Space complexity: O(n*m)
*/


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        m_=grid.size();
        n_=grid[0].size();
        g_=&grid;
        unordered_map<int,int> area;
        int color=1;
        int ans=0;
        for(int r=0;r<m_;++r)
        {
            for(int c=0;c<n_;++c)
            {
                if(grid[r][c]==1)
                {
                    ++color;
                    area[color]=getArea(r,c,color);
                    ans=max(ans,area[color]);
                }
            }
        }
        for(int r=0;r<m_;++r)
        {
            for(int c=0;c<n_;++c)
            {
                if(grid[r][c]==0){
                    int area_=1;
                    for(int color:set<int>{getColor(r+1,c),getColor(r-1,c),getColor(r,c+1),                        getColor(r,c-1)})
                    {
                        area_+=area[color];
                    }
                    ans=max(ans,area_);
                }
            }
        }
        return ans;
    }
private:
    int m_;
    int n_;
    vector<vector<int>> *g_;
    int getColor(int r,int c)
    {
        return (r<0||r>=m_||c<0||c>=n_)?0:(*g_)[r][c];
    }
    int getArea(int r,int c,int color)
    {
        if(r<0||r>=m_||c<0||c>=n_||(*g_)[r][c]!=1)
            return 0;
        (*g_)[r][c]=color;
        return 1+getArea(r+1,c,color)+getArea(r-1,c,color)+getArea(r,c+1,color)
                +getArea(r,c-1,color);
    }

};