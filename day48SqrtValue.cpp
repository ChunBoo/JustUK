//using bs to compute the sqrt(x)
#include<iostream>
#include<cmath>
float mySqrt(int x)
{
    if(x<0)
    {
        std::cout<<"X value is error,should be positive.\n";
        return 0;
    }
    int lo=0,hi=0;
    if(x<1)
        hi=1;
    else
        hi=x;
    float mid=(lo+hi)/2.0;
    float cur=mid*mid;
    while(std::abs(cur-x)>1e-5)
    {
        mid=(lo+hi)/2;
        cur=mid*mid;
        if(cur<=x)
            lo=mid;
        else
            hi=mid;

    }
    return mid;
}

int main()
{

    int x=3;
    float retValue=mySqrt(x);
    std::cout<<"result: "<<retValue<<'\n';
    return 0;
}