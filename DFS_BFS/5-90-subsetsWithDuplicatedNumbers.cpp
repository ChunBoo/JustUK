/**
 * subsetsWithDup
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

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
<strong>Input:</strong> [1,2,2]
<strong>Output:</strong>
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Solution: DFS

The key to this problem is how to remove/avoid duplicates efficiently.

For the same depth, among the same numbers, only the first number can be used.

Time complexity: O(2^n * n)
Space complexity: O(n)
*/


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
22
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    const int n = nums.size();
    sort(begin(nums), end(nums));
    vector<vector<int>> ans;
    vector<int> cur;
    function<void(int)> dfs = [&](int s) {
      ans.push_back(cur);
      if (cur.size() == n)
        return;      
      for (int i = s; i < n; ++i) {
        if (i > s && nums[i] == nums[i - 1]) continue;
        cur.push_back(nums[i]);
        dfs(i + 1);
        cur.pop_back();
      }
    };
    dfs(0);
    return ans;
  }
};