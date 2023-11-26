/**
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

1
2
3
4
5
6
7
8
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
 
return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

Solution 1: Binary Search
Find the smallest x, such that there are k elements that are smaller or equal to x.

Time complexity: O(nlogn*log(max – min))

Space complexity: O(1)


*/
class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    long l = matrix[0][0];
    long r = matrix[n - 1][n - 1] + 1;
    while (l < r) {
      long m = l + (r - l) / 2;      
      int total = 0;
      int s = n;
      for (const auto& row : matrix)
        total += (s = distance(begin(row), upper_bound(begin(row), begin(row) + s, m)));
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
