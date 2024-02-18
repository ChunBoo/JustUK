/**
 * @file 4-719-smallestDistancePair.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * @brief Given an integer array, return the k-th smallest distance among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.

Example 1:
Input:
nums = [1,3,1]
k = 1
Output: 0 
Explanation:
Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Note:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        const int N=nums.back();
        vector<int> cnt(N+1,0);

        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j)
                ++cnt[nums[j]-nums[i]];
        }

        for(int i=0;i<=N;++i){
            k-=cnt[i];
            if(k<=0)
                return i;
        }
        return 0;
    }
};