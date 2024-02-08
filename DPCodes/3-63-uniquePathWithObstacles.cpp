/**
 * @brief You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
 * 
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int R=obstacleGrid.size();
        int C=obstacleGrid[0].size();
        f_=vector(R+1,vector<int>(C+1,INT_MIN));
        return uniquePath(obstacleGrid,R,C);
    }
private:
    vector<vector<int>> f_;
    int uniquePath(const vector<vector<int>>& nums,int r,int c)
    {
        if(r<=0||c<=0)
            return 0;
        
        if(r==1&&c==1)
            return nums[r-1][c-1]==0;
        
        if(f_[r][c]!=INT_MIN)
            return f_[r][c];
        if(nums[r-1][c-1]==1)
            f_[r][c]=0;
        else
            f_[r][c]=uniquePath(nums,r-1,c)+uniquePath(nums,r,c-1);
        
        return f_[r][c];
    }
};