
/*
Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (” “).
The first player A always places “X” characters, while the second player B always places “O” characters.
“X” and “O” characters are always placed into empty squares, never on filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play. Return the winner of the game if it exists (A or B), in case the game ends in a draw return “Draw”, if there are still movements to play return “Pending”.

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

Example 1:
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: “A”

Explanation: “A” wins, he always plays first.

"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
Example 2:
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: “B”
Explanation: “B” wins.

"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
"   "    "   "    "   "    "   "    "   "    "O  "
Example 3:

Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: “Draw”
Explanation: The game ends in a draw since there are no moves to make.

1
2
3
"XXO"
"OOX"
"XOX"
Example 4:

Input: moves = [[0,0],[1,1]]
Output: “Pending”
Explanation: The game has not finished yet.

1
2
3
"X  "
" O "
"   "
Constraints:
1 <= moves.length <= 9
moves[i].length == 2
0 <= moves[i][j] <= 2
There are no repeated elements on moves.
moves follow the rules of tic tac toe.

Hints:
It’s straightforward to check if A or B won or not, check for each row/column/diag if all the three are the same.
Then if no one wins, the game is a draw if and only if the board is full, i.e. moves.length = 9 otherwise is pending.
*/

#include<vector>
#include<iostream>
#include<string>
bool win(char board[3][3],std::string& result)
{
    for(int i=0;i<3;++i)
    {
        if((board[i][0]!=0)&&(board[i][0]==board[i][1])
                            &&(board[i][1]==board[i][2]))
        {
            result=board[i][0];
            return true;
        }
        if((board[0][i]!=0)&&(board[0][i]==board[1][i])
                            &&(board[1][i]==board[2][i]))
        {
            result=board[0][i];
            return true;
        }
    }
    if((board[1][1]!=0)&&(board[0][0]==board[1][1])
                        &&(board[1][1]==board[2][2]))
    {
        result=board[1][1];
        return true;
    }
    if((board[1][1]!=0)&&(board[0][1]==board[1][1])
                        &&(board[1][1]==board[2][0]))
    {
        result=board[1][1];
        return true;
    }
    return false;
}

std::string tictactoe(std::vector<std::vector<int>>& moves)
{
    char board[3][3]={};
    std::string result;
    int i=0;
    for(const auto &n:moves)
    {
        board[n[0]][n[1]]=((i++)%2==0)?'A':'B';
        if(win(board,result))
            return result;
    }
    return i==9?"Draw":"Pending";
}

int main()
{
    std::vector<std::vector<int>> moves{{0,0},{2,0},{1,1},{2,1},{2,2}};
    std::cout<<tictactoe(moves);
}