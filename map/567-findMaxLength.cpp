/**
 * Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int preSum=0,ans=0;
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();++i){
            preSum+=nums[i]?1:-1;
            if(preSum==0)
                ans=i+1;
            else if(pos.count(preSum))
                ans=max(ans,i-pos[preSum]);
            else
                pos[preSum]=i;
        }
        return ans;
    }
};