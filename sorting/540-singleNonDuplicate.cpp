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



// time complexity is O(logN),means we should use binary search method
#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;

class Solution {
public:

    int singleNonDuplicate(VEC& nums) {
        int l=0,r=nums.size();
        while(l<r)
        {
            cout<<"\nl= "<<l<<","<<"r= "<<r<<'\n';
            const int m=l+(r-l)/2;
            const int n=(m%2)==0?m+1:m-1;  //const int n=m^1;
            cout<<"m= "<<m<<","<<"n= "<<n<<'\n';

            if(nums[m]==nums[n])
            {
                l=m+1;
            }
            else
                r=m;
        }
        return nums[l];
    }
};

int main()
{
    VEC nums{1,1,2,3,3,4,4,8,8};
    cout<<Solution().singleNonDuplicate(nums);
}