/**
 * 
 * Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

*/


#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums_;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sums_.clear();
        if(matrix.empty()) return;
        int m=matrix.size();
        int n=matrix[0].size();

        //sum[i][j]=sum(matrix[0][0]-matrix[i-1][j-1])
        sums_=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
                sums_[i][j]=matrix[i-1][j-1]
                            +sums_[i-1][j]
                            +sums_[i][j-1]
                            -sums_[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums_[row2+1][col2+1]
                -sums_[row2+1][col1]
                -sums_[row1][col2+1]
                +sums_[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
 int main()
 {
   vector<vector<int>> matrix {
     { 3, 0, 1, 4, 2 }, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 },{ 1, 0, 3, 0, 5 } };

   cout << NumMatrix(matrix).sumRegion(2, 1, 4, 3);
 }