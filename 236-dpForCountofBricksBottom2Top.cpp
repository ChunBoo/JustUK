//bottom 2 top dp method for the unlimited knapsack issue
#include<iostream>
#include<vector>
#include<cmath>
using DT=std::vector<int>;

int getCount(const DT& bricks,int width,int height)
{
    if(width<=0||height<=0||bricks.empty())
        return 0;

    int ans=0;

    //we should create one vector to store bottom values
    std::vector<int> dp(width+1,0);
    dp[0]=1;
    for(int w=0;w<width+1;++w)
    {
        for(auto b:bricks)
        {
            if(w>=b)
            {
                dp[w]+=dp[w-b];
            }
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
}
*/
int main()
{
    std::vector<int> bricks{3,3};
    std::cout<<getCount(bricks,5,6);
    return 0;
}