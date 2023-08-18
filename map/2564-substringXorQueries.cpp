#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> m;
        const int l=s.length();
        for(int i=0;i<l;++i){
            if(s[i]=='0'){
                if(!m.count(0)) m[0]={i,i};
                continue;
            }
            for(int j=0,cur=0;j<30&&i+j<l;++j){  // the length of substring should less than 30, how to prove it?
                cur=(cur<<1)|(s[i+j]-'0');
                if(!m.count(cur))
                    m[cur]={i,i+j};
            }
        }
        vector<vector<int>> ans;
        for(const auto& q:queries){
            int x=q[0]^q[1];
            if(m.count(x))
            ans.push_back(m[x]);
            else
             ans.push_back({-1,-1});
        }
        return ans;
    }
};

int main() {
  string sb{"101101"};
  vector<vector<int>> queries{{0, 5}, {1, 2}};
  vector<vector<int>> res = Solution().substringXorQueries(sb, queries);
  for (auto &v : res) {
    for (auto d : v)
      cout << d << ',';
    cout << '\n';
  }
}