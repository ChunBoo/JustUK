#include<iostream>

double f(int n,int a)  //recursion
{
    if(n==0)
        return a/(a+1);
    return a/(1+f(n-1,a));
}

double g(int n,int a)  //iteration
{
    double ans=0;
    for(int i=0;i<n;++i)
    {
        ans=a/(a+ans);
    }
    return ans;
}

int main()
{
    std::cout<<f(50,1)<<'\n';
    std::cout<<g(50,1)<<'\n';
}