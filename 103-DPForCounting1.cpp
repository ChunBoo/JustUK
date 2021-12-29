//dp for count1 in a integer
#include<iostream>
#include<map>
#include<vector>
int dpForCount1(int n,std::map<int,int>& dp)
{
    if(n<=0)
        return 0;
    
    if(n==1)
        return 1;

    dp[0]=0;
    dp[1]=1;
    int i=2;
    while(i<=n)
    {
        dp[i]=dp[i&(i-1)]+1; 
        i++;
    }

    return dp[n];
}

int main()
{
    int val=7;
        // std::vector<int> dp(val+1);
     std::map<int,int> dp{};

    int res=dpForCount1(val,dp);
    // std::cout<<res<<'\n';
        //output the dp
    std::map<int,int>::iterator it=dp.begin();
    for(;it!=dp.end();++it)
        std::cout<<it->first<<"-->"<<it->second<<'\n';
    return 0;
}