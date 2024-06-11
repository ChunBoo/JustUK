/***
 * Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int R=board.size();
        const int C=board[0].size();
        int ans=0;
        for(int r=0;r<R;++r ){
            for(int c=0;c<C;c++){
                if(board[r][c]=='X'){
                    board[r][c]='.';
                    for(int k=c+1;k<C&&board[r][k]=='X';k++){
                        board[r][k]='.';
                    }

                    for(int k=r+1;k<R&&board[k][c]=='X';k++){
                        board[k][c]='.';
                    }
                    ans++;                    
                }
            }
        }
        return ans;
    }
};