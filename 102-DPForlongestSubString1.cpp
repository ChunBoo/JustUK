//dp for longest sub string

#include<string>
#include<iostream>
#include<vector>
int dpForLongSubString(const std::string& str)  //top2bottom
{
    if(str.empty())
        return 0;

    int sz=str.size();

    if(sz==1)
        return 1;

    std::vector<std::vector<int>> dp(sz,std::vector<int>(sz,0));

    for(int i=sz-1;i>=0;--i)
    {
        dp[i][i]=1;
        for(int j=i+1;j<sz;++j)
        {
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][sz-1];
}

int main()
{
    std::string s{"abbcbbeb"};
    int res=dpForLongSubString(s);
    std::cout<<res<<"\n";
    return 0;
}