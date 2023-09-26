/*
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m=matrix.size();
        const int n=matrix[0].size();
        for(int j=0;j<n;++j)
            for(int i=1;i<m;++i)
                if(matrix[i][j]) matrix[i][j]+=matrix[i-1][j];
        
        int ans=0;
        for(int i=0;i<m;++i)
        {
            sort(rbegin(matrix[i]),rend(matrix[i]));
            for(int j=0;j<n;++j)
                ans=max(ans,(j+1)*matrix[i][j]);
        }
        return ans;
    }
};