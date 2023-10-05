
/*You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

 

Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.
Example 2:

Input: nums = [7,-9,15,-2], goal = -5
Output: 1
Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
Example 3:

Input: nums = [1,2,3], goal = -7
Output: 7
 

Constraints:

1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109*/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> t1{0},t2{0};
        t1.reserve(1<<(n/2+1));
        t2.reserve(1<<(n/2+1));

        int ans=abs(goal);

        for(int i=0;i<n/2;++i)
            //for(int j=0;j<int(t1.size());++j)
            for(int j=t1.size()-1;j>-1;--j)  //here, we should start from t1.size()-1
                t1.push_back(t1[j]+nums[i]);
        
        for(int i=n/2;i<n;++i)
            for(int j=t2.size()-1;j>=0;--j)
                t2.push_back(t2[j]+nums[i]);

        set<int> s2(begin(t2),end(t2));
        for(int x:unordered_set<int>(begin(t1),end(t1))){
            auto it=s2.lower_bound(goal-x);
            if(it!=end(s2))
                ans=min(ans,abs(goal-x-*it));
            if(it!=begin(s2))
                ans=min(ans,abs(goal-x-*prev(it)));
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{7,-9,15,-2};
    int goal = -5;
    cout<<Solution().minAbsDifference(nums,goal);
}