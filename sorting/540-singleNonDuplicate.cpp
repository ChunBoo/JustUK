/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution {
public:
    void counter(unordered_map<int,int>& m,vector<int>& nums)
    {
        for(auto i:nums)
            m[i]+=1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int _n=nums.size();
        if(_n==1)
            return nums[0];
        int l=0,r=_n;
        while(l<r)
        {
            const int m=l+(r-l)/2;
            const int n=m^1;
            if(nums[m]==nums[n])
                l=m+1;
            else
                r=m;
        }
        return nums[l];
    }
};