//haming distance of two integers

#include<iostream>

int hamingDistance(int m,int n)
{
    int t=m^n;
    int ans=0;

    while(t)
    {
        ans+=1;  //ans+=(t&1); why can not work?
        t&=(t-1);
    }
    // while(t)
    // {
    //     ans+=1;
    //     t>>=1;
    // }
    return ans;
}

int main()
{
    int m=15,n=16;
    int d=hamingDistance(m,n);
    std::cout<<"Distance of m and n is: "<<d<<'\n';

    return 0;
}