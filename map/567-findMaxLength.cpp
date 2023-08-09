/**
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int ans = 0;
      int preSum = 0;
      unordered_map<int, int> m{};
      for (int i = 0; i < int(nums.size()); ++i) {
        preSum += nums[i] ? 1 : -1;
        if (preSum == 0)
          ans = i+1; //why here is i+1,but not i?
        else if (m.count(preSum))
          ans = max(ans, i - m[preSum]);
        else
          m[preSum] = i;
      }
        return ans;
    }
};

int main() {
  vector<int> nums{0, 0,1, 0,1, 0,1,1,0,0,1};
  cout << Solution().findMaxLength(nums);
}