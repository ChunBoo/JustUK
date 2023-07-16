

/**
 * According to the Wikipedia’s article: “The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.”

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 * 
*/

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = m ? board[0].size() : 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int lives = 0;
        // Scan the 3x3 region including (j, i).
        for (int y = max(0, i - 1); y < min(m, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(n, j + 2); ++x)
            lives += board[y][x] & 1;
        if (lives == 3 || lives - board[i][j] == 3) board[i][j] |= 0b10;
      }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) 
        board[i][j] >>= 1;
  }
};