//given a unsorted array, return the longest increasing subsequence

#include<iostream>
#include<vector>

using DT=std::vector<int>;

int bisect_left(const DT& a,int val)
{
    if(a.empty())
        return 0;
    int sz=a.size();
    for(int i=0;i<sz;++i)
    {
        if(a[i]>=val)
            return i;
    }
    return sz;
}

int longestIncreasingSubsequenceDP(const DT& arr)
{
    int len=arr.size();
    if(!len)
        return 0;
    DT dp(len,1);
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=std::max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    for(auto &v:dp)
    {
        if(v>ans)
            ans=v;
    }
    return ans;
}



int longestIncreasingSubsequenceGreedy(const DT& arr)
{
    int sz=arr.size();
    if(!sz)
        return 0;
    DT lis;
    for(auto &v:arr)
    {
        int x=bisect_left(lis,v);
        if(x==lis.size())
            lis.push_back(v);
        else
            lis[x]=v;
    }
    return lis.size();
}

int main()
{
    DT a{3,2,4,1,7,6,10};
    int res=longestIncreasingSubsequenceDP(a);
    int res2=longestIncreasingSubsequenceGreedy(a);
    std::cout<<res<<'\n';
    std::cout<<res2<<'\n';
    return 0;
}