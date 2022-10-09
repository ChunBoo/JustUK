//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
#include<string>
#include<iostream>
#include<vector>

using STR=std::string;
using VEC=std::vector<int>;

void PrintPalindrome(const STR& s,int start,int e)
{
    for(int i=start;i<=e;++i)
        std::cout<<s[i];
}

void longestPalindrome(const STR& s)
{
    int n=s.size();
    if((n==0)||(n==1))
        return ;
    std::vector<std::vector<int>> dp(n,std::vector<int>(n,0));
    for(int i=0;i<n;++i)
        dp[i][i]=1;
    int start=0, maxLength=1;
    for(int i=0;i<n-1;++i)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=true;
            start=i;
            maxLength=2;
        }
    }
    //check for the lengths greater than 2.
    //k is the length of substring.
    for(int k=3;k<=n;++k)
    {
        for(int i=0;i<n-k+1;++i)
        {
            int j=i+k-1;
            if(dp[i+1][j-1]&&s[i]==s[j])
            {
                dp[i][j]=1;
                if(k>maxLength)
                {
                    start=i;
                    maxLength=k;
                }
            }
        }
    }
    PrintPalindrome(s,start,maxLength+start-1); 
}

int main()
{
    STR s{"forgeeksskeegfor"};
    longestPalindrome(s);
    return 0;
}