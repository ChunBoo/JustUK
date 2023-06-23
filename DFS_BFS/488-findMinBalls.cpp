#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        vector<int> h(128,0);
        for(char c:hand)
            h[c]++;
        return dfs(board,h);
    }
private:
    string update(string board)
    {
        size_t i=0;
        while(i<board.size()){
            size_t j=i;
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
    int dfs(string& board, vector<int>& hand)
    {
        if(board.size()==0)
            return 0;
        int ans=INT_MAX;
        size_t i=0,j=0;
        while(i<board.size()){
            // j=i;
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

int main()
{
   string board= "RRWWRRBBRR",hand="WB";
   cout<<Solution().findMinStep(board,hand);
}