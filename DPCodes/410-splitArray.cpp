/**
 * Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
 * 
*/

class Solution {
    private:
    vector<vector<int>> m_mem;
    vector<int> m_sum;
    //min of largest sum of spliting nums[0]-nums[k] into m groups
    int splitArray(const vector<int>& nums,int k,int m)
    {
        if(m==1) return m_sum[k];
        if(m>k+1) return INT_MAX;  //k is the count of elements count
        if(m_mem[k][m]!=INT_MAX) return m_mem[k][m];
        int ans=INT_MAX;
        for(int i=0;i<k;++i)
            ans=min(ans,max(splitArray(nums,i,m-1),m_sum[k]-m_sum[i]));
        return m_mem[k][m]=ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        const int n=nums.size();
        m_sum=vector<int>(n);
        m_mem=vector<vector<int>>(n,vector<int>(k+1,INT_MAX));
        m_sum[0]=nums[0];
        for(int i=1;i<n;++i)
            m_sum[i]=m_sum[i-1]+nums[i];
        return splitArray(nums,n-1,k);
    }
};