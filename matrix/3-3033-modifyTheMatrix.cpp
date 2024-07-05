/***
 * Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.

Return the matrix answer.

 

Example 1:


Input: matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
Output: [[1,2,9],[4,8,6],[7,8,9]]
Explanation: The diagram above shows the elements that are changed (in blue).
- We replace the value in the cell [1][1] with the maximum value in the column 1, that is 8.
- We replace the value in the cell [0][2] with the maximum value in the column 2, that is 9.
 */

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        const int COL=matrix[0].size();
        const int ROW=matrix.size();

        for(int c=0;c<COL;c++){
            int maxVal=-1;
            for(int r=0;r<ROW;r++){
                maxVal=max(maxVal,matrix[r][c]);
            }

            for(int r=0;r<ROW;r++){
                if(matrix[r][c]==-1){
                    matrix[r][c]=maxVal;
                }
            }
        }
        return matrix;
    }
};