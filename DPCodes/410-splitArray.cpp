/**
 * Given an integer array nums and an integer k, 
 split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
 * 
*/
#include<vector>
#include<iostream>

using VEC=std::vector<int>;
// using MATRIX=std::vector<VEC>;
using std::cout;
using namespace std;

class Solution {

private:
    vector<vector<int>> m_mem;  //save the temp values
    vector<int> m_sum;  //save the sum until each index
    //min of largest sum of spliting nums[0]-nums[k] into m groups
    int splitArray(const vector<int>& nums,int k,int m)     //m is count of groups,k is the count of numbers
    {
        if(m>k+1) return INT_MAX;
        if(m==1) return m_sum[k];
        if(m_mem[k][m]!=INT_MAX) return m_mem[k][m];
        int ans=INT_MAX;
        for(int i=0;i<k;++i)
        {
            ans=min(ans,max(m_sum[k]-m_sum[i],splitArray(nums,i,m-1)));
        }
        return m_mem[k][m]=ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        size_t n=nums.size();
        m_sum=vector<int>(n,0);
        m_mem=vector<vector<int>>(n,vector<int>(k+1,INT_MAX));
        m_sum[0]=nums[0];
        for(size_t i=1;i<n;++i)
            m_sum[i]=m_sum[i-1]+nums[i];
        return splitArray(nums,n-1,k);
    }
};

int main()
{
    VEC nums{7,2,5,10,8};
    int k = 2;
    cout<<Solution().splitArray(nums,k);
}