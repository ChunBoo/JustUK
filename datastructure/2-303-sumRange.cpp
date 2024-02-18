/**
 * Problem
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:

You may assume that the array does not change.
There are many calls to sumRange function.
Solution: Prefix sum
sums[i] = nums[0] + nums[1] + … + nums[i]

sumRange(i, j) = sums[j] – sums[i – 1]

Time complexity: pre-compute: O(n), query: O(1)

Space complexity: O(n)

*/

//refer to 221
class NumArray {
public:
  NumArray(vector<int> nums): sums_(nums) {      
    if (nums.empty()) return;            
    for (int i = 1; i < nums.size();++i)
      sums_[i] += sums_[i - 1];
  }
 
  int sumRange(int i, int j) {
    if (i == 0) return sums_[j];
    return sums_[j] - sums_[i-1];
  }
private:    
  vector<int> sums_;
};
