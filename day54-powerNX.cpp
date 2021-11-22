//O(logN)

#include<iostream>

long pow(int x,int n)
{
    if(n==0||x==1)
        return 1;
    if(x==0)
        return 0;
    if(n<0)
    {
        x=1.0/x;
        n=-n;
    }
    //recursion method
    // if(n&1)
    //     return x*pow(x,n-1);
    // return pow(x,n/2)*pow(x,n/2);

    //iterator method
    long ans=1;
    while(n>=1)
    {
        if(n&1)
        {
            ans*=x;
        }
        x*=x;
        n>>=1;
    }
    return ans;
}

int main()
{
    long ret=pow(2,10);
    std::cout<<"Result: "<<ret<<'\n';
    return 0;
}