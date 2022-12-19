#include<vector>
#include<iostream>

using VEC=std::vector<int>;

int bottom2Top(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    VEC dp(n+1,0);
    dp[1]=1;
    for(int i=2;i<=n;++i)
        dp[i]=dp[i-1]+dp[i-2];

    for(auto &v:dp)
        std::cout<<v<<'\n';    
}
/*
int f(int n)
{

}
*/
int top2Down(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int res=top2Down(n-2)+top2Down(n-1);
    std::cout<<res<<'\n';
    return res;   //here should return the result
}
int main()
{
    // bottom2Top(10);
    top2Down(10);
}