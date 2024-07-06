/***
 * You are given a 
binary array
 nums.

We call a 
subarray
 alternating if no two adjacent elements in the subarray have the same value.

Return the number of alternating subarrays in nums.

 

Example 1:

Input: nums = [0,1,1,1]

Output: 5

Explanation:

The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

Example 2:

Input: nums = [1,0,1,0]

Output: 10

Explanation:

Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 */

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        const int n=nums.size();
        
        long long ans=1,cur=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                cur+=1;
                 }
            else
            {
                cur=1;
            }
        ans+=cur;
        }
        return ans;
        
        
        // vector<int> dp(n,0);
        // dp[0]=1;

        // for(int i=1;i<n;i++){
        //     dp[i]=nums[i]==nums[i-1]?1:dp[i-1]+1;
        // }
        // long long ans=0;
        // for(auto v:dp){
        //     ans+=v;
        // }
        // return ans;


    }
};