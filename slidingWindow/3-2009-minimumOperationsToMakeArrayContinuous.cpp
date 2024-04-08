/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n=nums.size();
        if(n==1)
            return 0;

        std::sort(nums.begin(),nums.end());
        int m=unique(nums.begin(), nums.end())-nums.begin();
        int left=0, j=0,ans=n;
        for(int i=0;i<m;i++)
        {
            int right=nums[i]+n-1;
            while(j<m&&nums[j]<=right)
            {
                ans=min(ans,n-(j-i+1));
                j++;
            }
        }
        return ans;
    }
};