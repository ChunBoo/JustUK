/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

Input: board = [['5','3','.','.','7','.','.','.','.'],['6','.','.','1','9','5','.','.','.'],['.','9','8','.','.','.','.','6','.'],['8','.','.','.','6','.','.','.','3'],['4','.','.','8','.','3','.','.','1'],['7','.','.','.','2','.','.','.','6'],['.','6','.','.','.','.','2','8','.'],['.','.','.','4','1','9','.','.','5'],['.','.','.','.','8','.','.','7','9']]
Output: [['5','3','4','6','7','8','9','1','2'],['6','7','2','1','9','5','3','4','8'],['1','9','8','3','4','2','5','6','7'],['8','5','9','7','6','1','4','2','3'],['4','2','6','8','5','3','7','9','1'],['7','1','3','9','2','4','8','5','6'],['9','6','1','5','3','7','2','8','4'],['2','8','7','4','1','9','6','3','5'],['3','4','5','2','8','6','1','7','9']]
Explanation: The input board is shown above and the only valid solution is shown below:
*/

#include<iostream>
#include<vector>

using namespace std;


class Solution{
    public:
        bool solveSudoku(vector<vector<char>>& board)
        {
            rows_=vector<vector<int>>(9,vector<int>(10));
            cols_=vector<vector<int>>(9,vector<int>(10));
            boxes_= vector<vector<int>>(9,vector<int>(10));

            for(int i=0;i<9;++i)
            {
                for(int j=0;j<9;++j){
                    const char c=board[i][j];
                    if(c!='.'){
                        int n=c-'0';
                        int bx=j/3;
                        int by=i/3;
                        rows_[i][n]=1;
                        cols_[j][n]=1;
                        boxes_[by*3+bx][n]=1;
                    }
                }
            }
           return fill(board,0,0);
        }
    private:
        vector<vector<int>> rows_,cols_,boxes_;
        bool fill(vector<vector<char>>& board,int x,int y)
        {
            if(y==9)
                return true;
            
            int nx=(x+1)%9;
            int ny=(nx==0)?y+1:y;

            if(board[y][x]!='.') 
                return fill(board,nx,ny);

            for(int i=1;i<=9;++i)
            {
                int bx=x/3;
                int by=y/3;
                int box_key=by*3+bx;

                if(!rows_[y][i]&& !cols_[x][i]&&!boxes_[box_key][i]){
                    rows_[y][i]=1;
                    cols_[x][i]=1;
                    boxes_[box_key][i]=1;

                    board[y][x]=i+'0';
                    if(fill(board,nx,ny))
                        return true;
                    rows_[y][i]=0;
                    cols_[x][i]=0;
                    boxes_[box_key][i]=0;

                    board[y][x]='.';
                }
            }
            return false;
        }
        
};

int main()
{
    vector<vector<char>> board{ {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}}};
    cout<<Solution().solveSudoku(board);
}