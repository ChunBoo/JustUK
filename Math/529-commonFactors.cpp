#include<iostream>

using std::cout;

int gcd(int a,int b)
{
    while(b)
    {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}


int commonFactors(int a,int b)
{
    int x=gcd(a,b);
    int ans=1;
    for(int i=2;i<x+1;++i)
    {
        if(x%i==0)
            ans+=1;
    }
    return ans;
}

int main()
{
    int a=12,b=24;
    cout<<commonFactors(a,b);
}