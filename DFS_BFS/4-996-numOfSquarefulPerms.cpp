/**
 * Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

Example 1:

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: [2,2,2]
Output: 1
Note:

1 <= A.length <= 12
0 <= A[i] <= 1e9
Solution1: DFS
Try all permutations with pruning.

Time complexity: O(n!)
Space complexity: O(n)
*/


class Solution {
public:
  int numSquarefulPerms(vector<int>& A) {
    std::sort(begin(A), end(A));
    vector<int> cur;
    vector<int> used(A.size());
    int ans = 0;
    dfs(A, cur, used, ans);
    return ans;
  }
private:
  bool squareful(int x, int y) {
    int s = sqrt(x + y);
    return s * s == x + y;
  }
  
  void dfs(const vector<int>& A, vector<int>& cur, vector<int>& used, int& ans) {    
    if (cur.size() == A.size()) {
      ++ans;
      return;
    }
    for (int i = 0; i < A.size(); ++i) {
      if (used[i]) continue;
      // Avoid duplications.
      if (i > 0 && !used[i - 1] && A[i] == A[i - 1]) continue; 
      // Prune invalid solutions.
      if (!cur.empty() && !squareful(cur.back(), A[i])) continue;
      
      cur.push_back(A[i]);
      used[i] = 1;
      dfs(A, cur, used, ans);
      used[i] = 0;
      cur.pop_back();
    }
  }
};