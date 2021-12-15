//haming distance of two integers

#include<iostream>

int hamingDistance(int m,int n)
{
    int t=m^n;
    int ans=0;

    // while(t)
    // {
    //     ans++;
    //     t&=(t-1);
    // }
    while(t)
    {
        ans+=(t&1);
        t>>=1;
    }
    return ans;
}

int main()
{
    int m=15,n=15;
    int d=hamingDistance(m,n);
    std::cout<<"Distance of m and n is: "<<d<<'\n';

    return 0;
}