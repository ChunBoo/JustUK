#include<iostream>
#include<vector>
#include<numeric>
using std::cout;
using VEC=std::vector<int>;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n=nums.size();
        const int sum=std::accumulate(begin(nums),end(nums),0);
        if(sum<abs(target))
            return 0;
        vector<vector<int>> dp(n+1,vector<int>(2*sum+1,0));
        int offset=sum;
        dp[0][offset]=1;

        for(int i=0;i<n;i++){
            for(int j=nums[i];j<2*sum+1-nums[i];j++){
                if(dp[i][j]){
                    dp[i+1][j-nums[i]]+=dp[i][j];
                    dp[i+1][j+nums[i]]+=dp[i][j];
                }
            }
        }
        return dp.back()[target+offset];
    }
};


int foo(const VEC& nums,int idx,int t)
{
    // if(t<0)
        // return 0;
    if(idx<0)
    {
        if(t==0) return 1;
        return 0;
    }
    if(t<nums[idx])
        return foo(nums,idx-1,t);
    return foo(nums,idx-1,t)+foo(nums,idx-1,t-nums[idx]);
}

int test(const VEC& nums,int t)
{
    int n=nums.size();
    int sum=std::accumulate(nums.begin(),nums.end(),0);
    t+=sum;
    if(t<0 || t&1)
        return 0;
    t/=2;
    // int ans=0;
    return foo(nums,n-1,t); 
    // return ans;
}
int main()
{
    VEC nums{1,1,1,1,1};
    int target = 3;
    cout<<(test(nums,target));
}