//bottom 2 top 至底向上的动态规划算法求砌砖头数(无限背包变种)
#include<iostream>
#include<vector>
#include<cmath>


int f(std::vector<int>& bricks,int n)
{
    if(n<=1)
        return n;
    std::vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<=n;++i)
    {
        for(auto j:bricks)
        {
            if(i>=j)
                dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

int counts(std::vector<int>& bricks,int h,int w)
{
    return std::pow(f(bricks,w),h);
}

int main()
{
    std::vector<int> bricks{2,3};
    std::cout<<counts(bricks,6,5);
    return 0;
}