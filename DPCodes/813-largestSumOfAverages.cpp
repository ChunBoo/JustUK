/**
 * You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in nums, and that the score is not necessarily an integer.

Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.

Example 1:

Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

 * 
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) {
        const int n=nums.size();
        vector<double> sum(n+1);
        for(int i=1;i<=n;++i)   //here the i must from 1
            sum[i]=sum[i-1]+nums[i-1];

        vector<vector<double>> dp(n+1,vector<double>(K+1));

        for(int i=1;i<=n;++i)   
            dp[i][1]=sum[i]/i;
        
        for(int i=1;i<=n;++i){
            for(int k=2;k<=K;++k){
                for(int j=1;j<i;++j)  //here the j must from 1
                    dp[i][k]=max(dp[i][k],dp[j][k-1]+(sum[i]-sum[j])/(i-j));
            }
        }
        return dp[n][K];
    }
};

int main()
{
    vector<int> nums{9,1,2,3,9};
    int k = 3;
    cout<<Solution().largestSumOfAverages(nums,k);
}