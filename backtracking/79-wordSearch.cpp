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