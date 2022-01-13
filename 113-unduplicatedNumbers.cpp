//given a number likes 9,means 9-digits,output the total count of nonredundant numbers,
//means 22,33,44 excluded

#include<iostream>
#include<map>

//bottom 2 top

int getNonredundantNumbersCount(int n)
{
    if(n>10)
      return 0;
    
    std::map<int,int> dp;
    dp[0]=1;
    dp[1]=9;

    for(int i=2;i<=n;++i)
        dp[i]=dp[i-1]*(11-i);
    return dp[n];
}
//top2bottom
int getCountOfNonredundantNumbers(int n)
{
    if(n>10)
        return ;
    if(n==0)
        return 1;
    if(n==1)
        return 9;

    return getNonredundantNumbersCount(n-1)*(11-n);
}

int main()
{
    int n=3;
    int res=getCountOfNonredundantNumbers(n);
    std::cout<<res<<'\n';
    return 0;
}