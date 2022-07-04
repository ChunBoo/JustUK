//https://helloacm.com/teaching-kids-programming-top-down-and-bottom-up-dynamic-programming-algorithm-to-type-n-letters-on-a-2-keys-keyboard/
//f(n)=min(f(n)+n/i)  ,i is the factor of n
#include<iostream>
#include<vector>
#include<cmath>
int minStepsTop2Down(int n)
{
    if(n==1)
        return 0;

    int ans=n;

    for(int i=2;i<n/2+1;++i)
    {
        if((n%i)==0)
            ans=std::min(ans,minStepsTop2Down(i)+n/i);
    }
    return ans;
}

int minStepsDown2Top(int n)
{
    if(n==1)
        return 0;
    std::vector<int> dp(n+1,1);
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<i/2+1;++j)
        {
            if((i%j)==0)
                dp[i]=std::min(dp[i],dp[j]+i/j);
        }
    }
    return dp[n];
}

int main()
{
    // std::cout<<minSteps(99);
    std::cout<<minStepsDown2Top(3);
    return 0;
}