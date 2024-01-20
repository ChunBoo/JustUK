
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where “adjacent” cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

Idea:
Search, depth first search
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)
            return false;
        h=board.size();
        w=board[0].size();
        word_=std::move(word);
        for(int r=0;r<h;++r)
        {
            for(int c=0;c<w;++c)
            {
                if(search(board,r,c,0))
                    return true;
            }
        }
        return false;
    }
private:
    int h;
    int w;
    string word_;
    bool search(vector<vector<char>>& board,int r,int c,int d){
        if(r<0||r>=h||c<0||c>=w||board[r][c]!=word_[d])
            return false;
        if(d==word_.length()-1)
            return true;
        char cur=board[r][c];
        board[r][c]=0;
        bool found=search(board,r+1,c,d+1)
                    ||search(board,r-1,c,d+1)
                    ||search(board,r,c+1,d+1)
                    ||search(board,r,c-1,d+1);
        board[r][c]=cur;
        return found;
    }
};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        r_=board.size();
        c_=board[0].size();
        word_=std::move(word);
        for(int r=0;r<r_;++r)
            for(int c=0;c<c_;++c)
              if(dfs(board,r,c,0))
                return true;
        return false;
    }

private:
    int r_;
    int c_;
    string word_;
    bool dfs( vector<vector<char>>& board, int r,int c,int d)
    {
        if(r<0||r==r_||c<0||c==c_)
            return false;
        if(word_[d]!=board[r][c])
            return false;
        if(d==word_.size()-1)
            return true;
        char ch=board[r][c];
        board[r][c]=0; //indicate current r/c already access, as each cell can be used only once
        bool found= dfs(board,r+1,c,d+1)||dfs(board,r-1,c,d+1)
              ||dfs(board,r,c+1,d+1)||dfs(board,r,c-1,d+1);
        board[r][c]=ch;
        return found;
    }
};