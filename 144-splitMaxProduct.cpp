#include<iostream>
#include<cmath>
#include<vector>  //for the nb

int greedyForSplitMaxProduct(int n)
{
    //used the mathematics method to reduce the loops
    if(n==1)
        return 0;
    if(n==2)
        return 1;   //1==1
    if(n==3)
        return 2;   //3==1+2
    int ans=1;
    while(n>4)
    {
        ans*=3;
        n-=3;
    }
    return ans*n;   // why we needs this step?? 
}

int b2tDPForSplitMaxProduct(int n) //bottom 2 top DP,we need the nb to save the previous values
{
    //
    std::vector<int> dp(n+1,1);
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<i;++j)
        {
            int temp=std::max(j*(i-j),j*dp[i-j]);
            dp[i]=std::max(temp,dp[i]);
        }
    }
    return dp[n];
}

int t2bDPForSplitMaxProduct(int n)
{
    int ans=0;
    if(n<=2)
        return 1;
    if(n==3)
        return 2;  //added above if-statements for speedup 
    for(int i=1;i<n+1;++i)
    {    
        int temp=std::max(i*(n-i),i*t2bDPForSplitMaxProduct(n-i));
        ans=std::max(ans,temp);
    }
    return ans;
}


int main()
{
    std::cout<<greedyForSplitMaxProduct(7)<<'\n';
    std::cout<<b2tDPForSplitMaxProduct(7)<<"\n";
    std::cout<<t2bDPForSplitMaxProduct(7)<<"\n";
    return 0;
}