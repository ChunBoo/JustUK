//dp for count1 in a integer
#include<iostream>
#include<map>
#include<vector>

int dpForCount1(int n,std::map<int,int>& dp)  //bottom 2 top 
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    std::map<int,int>::iterator it=dp.find(n);
    if(it!=dp.end())
        return dp[n];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i)
    {
        dp[i]=dp[i&(i-1)]+1;
    }
    return dp[n];
}

int getCountOf1(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    int ans=0;

    while(n>0)
    {
        ans+=1;
        n&=(n-1);
    }
    return ans;
}

int getCountOf12(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        n>>=1;
    }
    return ans;
}


int main()
{
    int val=15;
        // std::vector<int> dp(val+1);
    int cnt=getCountOf12(val);
    std::cout<<val<<" has: "<<cnt<<"x one.\n";
    // std::map<int,int> dp{};

    // int res=dpForCount1(val,dp);
    // // std::cout<<res<<'\n';
    //     //output the dp
    // std::map<int,int>::iterator it=dp.begin();
    // for(;it!=dp.end();++it)
    //     std::cout<<it->first<<"-->"<<it->second<<'\n';
    return 0;
}