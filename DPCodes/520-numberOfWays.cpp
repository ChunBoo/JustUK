#include<iostream>
#include<cmath>
using std::cout;

int dfoo(int s,int e,int k)
{
    int d=std::abs(e-s);
    if(d>k)
        return 0;
    if((d&1)!=(k&1))
        return 0;
    
    if(k==0)
    {
        if(d==0)
            return 1;
        else
            return 0;
    }
    return dfoo(s-1,e,k-1)+dfoo(s+1,e,k-1);
}

int numberOfWays(int s,int e,int k)
{
    return dfoo(s,e,k);
}

int main()
{
    cout<<numberOfWays(1,2,3);
}