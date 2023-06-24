#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
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



struct State {
    string board;
    string hand;
    int step;
    State(const string & board, const string & hand, int step) {
        this->board = board;
        this->hand = hand;
        this->step = step;
    }
};

class Solution2 {
public:
    string clean(const string & s) {
        string res;
        vector<pair<char, int>> st;
        
        for (auto c : s) {
            while (!st.empty() && c != st.back().first && st.back().second >= 3) {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first) {
                st.push_back({c,1});
            } else {
                st.back().second++;
            }
        }
        if (!st.empty() && st.back().second >= 3) {
            st.pop_back();
        }
        for (size_t i = 0; i < st.size(); ++i) {
            for (int j = 0; j < st[i].second; ++j) {
                res.push_back(st[i].first);
            }
        }
        return res;
    }

    int findMinStep(string board, string hand) {
        unordered_set<string> visited;
        sort(hand.begin(), hand.end());

        visited.insert(board + " " + hand);
        queue<State> qu;
        qu.push(State(board, hand, 0));
        while (!qu.empty()) {
            State curr = qu.front();
            qu.pop();

            for (size_t j = 0; j < curr.hand.size(); ++j) {
                // 第 1 个剪枝条件: 当前选择的球的颜色和前一个球的颜色相同
                if (j > 0 && curr.hand[j] == curr.hand[j - 1]) {
                    continue;
                }
                for (size_t i = 0; i <= curr.board.size(); ++i) {
                    // 第 2 个剪枝条件: 只在连续相同颜色的球的开头位置插入新球
                    if (i > 0 && curr.board[i - 1] == curr.hand[j]) {
                        continue;
                    }

                    // 第 3 个剪枝条件: 只在以下两种情况放置新球
                    bool choose = false;
                    //   第 1 种情况 : 当前球颜色与后面的球的颜色相同
                    if (i < curr.board.size() && curr.board[i] == curr.hand[j]) {
                        choose = true;
                    }  
                    //   第 2 种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                    if (i > 0 && i < curr.board.size() && curr.board[i - 1] == curr.board[i] && curr.board[i] != curr.hand[j]){
                        choose = true;
                    }
                    if (choose) {
                        string new_board = clean(curr.board.substr(0, i) + curr.hand[j] + curr.board.substr(i));
                        string new_hand = curr.hand.substr(0, j) + curr.hand.substr(j + 1);
                        if (new_board.size() == 0) {
                            return curr.step + 1;
                        }
                        if (!visited.count(new_board + " " + new_hand)) {
                            qu.push(State(new_board, new_hand, curr.step + 1));
                            visited.insert(new_board + " " + new_hand);
                        }
                    }
                }
            }
        }

        return -1;  
    }
};


int main()
{
   string board= "RRWWRRBBRR",hand="WB";
   cout<<Solution2().findMinStep(board,hand);
}