/**
 * Given an array A of strings, find any smallest string that contains each string in A as a substring.

We may assume that no string in A is substring of another string in A.

Example 1:

Input: ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
Example 2:

Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
Note:

1 <= A.length <= 12
1 <= A[i].length <= 20

g[i][j] is the cost of appending word[j] after word[i], or weight of edge[i][j].

We would like find the shortest path to visit each node from 0 to n – 1 once and only once this is called the Travelling sells man’s problem which is NP-Complete.

We can solve it with DP that uses exponential time.

dp[s][i] := min distance to visit nodes (represented as a binary state s) once and only once and the path ends with node i.

e.g. dp[7][1] is the min distance to visit nodes (0, 1, 2) and ends with node 1, the possible paths could be (0, 2, 1), (2, 0, 1).

Time complexity: O(n^2 * 2^n)

Space complexity: O(n * 2^n)
*/

class Solution {
public:
  string shortestSuperstring(vector<string>& A) {        
    const int n = A.size();
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g[i][j] = A[j].length() - k;
      }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    
    for (int s = 1; s < (1 << n); ++s) {
      for (int j = 0; j < n; ++j) {
        if (!(s & (1 << j))) continue;
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            parent[s][j] = i;
          }
        }
      }
    }
    
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s) {
      int i = parent[s][j];
      if (i < 0) ans = A[j] + ans;
      else ans = A[j].substr(A[j].length() - g[i][j]) + ans;
      s &= ~(1 << j);
      j = i;
    }
    return ans;
  } 
};