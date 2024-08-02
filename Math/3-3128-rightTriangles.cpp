/***
 * You are given a 2D boolean matrix grid.

Return an integer that is the number of right triangles that can be made with the 3 elements of grid such that all of them have a value of 1.

Note:

A collection of 3 elements of grid is a right triangle if one of its elements is in the same row with another element and in the same column with the third element. The 3 elements do not have to be next to each other.
 

Example 1:

0	1	0
0	1	1
0	1	0
0	1	0
0	1	1
0	1	0
Input: grid = [[0,1,0],[0,1,1],[0,1,0]]

Output: 2

Explanation:

There are two right triangles.
 */

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int R=grid.size(), C=grid[0].size();
        vector<int> col(C);

        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                col[c]+=grid[r][c];
            }
        }
        long long ans=0;
        for(int r=0;r<R;r++){
            int row=accumulate(grid[r].begin(),grid[r].end(),0);
            for(int c=0;c<C;c++){
                if(grid[r][c]==1){
                    ans+=(row-1)*(col[c]-1);
                }
            }
        }
        return ans;
    }
};