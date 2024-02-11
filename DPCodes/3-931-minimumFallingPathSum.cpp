
/**
 * @brief Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  
The next row’s choice must be in a column that is different from the previous row’s column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.
 * 
 */
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         const int n=matrix.size();
//         int ans=0;
//         vector<vector<int>> f_(n+2,vector<int>(n+2,0));
//         for(int i=1;i<=n;++i)
//         {
//             f_[i][0]=f_[i][n+1]=INT_MAX;
//             for(int j=1;j<=n;++j)
//             {
//                 f_[i][j]=*min_element(f_[i-1].begin()+j-1,f_[i-1].begin()+j+2)+matrix[i-1][j-1];
//             }
//         }
//         return *min_element(f_[n].begin()+1,f_[n].end()-1);
//     }
// };
/**
 * @brief 题目需要求出矩阵的和最小下降路径，可以求出末行每个元素的和最小下降路径，然后找到其中和最小的那一条路径即可。
 * 而根据题意，每个坐标仅可以通过它的上一排紧邻的三个坐标到达（左上，正上，右上），根据贪心思想，每个坐标的和最小下降路径长度即为它的上一排紧邻的三个坐标的和最小下降路径长度的最小值，再加上当前坐标的和。
 * 用 dp\textit{dp}dp 表示和最小下降路径长度的话，即为 dp[i][j]=matrix[i][j]+min⁡(dp[i−1][j−1],dp[i−1][j],dp[i−1][j+1])\textit{dp}[i][j] = \textit{matrix}[i][j] + \min(\textit{dp}[i-1][j-1], \textit{dp}[i-1][j], \textit{dp}[i-1][j+1])dp[i][j]=matrix[i][j]+min(dp[i−1][j−1],dp[i−1][j],dp[i−1][j+1])，
 * 第一列和最后一列有边界情况，需要特殊处理。而第一行每个元素的和最小下降路径长度为它们本身的值。最后返回最后一行的和最小下降路径长度的最小值即可。


 * 
 */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = dp[i - 1][j];
                if (j > 0) {
                    mn = min(mn, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    mn = min(mn, dp[i - 1][j + 1]);
                }
                dp[i][j] = mn + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

