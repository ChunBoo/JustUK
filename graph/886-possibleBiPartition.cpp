
/**
 * We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= ai < bi <= n
All the pairs of dislikes are unique.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> g_;
    vector<int> colors_;
    bool dfs(int cur,int color){
        colors_[cur]=color;
        for(int nxt:g_[cur]){
            if(colors_[nxt]==color) return false;
            if (colors_[nxt] == 0 && !dfs(nxt, -color))
              return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      g_ = vector<vector<int>>(n); // vector<vector<int>>(n,vector<int>(n)) is incorrect, as the inner vec will be initialized with size as n,   
      colors_ = vector<int>(n, 0); // 0:unknown, 1:red, -1:blue
      for (auto const &d : dislikes) {
        g_[d[0] - 1].push_back(d[1] - 1);
        g_[d[1] - 1].push_back(d[0] - 1);
      }

      for (int i = 0; i < n; ++i) {
        // colors_[i]=1;
        if (colors_[i] == 0 && !dfs(i, 1))
          return false;
      }
        return true;
    }
};

class Solution2 {
private:
    vector<vector<int>> g_;
    vector<int> colors_;

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g_=vector<vector<int>>(n);
        for(const auto&d:dislikes){
            g_[d[0]-1].push_back(d[1]-1);
            g_[d[1]-1].push_back(d[0]-1);
        }
        queue<int> q;
        colors_=vector<int>(n,0);
        for(int i=0;i<n;++i){
            if(colors_[i]!=0) continue;
            q.push(i);
            colors_[i]=1;
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                for(int nxt:g_[cur]){
                    if(colors_[nxt]==colors_[cur]) return false;
                    if(colors_[nxt]!=0)  continue;
                    colors_[nxt]=-colors_[cur];
                    q.push(nxt);
                }
            }
        }
        return true;
    }
};

int main() {
  int n = 4;
  vector<vector<int>> dislikes{{1, 2}, {1, 3}, {2, 4}};
  cout << Solution().possibleBipartition(n, dislikes);
}