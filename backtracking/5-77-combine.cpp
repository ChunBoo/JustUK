/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 … n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Solution: DFS
Time complexity: O(C(n, k))
Space complexity: O(k)

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
*/
#include<vector>
#include<iostream>
#include<functional>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> cur;
    function<void(int)> dfs = [&](int s) {
      if (cur.size() == k) { 
        ans.push_back(cur); 
        return;
      }
      for (int i = s; i < n; ++i) {
        cur.push_back(i + 1);
        dfs(i + 1);
        cur.pop_back();
      }  
    };
    dfs(0);
    return ans;
  }
};

int main()
{
    vector<vector<int>> res=Solution().combine(4,2);
    for(auto _v:res)
    {
        cout<<"\n";
        for(auto v:_v)
        cout<<v<<',';
    }
}
