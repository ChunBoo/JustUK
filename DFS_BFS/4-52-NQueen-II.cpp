/**
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols(n);
        vector<int> diag1(2*n-1);
        vector<int> diag2(2*n-1);
        int ans=0;
        
        function<void(int)> dfs=[&](int r){
            if(r==n){
              ++ans;
              return;
            }
            
            for(int i=0;i<n;++i){
                int& c=cols[i];
                int& d1=diag1[r+i];
                int& d2=diag2[r-i+n-1];
                if(c||d1||d2)
                    continue;
                c=d1=d2=1;
                dfs(r+1);
                c=d1=d2=0;
            }
        };
        dfs(0);
        return ans;
    }
};