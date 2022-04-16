//bottom 2 top 至底向上的动态规划算法求砌砖头数(无限背包变种)
#include<iostream>
#include<vector>
#include<cmath>


int f(std::vector<int>& bricks,int width)
{
    if(width<0)
        return 0;
    if(width==0)
        return 1;
    int ans=0;
    for(auto i:bricks)
        ans+=f(bricks,width-i);
    return ans;
}

int getCountT2B(std::vector<int>& bricks,int height,int width)
{
    int ans=f(bricks,width);
    return std::pow(ans,height);
}



int getCount(std::vector<int>& bricks,int height,int width)  //bottom 2 top
{
    int ans=0;
    if(bricks.empty())
        return ans;

    //needs a vector to record all of the bottom values
    std::vector<int> dp(width+1,0);
    dp[0]=1;
    for(int i=0;i<width+1;++i)
    {
        for(auto j:bricks)
        {
            if(i>=j)
                dp[i]+=dp[i-j];
        }
    }
    return std::pow(dp[width],height);
}
















/*
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
}*/

int main()
{
    std::vector<int> bricks{2,3};
    std::cout<<getCountT2B(bricks,6,5);
    return 0;
}