class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> h(128,0);
        for(char c:board)
            h[c]++;
        return dfs(board,hand);
    }
private:
    string update(string board)
    {
        int i=0;
        while(i<board.size()){
            int j=i;
            while(j<board.size()&&board[j]==board[i]) ++j;
            if(j-i>=3)
            {
                board=board.substr(0,i)+board.substr(j);
                i=0;
            }
            else
                ++i;
        }
        return board;
    }
    int dfs(string& board, string& hand)
    {
        if(board.size()==0)
            return 0;
        int ans=INT_MAX;
        int i=0,j=0;
        while(i<board.size()){
            while(j<board.size()&&board[j]==board[i]) ++j;
            const int b=3-(j-i);
            const char color=board[i];
            if(hand[color]>=b){
                string nb=update(board.substr(0,i)+board.substr(j));
                hand[color]-=b;
                int r=dfs(nb,hand);
                if(r>=0)
                    ans=min(ans,r+b);
                hand[color]+=b;
            }
            i=j;
         }
         return ans==INT_MAX?-1:ans;
    }

};