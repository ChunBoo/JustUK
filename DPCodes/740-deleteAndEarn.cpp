// Author: Huahua
// Runtime: 6 ms
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        const auto range = std::minmax_element(nums.begin(), nums.end());
        const int l = *(range.first);
        const int r = *(range.second);        
        vector<int> points(r - l + 1, 0);
        for (const int num : nums)
            points[num - l] += num;
        return rob(points);
    }
private:
    // Robber
    int rob(const vector<int>& nums) {
        int dp2 = 0;
        int dp1 = 0;
        for (size_t i = 0; i < nums.size() ; ++i) {
            int dp = std::max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int n=nums.size();
        if(n<=1)
            return nums[0];
        
        int r=*max_element(begin(nums),end(nums));
        vector<int> points(r+1,0);

        for(int i:nums)
            points[i]+=i;
        
        return rob(points);
    }
private:
    int rob(const vector<int>& nums){
        int dp1=0,dp2=0;
        for(int i=0;i<nums.size();++i)
        {
            int dp=max(dp1,dp2+nums[i]);
            dp2=dp1;
            dp1=dp;
        }
        return dp1;
    }
};

int main()
{
    vector<int> nums{3,4,2};
    cout<<Solution().deleteAndEarn(nums);
}