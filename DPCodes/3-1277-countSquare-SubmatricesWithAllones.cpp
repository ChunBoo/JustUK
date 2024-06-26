
/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int R=matrix.size();
        const int C=matrix[0].size();
        vector<vector<int>> dp(R,vector<int>(C));

        int ans=0;
        for(int r=0;r<R;++r)
        {
            for(int c=0;c<C;++c)
            {
                dp[r][c]=matrix[r][c];
                if(r&&c&&dp[r][c])
                    dp[r][c]=min({dp[r-1][c-1],dp[r][c-1],dp[r-1][c]})+1;
                ans+=dp[r][c];
            }
        }
        return ans;
    }
};