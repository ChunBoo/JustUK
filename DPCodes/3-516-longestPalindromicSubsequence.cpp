

#include<vector>
#include<string>
#include<iostream>
#include<functional>
#include<cstring>
using namespace std;


int longestPalindromeSubstring(string s){
    int n=s.size();
    // int dp[n][n];
    // std::memset(dp, -1,sizeof(dp));  //can not be used here?
    vector<vector<int>> dp(n,vector<int>(n,-1));
    function<int(int,int)> dfs=[&](int start,int end)->int{
        if(start>end)
            return 0;
        if(start==end)
            return 1;
        int &res=dp[start][end];
        if(res>0)
            return res;
        if(s[start]==s[end])
            return res=dfs(start+1,end-1)+2;
        else
            return res=max(dfs(start+1,end),dfs(start,end-1));
    };
    return dfs(0,n-1);
}


int main(){
    cout<<longestPalindromeSubstring("bbbab");
}