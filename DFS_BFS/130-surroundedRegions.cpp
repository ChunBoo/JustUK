/**
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        /*const int m=board.size();
        if(m==0) return;
        const int n=board[0].size();

        function<void(int,int)> dfs=[&](int x,int y)
        {
            if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') return;
            board[x][y]='G';
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y+1);
            dfs(x,y-1);
        };

        for(int r=0;r<m;++r)
            dfs(0,r),dfs(n-1,r);

        for(int c=0;c<n;++c)
            dfs(c,0),dfs(c,m-1);

        map<char,char> v{{'G','O'},{'O','X'},{'X','X'}};
        for(int r=0;r<m;++r)
            for(int c=0;c<n;++c)
            {
                board[r][c]=v[board[r][c]];
            }*/

             const int m = board.size();
    if (m == 0) return;
    const int n = board[0].size();    
    
    function<void(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] != 'O') return;
      board[y][x] = 'G'; // mark it as good      
      dfs(x - 1, y);
      dfs(x + 1, y);
      dfs(x, y - 1);
      dfs(x, y + 1);
    };
    
    for (int y = 0; y < m; ++y)
      dfs(0, y), dfs(n - 1, y);    
    
    for (int x = 0; x < n; ++x)
      dfs(x, 0), dfs(x, m - 1);    
    
    map<char, char> v{{'G','O'},{'O','X'}, {'X','X'}};
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x)
        board[y][x] = v[board[y][x]];
    }
};