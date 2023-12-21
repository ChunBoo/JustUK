/**
 * Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1)is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

Example 1:


Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: 
The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: 
The cell (2, 2) is as far as possible from all the land with distance 4.
Note:

1 <= grid.length == grid[0].length <= 100
grid[i][j] is 0 or 1
Solution: BFS
Put all land cells into a queue as source nodes and BFS for water cells, the last expanded one will be the farthest.

Time compleixty: O(n^2)
Space complexity: O(n^2)
*/


class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    int ans = -1;
    queue<int> q; // y*100 + x
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1) q.push(i * 100 + j);
    vector<int> dirs{0, -1, 0, 1, 0};
    int steps = 0;
    while (q.size()) {
      int size = q.size();
      while (size--) {
        auto p = q.front(); q.pop();
        int x = p % 100;
        int y = p / 100;
        if (grid[y][x] == 2)
          ans = max(ans, steps);
        for (int i = 0; i < 4; ++i) {
          int tx = x + dirs[i];
          int ty = y + dirs[i + 1];
          if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0) continue;
          grid[ty][tx] = 2;
          q.push(ty * 100 + tx);
        }
      }
      ++steps;
    }
    return ans;
  }
};