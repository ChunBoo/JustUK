#include<iostream>

float sqrtWithFloat(int n,int a,float GAP=1e-5)
{
    if(n<=0)
        return 0;
    float b=n-a*a;
    float x=a+b/a;
    float t=x;
    while((n-x*x)>GAP)
    {
        x=a+b/t;
        t=x;
    }
    return x;
}

int main()
{
    int n=150;
    int a=12;
    float ret=sqrtWithFloat(n,a);
    std::cout<<ret<<'\n';

    return 0;
}