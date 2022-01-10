//given a number n,get the least count of perfect number
//e.g. 6=4+1+1
#include<iostream>
#include<vector>
#include<map>
int f(int n) // top2bottom
{

    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    int i=1;
    int ans=0;
    while(i*i<=n)
    {
        ans+=std::min(f(n),f(n-i*i)+1);
        ++i;
    }
    return ans;
}

int f2(int n)
{
    if(n<=0)
        return 0;
    std::vector<int> dp(n);

    for(int i=1;i*i<=n;++i)
    {
        int j=1;
        while(j*j<=n)
        {
            dp[i]=std::min(f2(i),f2(i-j*j)+1);
        }
    }
    for(auto i:dp)
        std::cout<<i<<'\n';
    return 0;
}

int main()
{
    int val=6;
    int res=f2(val);
    std::cout<<res<<'\n';
    return 0;
}
