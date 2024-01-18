/**
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    int n = num.size();
    int d = INT_MAX;
    int ans = target;
    sort(num.begin(), num.end());
      
    for (int i = 0; i < n - 2; i++) {
        int s = i + 1, t = n - 1;
        while (s < t) {
          int sum = num[i] + num[s] + num[t];
          if (sum == target)
              return target;            
 
          int diff = abs(sum - target);
          if (diff < d) {
            d = diff;
            ans = sum;
          }
 
          if (sum > target) --t;            
          else ++s;
        }
      }
 
      return ans;
  }
};