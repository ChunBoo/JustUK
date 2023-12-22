/**
 * Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:

Input: [4,6,15,35]
Output: 4

For each number, union itself with all its factors.

E.g. 6, union(6,2), union(6,3)

Time complexity: O(Σsqrt(A[i]))
Space complexity: O(max(A))
*/

class DSU {
public:
  DSU(int n): p_(n) {
    for (int i = 0; i < n; ++i)
      p_[i] = i;
  }
  
  void Union(int x, int y) {
    p_[Find(x)] = p_[Find(y)];
  }
  
  int Find(int x) {
    if (p_[x] != x) p_[x] = Find(p_[x]);
    return p_[x];
  }
private:
  vector<int> p_;
};
 
class Solution {
public:
  int largestComponentSize(vector<int>& A) {    
    int n = *max_element(begin(A), end(A));
    DSU dsu(n + 1);
    for (int a : A) {
      int t = sqrt(a);
      for (int k = 2; k <= t; ++k)
        if (a % k == 0) {
          dsu.Union(a, k);
          dsu.Union(a, a / k);
        }
    }
    unordered_map<int, int> c;
    int ans = 1;
    for (int a : A)
      ans = max(ans, ++c[dsu.Find(a)]);    
    return ans;
  }
};