/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:

0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:

0 0 0
0 1 0
1 2 1
Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
Solution 1: DP
Two passes:

down, right
up, left
Time complexity: O(mn)

Space complexity: O(mn)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int R=mat.size();
      int C=mat[0].size();
      vector<vector<int>> ans(R,vector<int>(C,INT_MAX-R*C));

      for(int r=0;r<R;++r)
        for(int c=0;c<C;++c)
          if(mat[r][c])
          {
              if(r>0) ans[r][c]=min(ans[r][c],ans[r-1][c]+1);
              if(c>0) ans[r][c]=min(ans[r][c],ans[r][c-1]+1);
          }
          else
            ans[r][c]=0;
    
     for(int r=R-1;r>=0;--r)
        for(int c=C-1;c>=0;--c)
        {
            if(r<R-1) ans[r][c]=min(ans[r][c],ans[r+1][c]+1);
            if(c<C-1) ans[r][c]=min(ans[r][c],ans[r][c+1]+1);
        }
        return ans;
    }
};