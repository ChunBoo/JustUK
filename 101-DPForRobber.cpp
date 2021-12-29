//dp 

#include<iostream>
#include<vector>
#include<map>

int dfTop2Down(const std::vector<int>& vals,int n,std::map<int,int>& dp)
{
    int sz=vals.size();

    if(n<0||n>sz)  // this condition should be satisfied,or it will be dead-loop
        return 0;

    std::map<int,int>::iterator it=dp.find(n);
    
    if(it!=dp.end())
        return dp[n];
    
    int temp=std::max(dfTop2Down(vals,n-2,dp)+vals[n],dfTop2Down(vals,n-1,dp));
    dp[n]=temp;
    return dp[n];
}


int dfBottom2Top(const std::vector<int>& vals)
{
    int sz=vals.size();
    if(sz==0)
        return 0;
    if(sz==1)
        return vals[0];
    std::map<int,int> dp{};
    dp[0]=vals[0];
    dp[1]=std::max(vals[0],vals[1]);
    for(int i=2;i<sz;++i)
    {
        dp[i]=std::max(dp[i-2]+vals[i],dp[i-1]);
    }

    return dp[sz-1];
}




int main()
{
    std::vector<int> val{1,12,10};
    std::map<int,int> nb{};
    int result=dfTop2Down(val,3,nb);
    // int result=dfBottom2Top(val);
    // int result=getMax(val,3);
    std::cout<<"Result is: "<<result<<'\n';

    return 0;
}