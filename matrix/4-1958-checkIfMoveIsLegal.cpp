/***
 * You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) on a game board. On the board, free cells are represented by '.', white cells are represented by 'W', and black cells are represented by 'B'.

Each move in this game consists of choosing a free cell and changing it to the color you are playing as (either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint of a good line (horizontal, vertical, or diagonal).

A good line is a line of three or more cells (including the endpoints) where the endpoints of the line are one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). You can find examples for good lines in the figure below:


Given two integers rMove and cMove and a character color representing the color you are playing as (white or black), return true if changing cell (rMove, cMove) to color color is a legal move, or false if it is not legal.

 

Example 1:


Input: board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
Output: true
Explanation: '.', 'W', and 'B' are represented by the colors blue, white, and black respectively, and cell (rMove, cMove) is marked with an 'X'.
The two good lines with the chosen cell as an endpoint are annotated above with the red rectangles.
 */

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        auto check=[&](int dx,int dy)->bool{
            int x=rMove+dx;
            int y=cMove+dy;

            int step=1;
            while(x>=0&&x<8&&y>=0&&y<8){
                if(step==1){
                    if(board[x][y]=='.'||board[x][y]==color){
                        return false;
                    }
                }
                else{
                    if(board[x][y]=='.'){
                        return false;
                    }
                    if(board[x][y]==color){
                        return true;
                    }
                }
                step++;
                x+=dx;
                y+=dy;
            }
            return false;
        };
        //CW from x coordinator
        vector<int> dx{1,1,0,-1,-1,-1,0,1};  //rows changes
        vector<int> dy{0,1,1,1,0,-1,-1,-1};  //cols changes

        for(int k=0;k<8;k++){
            if(check(dx[k],dy[k])){
                return true;
            }
        }
        return false;
    }
};