/**
Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Examples:  
Input: arr[] = {2, 0, 2}
Output: 2
Explanation: The structure is like below.
We can trap 2 units of water in the middle gap.
*/


#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        /*brute force*/
        // int n=height.size();
        // if(n==0)
        //     return 0;
        // int ans=0;

        // auto begin=cbegin(height);
        // auto end=cend(height);

        // for(int i=0;i<n;++i)
        // {
        //     int l=*max_element(begin,begin+i+1);
        //     int r=*max_element(begin+i,end);
        //     ans+=min(l,r)-height[i];
        // }
        // return ans;

        /* DP */
        int n=height.size();
        vector<int> l(n,0),r(n,0);

        //save all of the highest value for each index
        for(int i=0;i<n;++i)
        {
            l[i]=i==0?height[i]:max(l[i-1],height[i]);
        }
        for(int i=n-1;i>-1;--i)
            r[i]=i==n-1?height[i]:max(height[i],r[i+1]);
        int ans=0;
        for(int i=0;i<n;++i)
            ans+=min(l[i],r[i])-height[i];
        
        return ans;
    }
};

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<Solution().trap(arr);
}