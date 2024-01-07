
/**
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        sols_.clear();
        board_=vector<string>(n,string(n,'.'));
        cols_=vector<bool>(n,0);
        diag1_=vector<bool>(2*n-1,0);
        diag2_=vector<bool>(2*n-1,0);
        nqueens(n,0);
        return sols_;
    }
private:
    vector<vector<string>> sols_;
    vector<bool> cols_;
    vector<bool> diag1_;
    vector<bool> diag2_;
    vector<string> board_;
    bool available(int r,int c,int n){
        return !cols_[c]
             &&!diag1_[r+c]
             &&!diag2_[c-r+n-1];
    }
    void updateBoard(int r,int c,int n,bool isPut){
        cols_[c]=isPut;
        diag1_[c+r]=isPut;
        diag2_[c-r+n-1]=isPut;
        board_[r][c]=isPut?'Q':'.';
    }
    void nqueens(const int n,const int r){
        if(r==n)  //y is row
        {
            sols_.push_back(board_);
            return;
        }
        //check each column
        for(int c=0;c<n;++c){
            if(!available(r,c,n))
                continue;
            updateBoard(r,c,n,true);
            nqueens(n,r+1);
            updateBoard(r,c,n,false);
        }
    }

};