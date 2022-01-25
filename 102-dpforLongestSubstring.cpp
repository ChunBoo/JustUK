//dp for longest substring

#include<iostream>
#include<string>
#include<vector>
int longestSubString(const std::string& s,int from,int end)  //top2bottom
{
    if(from>end)
        return 0;
    if(from==end)
        return 1;

    if(s[from]==s[end])
        return longestSubString(s,from+1,end-1)+2;
    return std::max(longestSubString(s,from,end-1),longestSubString(s,from+1,end));
}

int getLongestSubString(const std::string& s)  //bottom2top
{
    int sz=s.size();
    if(sz==0)
        return 0;
    if(sz==1)
        return 1;
    
    std::vector<std::vector<int>> dp(sz,std::vector<int>(sz,0));

    for(int i=sz-1;i>=0;--i)
    {
        dp[i][i]=1;
        for(int j=i+1;j<sz;++j)
        {
            if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][sz-1];
}

int main()
{
    std::string s="abbcbbeb";
    int res=getLongestSubString(s);
    std::cout<<res<<'\n';
    return 0;
}